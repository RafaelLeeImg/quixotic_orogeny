#include "stdio.h"
#include "hardware_usart.h"
#include "stdarg.h"
#include "stdint.h"
#include "string.h"

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

void printf_int(const char str[], size_t start, size_t end, int number);
void printf_hex(const char str[], size_t start, size_t end,
                unsigned int number);
void printf_str(const char str[], size_t start, size_t end, char *input);
int _write(int file, char *data, int len);

int _write(int file, char *data, int len) {
  (void)file;
  for (int i = 0; i < len; i++) {
    *USART1_DR = (data[i]) % 256;
  }
  return len;
}

// TODO: fix print 2147483648 ~ 4294967295
// print format like %03d
void printf_int(const char str[], size_t start, size_t end, int number) {
  // printf("%ld\n", -1L); // -1
  // printf("%d\n", -1L);  // -1
  // printf("%ld\n", -1);  // 4294967295
  // printf("%d\n", -1);   // -1

  char buf0[12] = {0}; // -2147483648 ~ 4294967295
  char buf1_arr[12] = {0};
  char *buf1 = buf1_arr;
  static const char minus_2_pow_31[] = "-2147483648\0";
  int less_than_zero = 0;

  // debug
  // printf("printf_int,");
  // printf("'");
  // for (size_t i = start; i < end; i++) {printf("%c", str[i]);}
  // printf("',");
  // printf("%d\n", number);

  size_t ptr = 0;

  do {
    if (unlikely(number == -2147483648)) {
      buf1 = &(minus_2_pow_31[0]);
      break;
    } else if (number < 0) {
      number = -1 * number;
      less_than_zero = 1; // boolean true
    }
    for (; number > 0; ptr++) {
      // printf("%d",number%10);
      buf0[ptr] = (number % 10) + '0';
      number /= 10;
    }
    if (less_than_zero) {
      buf0[ptr] = '-';
      ptr++;
    }
    size_t ptr1 = 0;
    for (; ptr1 < ptr; ptr1++) {
      buf1[ptr1] = buf0[ptr - 1 - ptr1];
    }
    // printf("ptr = %d\n", ptr);
  } while (0);
  size_t len = strnlen(buf1, MAX_STRING_LEN);
  for (size_t i = 0; i < len; i++) {
    *USART1_DR = buf1[i];
  }
}

// print format like %03d
void printf_hex(const char str[], size_t start, size_t end,
                unsigned int number) {
  // printf("0x%lx\n", -1L); // 0xffffffffffffffff
  // printf("0x%x\n", -1L);  // 0xffffffff
  // printf("0x%lx\n", -1);  // 0xffffffff
  // printf("0x%x\n", -1);   // 0xffffffff

  char buf0[9] = {0}; // -0x7FFFFFFF ~ 0xFFFFFFFF, length of 0x not count
  char buf1_arr[9] = {0};
  char *buf1 = buf1_arr;

  // debug
  // printf("printf_int,");
  // printf("'");
  // for (size_t i = start; i < end; i++) {printf("%c", str[i]);}
  // printf("',");
  // printf("%d\n", number);
  size_t ptr = 0;

  do {
    for (; number > 0; ptr++) {
      // printf("%d",number%16);
      unsigned int remainder = number % 16;
      // 'W' = 'a' - 10
      buf0[ptr] = remainder >= 10 ? remainder + 'W' : remainder + '0';
      number /= 16;
    }
    size_t ptr1 = 0;
    for (; ptr1 < ptr; ptr1++) {
      buf1[ptr1] = buf0[ptr - 1 - ptr1];
    }
    // printf("ptr = %d\n", ptr);
  } while (0);
  size_t len = strnlen(buf1, MAX_STRING_LEN);
  for (size_t i = 0; i < len; i++) {
    *USART1_DR = buf1[i];
  }
}

// TODO: not tested, not verified
void printf_str(const char str[], size_t start, size_t end, char *input) {
  size_t len = strnlen(str, MAX_STRING_LEN);
  for (size_t i = 0; i < len; i++) {
    *USART1_DR = input[i];
  }
}

// void printf(char str[], ...) {
int printf_not_used(const char *restrict str, ...) {
  size_t len = strnlen(str, MAX_STRING_LEN);
  // printf("len = %d\n", len);
  size_t arg_count = 0;
  for (size_t i = 0; i < len; i++) {
    if (str[i] == '%') {
      arg_count++;
    }
  }
  int arg_idx = 0;
  size_t i = 0;
  va_list arg_ptr;
  va_start(arg_ptr, arg_count);
  // printf("arg_count = %d\n", arg_count);

  for (; arg_idx < arg_count && i < len; i++) {
    // printf("i = %d\n", i);
    if (str[i] == '%') {
      // printf("%%");
      size_t start = i;
      int stop_for = 0;
      for (size_t j = i; stop_for == 0 && i < len; j++, i++) {
        // print("str[j]=%c, ", str[j]);

        switch (str[j]) {
        case 'c':
          break;
        case 's':
          // char *input = va_arg(arg_ptr, char *);
          // printf_str(str, start, j + 1, ((char*)arg_ptr)+4);
          // printf_str(str, start, j + 1, input);
          // j--;
          // i--;
          // stop_for = 1;
          break;
        case 'D':
        case 'd': {
          int number = va_arg(arg_ptr, int);
          // printf("number = %d\n", number);
          // printf("||start = %d, i = %d, j = %d, number = %d\n", start, i, j,
          // number); // debug
          printf_int(str, start, j + 1, number);
          j--;
          i--;
          stop_for = 1;
        } break;
        case 'u':
          break;
        case 'o':
          break;
        case 'X':
        case 'x': {
          unsigned int number = va_arg(arg_ptr, unsigned int);
          printf_hex(str, start, j + 1, number);
          j--;
          i--;
          stop_for = 1;
        } break;
        case 'f':
          break;
        case 'e':
          break;
        case 'g':
          break;
        default:
          break;
        }
      }
    } else {
      *USART1_DR = str[i];
    }
  }
  va_end(arg_ptr);

  // printf("strlen = %d\n", strnlen("abc", 4096)); // strlen = 3
}
