#include "assert.h"
#include "stdint.h"
#include "stdio.h"

// **************************** function prototype *****************************
void operator_test(void);
void test(void);
void linker_script_info(void);
void test_include(void);
void test_malloc(void);
void test_memset(void);
void test_operator(void);

// *************************** global variables ********************************
extern uint32_t _data_loadaddr;
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _ebss;
extern uint32_t __preinit_array_start;
extern uint32_t __preinit_array_end;
extern uint32_t __init_array_start;
extern uint32_t __init_array_end;
extern uint32_t __fini_array_start;
extern uint32_t __fini_array_end;

// ************************ function implementation ****************************

void test(void) {
  test_include();
  test_malloc();
  test_operator();
  test_memset();
  printf("all tests passed!!!\n");
}

void test_operator(void) {
  assert(~1u == 0xfffffffe);
  assert(~1 == 0xfffffffe);
  assert(~1L == 0xfffffffe);
  assert(~1uL == 0xfffffffe);
  assert(~1L == -2);
  assert(~1uL == 4294967294);
}

// int vout(int arg_count, ...) {
//   va_list arg_ptr;
//   va_start(arg_ptr, arg_count);
//   int sum = 0;
//   for (int i = 0; i < arg_count; i++) {
//     int number = va_arg(arg_ptr, int);
//   }
//   va_end(arg_ptr);
//   return sum;
// }

void linker_script_info(void) {
  printf("_data_loadaddr = 0x%X\n", _data_loadaddr);
  printf("_data = 0x%X\n", _data);
  printf("_edata = 0x%X\n", _edata);
  printf("_ebss = 0x%X\n", _ebss);
  printf("__preinit_array_start = 0x%X\n", __preinit_array_start);
  printf("__preinit_array_end = 0x%X\n", __preinit_array_end);
  printf("__init_array_start = 0x%X\n", __init_array_start);
  printf("__init_array_end = 0x%X\n", __init_array_end);
  printf("__fini_array_start = 0x%X\n", __fini_array_start);
  printf("__fini_array_end = 0x%X\n", __fini_array_end);
}

