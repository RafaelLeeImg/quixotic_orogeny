#include "console.h"
#include "hardware_clock.h"
#include "hardware_gpio.h"
#include "hardware_systick.h"
#include "hardware_usart.h"
#include "pthread.h"
#include "stdio.h"
#include "string.h"
#include "sys/types.h"
// #include <stdarg.h>

#define MAX_STRING_LEN 4096
void print(char const str[]);
void test(void);
void cm_enable_interrupts(void);
void cm_enable_faults(void);

void print(char const str[]);

void print(char const str[]) {
  for (size_t i = 0; i < strnlen(str, MAX_STRING_LEN) / sizeof(char); i++) {
    *USART1_DR = str[i];
  }
}

pthread_mutex_t lock1;
extern volatile unsigned int systick_cnt;

void process_1(void) {}

void process_2(void) {}

int main(void) {

  char hello_world[] = "Hello World!\n";
  // char *hello_world = "World!\n";

  clock_setup();
  gpio_setup();
  usart_setup();
  // print(hello_world);

  // printf("test printf_hex = 0x%x\n", 0xffff);
  // printf("test printf_str =  %s\n", hello_world);
  // printf("aisioa = %d\n", 1891289);
  test();
  systick_setup();

  printf("cm_enable_interrupts\n");
  cm_enable_interrupts();

  printf("cm_enable_faults\n");
  cm_enable_faults();

  printf("console_setup\n");
  console_setup();

  int locked = 0;
  while (1) {
    // printf(".");
    if (systick_cnt % 500 == 10 /*  && systick_cnt <= 20 */) {
      printf("t = %ud\n", systick_cnt);
      pthread_mutex_init(&lock1, 0);
    } else if (systick_cnt % 500 == 200 /*  && systick_cnt <= 210 */) {
      printf("t = %ud\n", systick_cnt);
      if (1) {
        // if (locked == 0) {
        print("200 before lock\n");
        // __clrex();
        printf("lock1.locked_ = %d\n", lock1.locked_);
        pthread_mutex_lock(&lock1);
        // pthread_mutex_unlock(&lock1);
        print("200 after lock\n");
        printf("lock1.locked_ = %d\n", lock1.locked_);
        locked = 1;
      }
    } else if (systick_cnt % 500 == 499 /*  && systick_cnt <= 410 */) {
      printf("t = %ud\n", systick_cnt);
      if (locked == 1) {
        printf("499 before unlock\n");
        pthread_mutex_unlock(&lock1);
        printf("499 after unlock\n");
        locked = 0;
      }
    }
  }

  for (int j = 0; j < 3000; j++) {
    ;
  }

  return 0;
}
