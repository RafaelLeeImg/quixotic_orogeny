#include "hardware_systick.h"
#include "stdint.h"
void systick_setup(void) {
  uint32_t *SYST_CSR = 0xE000E010;
  uint32_t *SYST_RVR = 0xE000E014;
  uint32_t *SYST_CVR = 0xE000E018;
  uint32_t *SYST_CALIB = 0xE000E01C;

  *SYST_CSR |= 1 << 2;  // clock source processor clock
  *SYST_RVR = 1000 - 1; //

  // SysTick Control and Status Register, SYST_CSR, TICKINT, bit[1]
  // generate a systick exception when counter is changed to 0
  *SYST_CSR |= 1 << 1; // TICKINT, bit[1]

  *SYST_CSR |= 1 << 0; // ENABLE, bit[0]
}
