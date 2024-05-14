#include "mutex.h"
#include "spinlock.h"
#include "stdio.h"

void cm_disable_interrupts(void) { __asm__ volatile("CPSID I\n"); }
void cm_disable_faults(void) { __asm__ volatile("CPSID F\n"); }
void cm_enable_interrupts(void) { __asm__ volatile("CPSIE I\n"); }
void cm_enable_faults(void) { __asm__ volatile("CPSIE F\n"); }

volatile unsigned int systick_cnt = 0;

extern pthread_mutex_t lock1;

void sys_tick_handler(void) {
  // extern unsigned int systick_cnt;
  // print(".");
  if ((systick_cnt % 10) == 0) {
    printf(".");
    if ((systick_cnt % 1000) == 0) {
      printf("\n");
    }
  }

  if ((systick_cnt % 500) == 305) {
    printf("t = %ud\n", systick_cnt);
    printf("305 before unlock\n");
    // __clrex();
    printf("lock1.locked_ = %ud\n", lock1.locked_);
    // pthread_spin_lock(&lock1);
    pthread_mutex_unlock(&lock1);
    printf("305 after unlock\n");
    printf("lock1.locked_ = %ud\n", lock1.locked_);
  }

  systick_cnt++;
}
