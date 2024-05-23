#include "os_define.h"
#include "pthread.h"
#include "stdint.h"

// use a fixed size array to store thread information. insert them for
// if there are task switching, use bubble sort to find the newest pointer

typedef struct {
  uint32_t *stack_pointer; // Pointer to the saved stack
                           // Add other task-related information as needed
} TCB;

#define MAX_TASKS OS_MAX_PROCESS
TCB task_list[MAX_TASKS];
TCB *current_task;
TCB *next_task;

extern pthread_attr_t os_threads[OS_MAX_PROCESS];

void scheduler(void);

// void copy_value_to_r0(uint32_t value) {
//     __asm volatile (
//         "mov r0, %0\n"  // Move the value into R0
//         :               // No output operands
//         : "r" (value)   // Input operand: value to be moved into R0
//         : "r0"          // Clobbered register: R0 is modified
//     );
// }

// void set_psp(unsigned int value) {
//   // Save the current task's context (registers, stack pointer, etc.)
//     __asm volatile ("mov r0, %0" :: "r" (value) : "r0");

// }

void set_psp(uint32_t value) {
  __asm volatile("msr psp, %0" ::"r"(value) : "memory");
}

unsigned int read_psp() {
  // Save the current task's context (registers, stack pointer, etc.)
  __asm volatile("MRS   r0, psp\n" // Get Process Stack Pointer (PSP)
  );
}

unsigned int read_msp() {
  // Save the current task's context (registers, stack pointer, etc.)
  __asm volatile("MRS   r0, msp\n" // Get Process Stack Pointer (MSP)
  );
}

void save_context(TCB *task) {
  // Save the current task's context (registers, stack pointer, etc.)
  __asm volatile(
      "MRS   r0, psp\n"       // Get Process Stack Pointer (PSP)
      "STMDB r0!, {r4-r11}\n" // Store registers R4-R11 onto the stack
      "STMDB r0!, {lr}\n"     // Store Link Register (LR)
      "STR   r0, [r1]\n"      // Save PSP to TCB
  );
}

void restore_context(TCB *task) {
  __asm volatile(
      "LDR   r0, [r1]\n"      // Load PSP from TCB
      "LDMIA r0!, {lr}\n"     // Restore Link Register (LR)
      "LDMIA r0!, {r4-r11}\n" // Restore registers R4-R11 from the stack
      "MSR   psp, r0\n"       // Update PSP
  );
}

void schedule_next_task(void) {
  // Simple round-robin scheduler
  static int current_task_index = 0;

  do {
    current_task_index = (current_task_index + 1) % MAX_TASKS;
    next_task = &task_list[current_task_index];
  } while (next_task == (TCB *)0);
}

// Keep MSP as it is, modify PSP
// run all user space threads use PSP
void scheduler(void) {
  printf("enter scheduler();\n");

  printf("psp: 0x%x\n", read_msp());
  set_psp(0x20004000);
  printf("msp: 0x%x\n", read_msp());
  printf("psp: 0x%x\n", read_psp());
  save_context(current_task); // Save context of the current task
  printf("save_context(current_task);\n");
  schedule_next_task(); // Determine the next task to run
  printf("schedule_next_task();\n");
  restore_context(next_task); // Restore context of the next task
  printf("restore_context(next_task);\n");
  current_task = next_task; // Update current task
  printf("exit scheduler();\n");
}
