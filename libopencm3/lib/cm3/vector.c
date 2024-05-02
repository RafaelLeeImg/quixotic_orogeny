/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2010 Piotr Esden-Tempski <piotr@esden.net>,
 * Copyright (C) 2012 chrysn <chrysn@fsfe.org>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/cm3/scb.h>
#include <libopencm3/cm3/vector.h>

/* load optional platform dependent initialization routines */
// #include "../dispatch/vector_chipset.c"
/* load the weak symbols for IRQ_HANDLERS */
// #include "../dispatch/vector_nvic.c"
// /dev/shm/d/proj/quixotic_orogeny/libopencm3/lib/cm3/vector.c
// /dev/shm/d/proj/quixotic_orogeny/libopencm3/lib/stm32/f4/vector_nvic.c

#include "../stm32/f4/vector_nvic.c"
#include "libopencm3/stm32/f4/handler.h"
#include "libopencm3/stm32/f4/nvic.h"

/* Less common symbols exported by the linker script(s): */
typedef void (*funcp_t)(void);
extern funcp_t __preinit_array_start, __preinit_array_end;
extern funcp_t __init_array_start, __init_array_end;
extern funcp_t __fini_array_start, __fini_array_end;

void blocking_handler(void) {
  while (1)
    ;
}

void null_handler(void) { /* Do nothing. */
}

void nvic_wwdg_isr(void) __attribute__((weak, alias("blocking_handler")));
void pvd_isr(void) __attribute__((weak, alias("blocking_handler")));
void tamp_stamp_isr(void) __attribute__((weak, alias("blocking_handler")));
void rtc_wkup_isr(void) __attribute__((weak, alias("blocking_handler")));
void flash_isr(void) __attribute__((weak, alias("blocking_handler")));
void rcc_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti0_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti1_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti2_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti3_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti4_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_stream0_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_stream1_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_stream2_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_stream3_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_stream4_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_stream5_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_stream6_isr(void) __attribute__((weak, alias("blocking_handler")));
void adc_isr(void) __attribute__((weak, alias("blocking_handler")));
void can1_tx_isr(void) __attribute__((weak, alias("blocking_handler")));
void can1_rx0_isr(void) __attribute__((weak, alias("blocking_handler")));
void can1_rx1_isr(void) __attribute__((weak, alias("blocking_handler")));
void can1_sce_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti9_5_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim1_brk_tim9_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim1_up_tim10_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim1_trg_com_tim11_isr(void)
    __attribute__((weak, alias("blocking_handler")));
void tim1_cc_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim2_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim3_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim4_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c1_ev_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c1_er_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c2_ev_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c2_er_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi1_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi2_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart1_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart2_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart3_isr(void) __attribute__((weak, alias("blocking_handler")));
void exti15_10_isr(void) __attribute__((weak, alias("blocking_handler")));
void rtc_alarm_isr(void) __attribute__((weak, alias("blocking_handler")));
void usb_fs_wkup_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim8_brk_tim12_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim8_up_tim13_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim8_trg_com_tim14_isr(void)
    __attribute__((weak, alias("blocking_handler")));
