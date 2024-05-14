#include "errno.h"
#include "pthread.h"

// extern int errno;

int pthread_mutex_destroy(pthread_mutex_t *mutex) {
  // EBUSY
  // A request has detected an attempt to destroy the object referenced by mutex
  // while it was locked or referenced by another thread (for example, while
  // being used in a pthread_cond_wait() or pthread_cond_timedwait() function).
  // EINVAL
  // The value specified by mutex is not valid.

  if (!mutex) {
    return EINVAL;
  }

  pthread_spin_destroy(&mutex->guard_);
  mutex->locked_ = 0;
  // mutex->owner_;
  mutex->flags_ = 0;
  // waiting_threads_

  return 0;
}

int pthread_mutex_init(pthread_mutex_t *mutex,
                       const pthread_mutexattr_t *attrs) {
  // EAGAIN
  // The system lacked the necessary resources (other than memory) to
  // initialize another mutex.
  // EBUSY detected an attempt to re-initialize the
  // object referenced by mutex, a previously initialized, but not yet
  // destroyed, mutex.
  // EINVAL
  // The value specified by attr is not valid.
  // ENOMEM There is not enough memory to acquire a lock. This errno will only
  // occur
  // in the private path. EPERM The caller does not have the privilege to
  // perform the operation.

  pthread_spin_init(&mutex->guard_, 0);
  mutex->locked_ = 0;
  // mutex->owner_;
  mutex->flags_ = 0;
  // waiting_threads_

  return 0;
}

int pthread_mutex_lock(pthread_mutex_t *mutex) {
  // EAGAIN
  // The mutex could not be acquired because the maximum number of recursive
  // locks for mutex has been exceeded. This errno will only occur in the shared
  // path.
  // EDEADLK
  // The current thread already owns the mutex, and the mutex has
  // a kind attribute of __MUTEX_NONRECURSIVE.
  // EINVAL
  // The value specified by mutex is not valid.

  if (!mutex) {
    return EINVAL;
  }

  while (1) {
    while (1 == mutex->locked_) {
    }

    pthread_spin_lock(&mutex->guard_);
    if (1 == mutex->locked_) {
      pthread_spin_unlock(&mutex->guard_);
    } else { // 0 == mutex->locked_
      mutex->locked_ = 1;
      // mutex->owner_;
      // mutex->flags_ = 0;
      // waiting_threads_
      pthread_spin_unlock(&mutex->guard_);
      return 0;
    }
  }
}

int pthread_mutex_trylock(pthread_mutex_t *mutex) {
  // EAGAIN
  // The mutex could not be acquired because the maximum number of recursive
  // locks for mutex has been exceeded. This errno will only occur in the shared
  // path.
  // EBUSY
  // mutex could not be acquired because it was already locked.
  // EINVAL
  // The value specified by mutex is not valid.

  if (!mutex) {
    return EINVAL;
  }

  if (mutex->locked_ == 1) {
    return EBUSY;
  }

  // TODO: pthread_spin_lock/pthread_spin_trylock which is correct
  //  if (0 != pthread_spin_trylock(&mutex->guard_)){
  //    return EBUSY;
  //  }
  pthread_spin_lock(&mutex->guard_);
  if (mutex->locked_ == 1) {
    return EBUSY;
  } else {
    mutex->locked_ = 1;
  }

  // mutex->owner_;
  // mutex->flags_ = 0;
  // waiting_threads_
  pthread_spin_unlock(&mutex->guard_);

  return 0;
}

int pthread_mutex_unlock(pthread_mutex_t *mutex) {
  // EINVAL
  // The value specified by mutex is not valid.
  // EPERM
  // The current thread does not own the mutex.

  if (!mutex) {
    return EINVAL;
  }

  pthread_spin_lock(&mutex->guard_);

  mutex->locked_ = 0;

  // mutex->owner_;
  // mutex->flags_ = 0;
  // waiting_threads_
  pthread_spin_unlock(&mutex->guard_);

  return 0;
}
