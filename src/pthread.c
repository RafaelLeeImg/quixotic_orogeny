#include "pthread.h"
#include "errno.h"
#include "os_define.h"
#include "stdlib.h"

pthread_attr_t os_thresds[OS_MAX_PROCESS] = {0};
// pthread_attr_t os_thresd_attrs[OS_MAX_PROCESS] = {0};

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

int pthread_attr_destroy(pthread_attr_t *attr) {
  free(attr->stackaddr);
  return 0;
}

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
                   void *(*start_routine)(void *), void *restrict arg) {
  for (int i = 0; i < OS_MAX_PROCESS; i++) {
    if (os_thresds[i].pid == 0) {
      unsigned char *stackaddr = (void *)malloc(PROCESS_MEMORY);
      size_t stacksize = 0;
      unsigned int stackend = stackaddr + PROCESS_MEMORY;
      // align 4 bytes
      stackend = stackend - (stackend & 3);
      stacksize = stackend - (unsigned int)stackaddr;
      // printf("stacksize = 0x%08x\n", stacksize);
      // process_control_block_t pcb = os_thresds[i];
      pthread_attr_t process_attr = os_thresds[i];
      pthread_attr_setstack(&process_attr, stackaddr, stacksize);

      process_attr.registers[REGISTER_SP] = stackend;

      printf("process_attr = .addr = %p, .stacksize = %d\n",
             process_attr.stackaddr, process_attr.stacksize);
    }
    break;
  }
}

void pthread_exit(void *) {}

int pthread_join(pthread_t, void **) {}
