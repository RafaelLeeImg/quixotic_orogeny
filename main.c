#include "console.h"
#include "hardware_clock.h"
#include "hardware_gpio.h"
#include "hardware_usart.h"
#include "string.h"

#define MAX_STRING_LEN 4096
int main(void) {

  char hello_world[] = "Hello World!\n";
  // char *hello_world = "World!\n";

  clock_setup();
  gpio_setup();
  usart_setup();

  for (size_t i = 0; i < strnlen(hello_world, MAX_STRING_LEN) / sizeof(char);
       i++) {
    *USART1_DR = hello_world[i];
  }

  for (int j = 0; j < 3000; j++) {
    ;
  }

  console_setup();

  while (1) {
    ;
  }

  return 0;
}
