# Description
An operating system runs on Cortex-M micro controllers.  


## Plan:
1, run fully on emulator first  
1, logging system, through rdimon  
1, reset handler and vector table  
1, implement USART I/O output, for debugging purpose  
1, implement minimal memory management  
1, data types  
1, implement atomic operations  
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