void tim8_cc_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma1_stream7_isr(void) __attribute__((weak, alias("blocking_handler")));
void fsmc_isr(void) __attribute__((weak, alias("blocking_handler")));
void sdio_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim5_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi3_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart4_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart5_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim6_dac_isr(void) __attribute__((weak, alias("blocking_handler")));
void tim7_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_stream0_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_stream1_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_stream2_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_stream3_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_stream4_isr(void) __attribute__((weak, alias("blocking_handler")));
void eth_isr(void) __attribute__((weak, alias("blocking_handler")));
void eth_wkup_isr(void) __attribute__((weak, alias("blocking_handler")));
void can2_tx_isr(void) __attribute__((weak, alias("blocking_handler")));
void can2_rx0_isr(void) __attribute__((weak, alias("blocking_handler")));
void can2_rx1_isr(void) __attribute__((weak, alias("blocking_handler")));
void can2_sce_isr(void) __attribute__((weak, alias("blocking_handler")));
void otg_fs_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_stream5_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_stream6_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2_stream7_isr(void) __attribute__((weak, alias("blocking_handler")));
void usart6_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c3_ev_isr(void) __attribute__((weak, alias("blocking_handler")));
void i2c3_er_isr(void) __attribute__((weak, alias("blocking_handler")));
void otg_hs_ep1_out_isr(void) __attribute__((weak, alias("blocking_handler")));
void otg_hs_ep1_in_isr(void) __attribute__((weak, alias("blocking_handler")));
void otg_hs_wkup_isr(void) __attribute__((weak, alias("blocking_handler")));
void otg_hs_isr(void) __attribute__((weak, alias("blocking_handler")));
void dcmi_isr(void) __attribute__((weak, alias("blocking_handler")));
void cryp_isr(void) __attribute__((weak, alias("blocking_handler")));
void hash_rng_isr(void) __attribute__((weak, alias("blocking_handler")));
void fpu_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart7_isr(void) __attribute__((weak, alias("blocking_handler")));
void uart8_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi4_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi5_isr(void) __attribute__((weak, alias("blocking_handler")));
void spi6_isr(void) __attribute__((weak, alias("blocking_handler")));
void sai1_isr(void) __attribute__((weak, alias("blocking_handler")));
void lcd_tft_isr(void) __attribute__((weak, alias("blocking_handler")));
void lcd_tft_err_isr(void) __attribute__((weak, alias("blocking_handler")));
void dma2d_isr(void) __attribute__((weak, alias("blocking_handler")));

/**@}*/

/* Initialization template for the interrupt vector table. This definition is
 * used by the startup code generator (vector.c) to set the initial values for
 * the interrupt handling routines to the chip family specific _isr weak
 * symbols. */

