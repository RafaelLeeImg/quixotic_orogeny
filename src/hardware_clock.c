#include "hardware_clock.h"
#include "stdint.h"

void clock_setup(void) {
  uint32_t *RCC_CR = (uint32_t *)0x40023800;

  uint32_t *RCC_AHB1RSTR = (uint32_t *)0x40023810;
  uint32_t *RCC_APB2RSTR = (uint32_t *)0x40023824;

  *RCC_AHB1RSTR |= (uint32_t)0x1;        // enable GPIOA
  *RCC_APB2RSTR |= ((uint32_t)0x1) << 4; // enable USART1

  // USART1, APB2
}
