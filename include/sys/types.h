#ifndef __SYS_TYPES_H__
#define __SYS_TYPES_H__
#include "stdint.h"

#define _POSIX_SSIZE_MAX 32767

#define not_defined int

typedef int blkcnt_t;
typedef int blksize_t;
#define clock_t not_defined // int or float

#define clockid_t not_defined
typedef int dev_t;
typedef unsigned int fsblkcnt_t;
typedef unsigned int fsfilcnt_t;
typedef int gid_t;
typedef int id_t;

typedef unsigned int ino_t;
#define key_t not_defined
typedef int mode_t;
typedef int nlink_t;
typedef int off_t; // signed
typedef int pid_t; // signed

typedef struct {
  int a;
} pthread_attr_t;

typedef struct {
  int a;
} pthread_barrier_t;

typedef struct {
  int a;
} pthread_barrierattr_t;

typedef struct {
  int a;
} pthread_cond_t;

typedef struct {
  int a;
} pthread_condattr_t;
typedef struct {
  int a;
} pthread_key_t;

typedef struct pthread_spinlock {
  volatile unsigned int locked_;
} pthread_spinlock_t;

typedef unsigned int pthread_t;

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
typedef struct {
  int a;
} pthread_once_t;

typedef struct {
  int a;
} pthread_rwlock_t;

typedef struct {
  int a;
} pthread_rwlockattr_t;

typedef unsigned int size_t;
typedef int ssize_t;
// suseconds_t
typedef int time_t;
// timer_t
// trace_attr_t
// trace_event_id_t
// trace_event_set_t
// trace_id_t
typedef int uid_t;

// // not int
// pthread_attr_t
// pthread_barrier_t
// pthread_barrierattr_t
// pthread_cond_t
// pthread_condattr_t
// pthread_key_t
// pthread_mutex_t
// pthread_mutexattr_t
// pthread_once_t
// pthread_rwlock_t
// pthread_rwlockattr_t
// pthread_spinlock_t
// pthread_t
// timer_t
// trace_attr_t
// trace_event_id_t
// trace_event_set_t
// trace_id_t

// mode_t shall be an integer type.
// dev_t shall be an integer type.
// nlink_t, uid_t, gid_t, and id_t shall be integer types.
// blkcnt_t and off_t shall be signed integer types.
// fsblkcnt_t, fsfilcnt_t, and ino_t shall be defined as unsigned integer types.
// size_t shall be an unsigned integer type.
// blksize_t, pid_t, and ssize_t shall be signed integer types.

// clock_t shall be an integer or real-floating type.
// time_t shall be an integer type.
// The type ssize_t shall be capable of storing values at least in the range
// [−1, {SSIZE_MAX}].

#endif /* __SYS_TYPES_H__ */