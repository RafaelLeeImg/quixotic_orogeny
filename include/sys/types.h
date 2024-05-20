#ifndef __SYS_TYPES_H__
#define __SYS_TYPES_H__
#include "sched.h"
#include "stdint.h"

#define _POSIX_SSIZE_MAX 32767

typedef unsigned int size_t;
typedef int ssize_t;

typedef float not_defined;

typedef int blkcnt_t;
typedef int blksize_t;
typedef int clock_t;

#define clockid_t not_defined
// POSIX Headers <time.h>
// CLOCKS_PER_SEC A number used to convert the value returned by the clock( )
// function into seconds. The value shall be an expression with type clock_t.
// The value of CLOCKS_PER_SEC shall be 1 million on XSI-conformant systems.
// However, it may be variable on other systems, and it should not be assumed
// that CLOCKS_PER_SEC is a compile-time constant.

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

// not defined by POSIX
typedef enum {
  PROCESS_STATE_CREATED = 0,
  PROCESS_STATE_READY,
  PROCESS_STATE_RUNNING,
  PROCESS_STATE_BLOCKED,
  PROCESS_STATE_WAITING,
  PROCESS_STATE_SWAPPED_OUT_AND_WAITING,
  PROCESS_STATE_SWAPPED_OUT_AND_BLOCKED,
  PROCESS_STATE_end = 0x7FFFFFFF // make this enum 4 byte aligned
} process_state_t;

enum {
  REGISTER_R1 = 1,
  REGISTER_R2 = 2,
  REGISTER_R3 = 3,
  REGISTER_R4 = 4,
  REGISTER_R5 = 5,
  REGISTER_R6 = 6,
  REGISTER_R7 = 7,
  REGISTER_R8 = 8,
  REGISTER_R9 = 9,
  REGISTER_R10 = 10,
  REGISTER_R11 = 11,
  REGISTER_R12 = 12,
  REGISTER_SP = 13,
  REGISTER_LR = 14,
  REGISTER_PC = 15
};

// not defined by POSIX
typedef struct {
  unsigned int low_limit;
  unsigned int high_limit;
} process_memory_t;

// defined according to POSIX Headers <sched.h>
typedef struct {
  // **** defined by POSIX
  int detachstate;
  size_t guardsize;
  int inheritsched;
  struct sched_param schedparam;
  int schedpolicy;
  int scope;
  void *stackaddr;
  size_t stacksize;

  // **** not defined by POSIX
  unsigned int pid;
  // R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, SP, LR, PC, XPSR
  unsigned int registers[17];
  int priority;
  // process_memory_t memory_info; // other than stack
  int ppid; // parent_pid
  int signal_handlers;
  int statistics;
  process_state_t state;
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

// suseconds_t

// define time_t here will cause recursive inclusion, move time_t to <time.h>
// typedef int time_t;

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