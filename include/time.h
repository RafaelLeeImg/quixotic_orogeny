#ifndef __TIME_H__
#define __TIME_H__

// defined according to posix Headers <time.h>
// POSIX specification define time_t in sys/types.h, this will create
// recursive include
typedef int time_t;

struct timespec {
  time_t tv_sec; // Seconds.
  long tv_nsec;  // Nanoseconds.
};

struct itimerspec {
  struct timespec it_interval; // Timer period.
  struct timespec it_value;    // Timer expiration.
};

#endif /* __TIME_H__ */
