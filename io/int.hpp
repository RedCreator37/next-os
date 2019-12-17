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

#endif
