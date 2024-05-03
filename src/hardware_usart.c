#include "hardware_usart.h"
#include "stdint.h"

void usart_setup(void) {
  // data bits: 8 bit, USART_CR1_M, bit clear
  *USART1_CR1 &= ~(((uint32_t)1) << 12);
  // 1 stop bit, USART_CR2_STOP, bits clear
  *USART1_CR2 &= ~(((uint32_t)3) << 12);

  *USART1_CR1 |= (((uint32_t)1) << 2); // RE enable, bit set
  *USART1_CR1 |= (((uint32_t)1) << 3); // TE enable, bit set

  *USART1_CR1 &= ~(((uint32_t)1) << 10); // disable parity, clear PCE bit

  *USART1_CR3 &= ~(((uint32_t)1) << 8); // disable flow control
  *USART1_CR3 &= ~(((uint32_t)1) << 9); // disable flow control
}
