#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "pthread.h"
#include "spinlock.h"
#include "stdint.h"

// https://osleak.sourceforge.net/structUSER_1_1pthread__mutex__t.html

typedef struct {
  pthread_spinlock_t guard_;
  int locked_;
  pthread_t owner_;
  uint32_t flags_;
  // struct list_head waiting_threads_;
} pthread_mutex_t;

typedef struct {
  int type_;
} pthread_mutexattr_t;

int pthread_mutex_init(pthread_mutex_t *mutex,
                       const pthread_mutexattr_t *attrs);

int pthread_mutex_destroy(pthread_mutex_t *mutex);

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_trylock(pthread_mutex_t *mutex);

int pthread_mutex_unlock(pthread_mutex_t *mutex);

#endif /* __MUTEX_H__ */
