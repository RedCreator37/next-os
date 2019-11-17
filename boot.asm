bits 32

section .multiboot              ;accordint to multiboot spec
        dd 0x1BADB002           ;set magic number for bootloader
        dd 0x0                  ;set flags
        dd - (0x1BADB002 + 0x0) ;set checksum

section .text
global start
extern main                     ;defined in C source

start:
        cli                     ;block interrupts
        mov esp, stack_space    ;set stack pointer
        call main
        hlt                     ;halt the CPU (when done running main)

section .bss
resb 8192
stack_space:
