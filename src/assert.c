#include "assert.h"

extern void blocking_handler(void);

void assert(int expression) {
  if (expression == 0) {
    blocking_handler();
  }
}