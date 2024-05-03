#ifndef __HARDWARE_USART_H__
#define __HARDWARE_USART_H__

#include "stdint.h"

static const uint32_t USART1_BASE = 0x40011000;
static uint32_t *const USART1_DR = (uint32_t *)(0x40011000 + 0x4);
static uint32_t *const USART1_CR1 = (uint32_t *)(0x40011000 + 0xC);
static uint32_t *const USART1_CR2 = (uint32_t *)(0x40011000 + 0x10);
static uint32_t *const USART1_CR3 = (uint32_t *)(0x40011000 + 0x14);

void usart_setup(void);

#endif /* __HARDWARE_USART_H__ */