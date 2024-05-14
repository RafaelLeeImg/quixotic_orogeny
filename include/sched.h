#ifndef __SCHED_H__
#define __SCHED_H__
#include "time.h"

// defined according to POSIX Headers <sched.h>

struct sched_param {
  // Low scheduling priority for sporadic server.
  int sched_ss_low_priority;
  //  Replenishment period for sporadic server.
  struct timespec sched_ss_repl_period;
  //  Initial budget for sporadic server.
  struct timespec sched_ss_init_budget;
  //  Maximum pending replenishments for sporadic server.
  int sched_ss_max_repl;
};

#endif /* __SCHED_H__ */
