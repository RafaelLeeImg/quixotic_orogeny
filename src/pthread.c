#include "pthread.h"
#include "errno.h"

int pthread_attr_init(pthread_attr_t *attr) {
  pthread_attr_setdetachstate(attr, 0);
  pthread_attr_setguardsize(attr, 0);
  pthread_attr_setinheritsched(attr, 0);
  struct sched_param param = {0};
  pthread_attr_setschedparam(attr, &param);
  pthread_attr_setschedpolicy(attr, 0);
  pthread_attr_setscope(attr, 0);
  pthread_attr_setstack(attr, (void *)0, 0);
  pthread_attr_setstacksize(attr, 0);
  return 0;
}

int pthread_attr_destroy(pthread_attr_t *attr) { return 0; }

int pthread_attr_getdetachstate(const pthread_attr_t *attr, int *detachstate) {
  if (!attr) {
    return EINVAL;
  }
  *detachstate = attr->detachstate;
  return 0;
}
int pthread_attr_getguardsize(const pthread_attr_t *restrict attr,
                              size_t *restrict guardsize) {
  if (!attr) {
    return EINVAL;
  }
  *guardsize = attr->guardsize;
  return 0;
}
int pthread_attr_getinheritsched(const pthread_attr_t *restrict attr,
                                 int *restrict inheritsched) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}
int pthread_attr_getschedparam(const pthread_attr_t *restrict attr,
                               struct sched_param *restrict param) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}
int pthread_attr_getschedpolicy(const pthread_attr_t *restrict attr,
                                int *restrict policy) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}
int pthread_attr_getscope(const pthread_attr_t *restrict attr,
                          int *restrict contentionscope) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}
int pthread_attr_getstack(const pthread_attr_t *restrict attr,
                          void **restrict stackaddr,
                          size_t *restrict stacksize) {
  if (!attr) {
    return EINVAL;
  }
  *stackaddr = attr->stackaddr;
  *stacksize = attr->stacksize;
  return 0;
}
int pthread_attr_getstacksize(const pthread_attr_t *restrict attr,
                              size_t *restrict stacksize) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}

int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}
int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}
int pthread_attr_setinheritsched(pthread_attr_t *attr, int inheritsched) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}
int pthread_attr_setschedparam(pthread_attr_t *restrict attr,
                               const struct sched_param *restrict param) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}
int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}

int pthread_attr_setscope(pthread_attr_t *attr, int contentionscope) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}
int pthread_attr_setstack(pthread_attr_t *attr, void *stackaddr,
                          size_t stacksize) {
  if (!attr) {
    return EINVAL;
  }

  attr->stackaddr = stackaddr;
  attr->stacksize = stacksize;

  return 0;
}
int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize) {
  if (!attr) {
    return EINVAL;
  }
  return 0;
}

int pthread_create(pthread_t *restrict thread,
                   const pthread_attr_t *restrict attr,
                   void *(*start_routine)(void *), void *restrict arg) {}