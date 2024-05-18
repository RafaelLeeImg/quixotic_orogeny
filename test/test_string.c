#include "assert.h"
#include "stdio.h"
#include "string.h"

void test_memset(void);

// test cases for memset
void test_memset(void) {
  // memset(memset(a, 300, 10), 101, 10);
  // memset(a+5, (7<<8)+3, 10);
  // memset(a+2, 780, 10);
  const int array_size = 20;
  int a[array_size];
  memset(a, (unsigned int)-1, array_size * sizeof(int));
  //   for (int i = 0; i < array_size; i++) {
  //     printf("a[%d]=%d\n", i, a[i]);
  //   }

  for (int i = 0; i < array_size; i++) {
    assert(a[i] == -1);
  }
}
