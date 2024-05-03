#include "libopencm3/cm3/scb.h"

typedef void (*funcp_t)(void);

void reset_handler(void) {
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

  volatile unsigned int *src, *dest;

  funcp_t *fp;

  for (src = &_data_loadaddr, dest = &_data; dest < &_edata; src++, dest++) {
    *dest = *src;
  }

  while (dest < &_ebss) {
    *dest++ = 0;
  }

  /* Ensure 8-byte alignment of stack pointer on interrupts */
  /* Enabled by default on most Cortex-M parts, but not M3 r1 */
  SCB_CCR |= SCB_CCR_STKALIGN;

  /* Enable access to Floating-Point coprocessor. */
  SCB_CPACR |= SCB_CPACR_FULL * (SCB_CPACR_CP10 | SCB_CPACR_CP11);

  /* Constructors. */
  for (fp = &__preinit_array_start; fp < &__preinit_array_end; fp++) {
    (*fp)();
  }
  for (fp = &__init_array_start; fp < &__init_array_end; fp++) {
    (*fp)();
  }

  (void)main();

  /* Destructors. */
  for (fp = &__fini_array_start; fp < &__fini_array_end; fp++) {
    (*fp)();
  }
}
