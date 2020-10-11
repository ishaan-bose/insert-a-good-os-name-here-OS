bits    32
section   .text
    align      4
    dd  0x1BADB002
    dd  0x00
    dd  - (0x1BADB002+0x00)
    
global start
extern kmain    ; this function is going to be located in kernel.c file

start:
    cli ; clears interrupts
    call kmain  ;calls the kmain function in kernel.c
    hlt     ; halt the cpu, aka, pause it from executing from this address

