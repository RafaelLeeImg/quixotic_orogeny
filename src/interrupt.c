
void cm_disable_interrupts(void) { __asm__ volatile("CPSID I\n"); }
void cm_disable_faults(void) { __asm__ volatile("CPSID F\n"); }
void cm_enable_interrupts(void) { __asm__ volatile("CPSIE I\n"); }
void cm_enable_faults(void) { __asm__ volatile("CPSIE F\n"); }

void sys_tick_handler(void) { print("sys_tick_handler\n"); }
