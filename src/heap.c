#include "os_define.h"

__attribute__((aligned(4))) char heap[HEAP_SIZE] = {0};
const char *heap_start = (char *)heap;
const char *heap_end = (char *)heap + HEAP_SIZE - 1;
