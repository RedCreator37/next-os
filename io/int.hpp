// A simple x86 operating system kernel
// int.hpp - interrupt handling header
// 2019-12-17 by RedCreator37
#ifndef int_header
#define int_header

// a basic IDT table component
struct IDT_entry {
	unsigned short int offset_lowerbits;
	unsigned short int selector;
	unsigned char zero;
	unsigned char type_attr;
	unsigned short int offset_higherbits;
};

struct IDT_entry IDT[256];

void irq0_handler(), irq1_handler(), irq2_handler(), irq3_handler(), irq4_handler(),
     irq5_handler(), irq6_handler(), irq7_handler(), irq8_handler(), irq9_handler(),
     irq10_handler(), irq11_handler(), irq12_handler(), irq13_handler(), irq14_handler(),
     irq15_handler();

#endif
