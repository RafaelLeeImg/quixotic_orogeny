#include "os_define.h"

__attribute__((aligned(4))) unsigned char heap[HEAP_SIZE] = {0};
const unsigned char *heap_start = (char *)heap;
const unsigned char *heap_end = (char *)heap + HEAP_SIZE - 1;
