; NEXTOS Bootstrapper
; 2019-11-16 by RedCreator37
bits 32

section .multiboot              ;according to multiboot specs
        dd 0x1BADB002           ;magic number for bootloader
        dd 0x0                  ;flags
        dd - (0x1BADB002 + 0x0) ;checksum (should be exactly 0)

section .text
global start
extern main                     ;defined in C source

start:
        cli                     ;block interrupts
        mov esp, stack_top      ;set stack pointer

        jmp load_gdt
        gdt:                    ;global descriptor table
        gdt_null:
            dq 0

        gdt_code:
            dw 0FFFFh
            dw 0

            db 0
            db 10011010b
            db 11001111b
            db 0

        gdt_data:
            dw 0FFFFh
            dw 0

            db 0
            db 10010010b
            db 11001111b
            db 0

        gdt_end:

        gdt_desc:
            dw gdt_end - gdt - 1
            dd gdt

        load_gdt:
            cli                 ;disable interrupts
            lgdt [gdt_desc]     ;load GDT
            sti                 ;enable interrupts

        continue:
            call main
            hlt                 ;halt the CPU (when done running main)

section .bss                    ;align stack
align 16
stack_bottom:
resb 16384                      ;16 KiB for stack
stack_top:
