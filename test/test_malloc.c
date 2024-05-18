#include "assert.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"

extern void debug_malloc(void);
extern memory_block_t *g_root;
void test_malloc(void);

void test_malloc(void) {
  int *a[20] = {0};
  printf("before malloc\n");
  a[0] = (int *)malloc(12);
  free(a[0]);
  a[0] = 0;
  debug_malloc();
  assert(g_root == (void *)0);
  printf("after malloc\n");

  printf("before malloc\n");
  for (int i = 0; i < 7; i++) {
    a[i] = (int *)malloc(244);
    printf("i = %2d, ", i);
    printf("a[%2d] = %p\n", i, (void *)a[i]);
    debug_malloc();
  }
  for (int i = 0; i < 7; i++) {
    unsigned char *x =
        (unsigned char *)g_root + (i + 1) * sizeof(memory_block_t) + 244 * i;
    assert(a[i] == (int *)x);
  }
  printf("after malloc\n");

  printf("before free\n");
  int k[] = {3, 5, 0, 1};
  for (size_t i = 0; i < sizeof(k) / sizeof(k[0]); i++) {
    printf("free(a[%d]);\n", k[i]);
    free(a[k[i]]);
    a[k[i]] = 0;
    debug_malloc();
  }
  printf("after free\n");

  printf("before 2nd malloc\n");
  for (int i = 0; i < 10; i++) {
    if (!a[i]) {
      a[i] = (int *)malloc(240);
      printf("i = %2d\n", i);
      printf("a[%2d] = %p\n", i, (void *)a[i]);
      debug_malloc();
    }
  }
  printf("after 2nd malloc\n");
}
