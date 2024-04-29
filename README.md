# Description
An operating system runs on Cortex-M micro controllers.


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
    -kernel /dev/shm/d/proj/libopencm3-examples/examples/stm32/f4/olimex_stm32_h405/usart/usart.elf
```

