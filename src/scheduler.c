#include "os_define.h"
#include "pthread.h"
#include "stdint.h"

// use a fixed size array to store thread information. insert them for
// if there are task switching, use bubble sort to find the newest pointer

void scheduler(void);

// Keep MSP as it is, modify PSP
// run all user space threads use PSP
void scheduler(void) { printf("scheduler\n"); }