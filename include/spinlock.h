#ifndef __SPINLOCK_H__
#define __SPINLOCK_H__
#include "stdint.h"
#include "sys/types.h"

void __dmb(void);
uint32_t __ldrex(volatile uint32_t *addr);
uint32_t __strex(uint32_t val, volatile uint32_t *addr);
void __clrex(void);

#endif /* __SPINLOCK_H__ */
