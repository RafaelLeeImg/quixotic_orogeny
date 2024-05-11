#ifndef __SPINLOCK_H__
#define __SPINLOCK_H__
#include "stdint.h"

void __dmb(void);
uint32_t __ldrex(volatile uint32_t *addr);
uint32_t __strex(uint32_t val, volatile uint32_t *addr);
void __clrex(void);

typedef struct pthread_spinlock {
  volatile unsigned int locked_;
} pthread_spinlock_t;

// POSIX, IEEE Std 1003.1-2017
int pthread_spin_destroy(pthread_spinlock_t *lock);
// POSIX, IEEE Std 1003.1-2017
int pthread_spin_init(pthread_spinlock_t *lock, int pshared);
// POSIX, IEEE Std 1003.1-2017
int pthread_spin_lock(pthread_spinlock_t *lock);
// POSIX, IEEE Std 1003.1-2017
int pthread_spin_trylock(pthread_spinlock_t *lock);
// POSIX, IEEE Std 1003.1-2017
int pthread_spin_unlock(pthread_spinlock_t *lock);

#endif /* __SPINLOCK_H__ */
