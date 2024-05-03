# Description
An operating system runs on Cortex-M micro controllers.  


## Plan:
1, run fully on emulator first  ... Done  
1, logging system, through rdimon  ... Done  
1, reset handler and vector table  ... Done  
1, implement USART I/O output, for debugging purpose  ... Done  
1, implement systick timer  ... Done  
1, implement atomic operations  
1, implement minimal memory management  
1, data types  
1, multi tasking  
1, inter process communication  
1, implement a minimal C standard library function.  

## hardware
MCU: STM32F405RET6  
schematic: https://www.olimex.com/Products/ARM/ST/STM32-H405/resources/STM32-H405_sch.pdf  


# emulate
```bash
# example, done, successful
# redirect USART1 output to terminal
# compile with --specs=rdimon.specs
qemu-system-arm \
    -M olimex-stm32-h405 \
    -cpu cortex-m4 \
    -nographic \
    -serial stdio \
    -monitor null \
    -semihosting \
    --semihosting-config enable=on,target=native \
    -kernel build/main.elf
```



## references
PM0214 Programming manual STM32 Cortex®-M4 MCUs and MPUs programming manual
RM0090 Reference manual STM32F405/415, STM32F407/417, STM32F427/437 and STM32F429/439 advanced ARM®-based 32-bit MCUs
STM32F405xx STM32F407xx Arm® Cortex®-M4 32b MCU+FPU, 210DMIPS, up to 1MB Flash/192+4KB RAM, USB OTG HS/FS, Ethernet, 17 TIMs, 3 ADCs, 15 comm. interfaces & camera
Cortex-M4 Revision r0p0 Technical Reference Manual
Arm v7-M Architecture ® Reference Manual
IEEE & The Open Group - IEEE Std 1003.1-2017