#define IRQ_HANDLERS                                                           \
  [NVIC_NVIC_WWDG_IRQ] = nvic_wwdg_isr, [NVIC_PVD_IRQ] = pvd_isr,              \
  [NVIC_TAMP_STAMP_IRQ] = tamp_stamp_isr, [NVIC_RTC_WKUP_IRQ] = rtc_wkup_isr,  \
  [NVIC_FLASH_IRQ] = flash_isr, [NVIC_RCC_IRQ] = rcc_isr,                      \
  [NVIC_EXTI0_IRQ] = exti0_isr, [NVIC_EXTI1_IRQ] = exti1_isr,                  \
  [NVIC_EXTI2_IRQ] = exti2_isr, [NVIC_EXTI3_IRQ] = exti3_isr,                  \
  [NVIC_EXTI4_IRQ] = exti4_isr, [NVIC_DMA1_STREAM0_IRQ] = dma1_stream0_isr,    \
  [NVIC_DMA1_STREAM1_IRQ] = dma1_stream1_isr,                                  \
  [NVIC_DMA1_STREAM2_IRQ] = dma1_stream2_isr,                                  \
  [NVIC_DMA1_STREAM3_IRQ] = dma1_stream3_isr,                                  \
  [NVIC_DMA1_STREAM4_IRQ] = dma1_stream4_isr,                                  \
  [NVIC_DMA1_STREAM5_IRQ] = dma1_stream5_isr,                                  \
  [NVIC_DMA1_STREAM6_IRQ] = dma1_stream6_isr, [NVIC_ADC_IRQ] = adc_isr,        \
  [NVIC_CAN1_TX_IRQ] = can1_tx_isr, [NVIC_CAN1_RX0_IRQ] = can1_rx0_isr,        \
  [NVIC_CAN1_RX1_IRQ] = can1_rx1_isr, [NVIC_CAN1_SCE_IRQ] = can1_sce_isr,      \
  [NVIC_EXTI9_5_IRQ] = exti9_5_isr,                                            \
  [NVIC_TIM1_BRK_TIM9_IRQ] = tim1_brk_tim9_isr,                                \
  [NVIC_TIM1_UP_TIM10_IRQ] = tim1_up_tim10_isr,                                \
  [NVIC_TIM1_TRG_COM_TIM11_IRQ] = tim1_trg_com_tim11_isr,                      \
  [NVIC_TIM1_CC_IRQ] = tim1_cc_isr, [NVIC_TIM2_IRQ] = tim2_isr,                \
  [NVIC_TIM3_IRQ] = tim3_isr, [NVIC_TIM4_IRQ] = tim4_isr,                      \
  [NVIC_I2C1_EV_IRQ] = i2c1_ev_isr, [NVIC_I2C1_ER_IRQ] = i2c1_er_isr,          \
  [NVIC_I2C2_EV_IRQ] = i2c2_ev_isr, [NVIC_I2C2_ER_IRQ] = i2c2_er_isr,          \
  [NVIC_SPI1_IRQ] = spi1_isr, [NVIC_SPI2_IRQ] = spi2_isr,                      \
  [NVIC_USART1_IRQ] = usart1_isr, [NVIC_USART2_IRQ] = usart2_isr,              \
  [NVIC_USART3_IRQ] = usart3_isr, [NVIC_EXTI15_10_IRQ] = exti15_10_isr,        \
  [NVIC_RTC_ALARM_IRQ] = rtc_alarm_isr,                                        \
  [NVIC_USB_FS_WKUP_IRQ] = usb_fs_wkup_isr,                                    \
  [NVIC_TIM8_BRK_TIM12_IRQ] = tim8_brk_tim12_isr,                              \
  [NVIC_TIM8_UP_TIM13_IRQ] = tim8_up_tim13_isr,                                \
  [NVIC_TIM8_TRG_COM_TIM14_IRQ] = tim8_trg_com_tim14_isr,                      \
  [NVIC_TIM8_CC_IRQ] = tim8_cc_isr,                                            \
  [NVIC_DMA1_STREAM7_IRQ] = dma1_stream7_isr, [NVIC_FSMC_IRQ] = fsmc_isr,      \
  [NVIC_SDIO_IRQ] = sdio_isr, [NVIC_TIM5_IRQ] = tim5_isr,                      \
  [NVIC_SPI3_IRQ] = spi3_isr, [NVIC_UART4_IRQ] = uart4_isr,                    \
  [NVIC_UART5_IRQ] = uart5_isr, [NVIC_TIM6_DAC_IRQ] = tim6_dac_isr,            \
  [NVIC_TIM7_IRQ] = tim7_isr, [NVIC_DMA2_STREAM0_IRQ] = dma2_stream0_isr,      \
  [NVIC_DMA2_STREAM1_IRQ] = dma2_stream1_isr,                                  \
  [NVIC_DMA2_STREAM2_IRQ] = dma2_stream2_isr,                                  \
  [NVIC_DMA2_STREAM3_IRQ] = dma2_stream3_isr,                                  \
  [NVIC_DMA2_STREAM4_IRQ] = dma2_stream4_isr, [NVIC_ETH_IRQ] = eth_isr,        \
  [NVIC_ETH_WKUP_IRQ] = eth_wkup_isr, [NVIC_CAN2_TX_IRQ] = can2_tx_isr,        \
  [NVIC_CAN2_RX0_IRQ] = can2_rx0_isr, [NVIC_CAN2_RX1_IRQ] = can2_rx1_isr,      \
  [NVIC_CAN2_SCE_IRQ] = can2_sce_isr, [NVIC_OTG_FS_IRQ] = otg_fs_isr,          \
  [NVIC_DMA2_STREAM5_IRQ] = dma2_stream5_isr,                                  \
  [NVIC_DMA2_STREAM6_IRQ] = dma2_stream6_isr,                                  \
  [NVIC_DMA2_STREAM7_IRQ] = dma2_stream7_isr, [NVIC_USART6_IRQ] = usart6_isr,  \
  [NVIC_I2C3_EV_IRQ] = i2c3_ev_isr, [NVIC_I2C3_ER_IRQ] = i2c3_er_isr,          \
  [NVIC_OTG_HS_EP1_OUT_IRQ] = otg_hs_ep1_out_isr,                              \
  [NVIC_OTG_HS_EP1_IN_IRQ] = otg_hs_ep1_in_isr,                                \
  [NVIC_OTG_HS_WKUP_IRQ] = otg_hs_wkup_isr, [NVIC_OTG_HS_IRQ] = otg_hs_isr,    \
  [NVIC_DCMI_IRQ] = dcmi_isr, [NVIC_CRYP_IRQ] = cryp_isr,                      \
  [NVIC_HASH_RNG_IRQ] = hash_rng_isr, [NVIC_FPU_IRQ] = fpu_isr,                \
  [NVIC_UART7_IRQ] = uart7_isr, [NVIC_UART8_IRQ] = uart8_isr,                  \
  [NVIC_SPI4_IRQ] = spi4_isr, [NVIC_SPI5_IRQ] = spi5_isr,                      \
  [NVIC_SPI6_IRQ] = spi6_isr, [NVIC_SAI1_IRQ] = sai1_isr,                      \
  [NVIC_LCD_TFT_IRQ] = lcd_tft_isr, [NVIC_LCD_TFT_ERR_IRQ] = lcd_tft_err_isr,  \
  [NVIC_DMA2D_IRQ] = dma2d_isr

