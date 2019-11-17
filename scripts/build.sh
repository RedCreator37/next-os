#!/bin/bash
# Builds and links the test kernel

# boot.asm
nasm -f elf32 boot.asm -o boot.o

# kernel.c
gcc -m32 -c kernel.c -o kernel.o

# linking
ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o
