// A simple x86 operating system kernel
// bios.cpp - BIOS-level interrupt handling header
// 2019-11-16 by RedCreator37
#ifndef bios
#define bios

void outb(unsigned short port, unsigned char val);
unsigned char inb(unsigned short port);

#endif