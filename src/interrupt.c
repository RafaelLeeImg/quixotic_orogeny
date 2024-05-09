void cm_disable_interrupts(void) { __asm__ volatile("CPSID I\n"); }
void cm_disable_faults(void) { __asm__ volatile("CPSID F\n"); }
void cm_enable_interrupts(void) { __asm__ volatile("CPSIE I\n"); }
void cm_enable_faults(void) { __asm__ volatile("CPSIE F\n"); }

volatile unsigned int systick_cnt = 0;

void sys_tick_handler(void) {
  systick_cnt++;
}