__attribute__((section(".vectors")))
vector_table_t vector_table = {.initial_sp_value = &_stack,
                               .reset = reset_handler,
                               .nmi = nmi_handler,
                               .hard_fault = hard_fault_handler,

/* Those are defined only on CM3 or CM4 */
#if defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
                               .memory_manage_fault = mem_manage_handler,
                               .bus_fault = bus_fault_handler,
                               .usage_fault = usage_fault_handler,
                               .debug_monitor = debug_monitor_handler,
#endif

                               .sv_call = sv_call_handler,
                               .pend_sv = pend_sv_handler,
                               .systick = sys_tick_handler,
                               .irq = {IRQ_HANDLERS}};

static void pre_main(void) {
  /* Enable access to Floating-Point coprocessor. */
  SCB_CPACR |= SCB_CPACR_FULL * (SCB_CPACR_CP10 | SCB_CPACR_CP11);
}

void __attribute__((weak)) reset_handler(void) {
  volatile unsigned *src, *dest;
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

  /* might be provided by platform specific vector.c */
  pre_main();

  /* Constructors. */
  for (fp = &__preinit_array_start; fp < &__preinit_array_end; fp++) {
    (*fp)();
  }
  for (fp = &__init_array_start; fp < &__init_array_end; fp++) {
    (*fp)();
  }

  /* Call the application's entry point. */
  (void)main();

  /* Destructors. */
  for (fp = &__fini_array_start; fp < &__fini_array_end; fp++) {
    (*fp)();
  }
}

void nmi_handler(void) __attribute__((weak, alias("blocking_handler")));
void hard_fault_handler(void) __attribute__((weak, alias("blocking_handler")));
void mem_manage_handler(void) __attribute__((weak, alias("blocking_handler")));
void bus_fault_handler(void) __attribute__((weak, alias("blocking_handler")));
void usage_fault_handler(void) __attribute__((weak, alias("blocking_handler")));
void sv_call_handler(void) __attribute__((weak, alias("blocking_handler")));
void debug_monitor_handler(void)
    __attribute__((weak, alias("blocking_handler")));
void pend_sv_handler(void) __attribute__((weak, alias("blocking_handler")));
void sys_tick_handler(void) __attribute__((weak, alias("blocking_handler")));
