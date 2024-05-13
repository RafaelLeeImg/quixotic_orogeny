#include "os_define.h"
#include "pthread.h"
#include "stdint.h"

// use a fixed size array to store thread information. insert them for
// if there are task switching, use bubble sort to find the newest pointer

process_control_block_t processes_control[OS_MAX_PROCESS] = {0};

// scheduler shall run in
