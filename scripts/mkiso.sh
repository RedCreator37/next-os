#!/bin/bash
# package the ISO for test kernel
# DEPRECATED: use make instead

grub-file --is-x86-multiboot kernel
cp kernel iso/boot/
cp grub.cfg iso/boot/grub/

# make the final ISO
grub-mkrescue -o test-kernel.iso iso/

