// A simple x86 operating system kernel
// vgautil.hpp - display routines header
// 2019-11-16 by RedCreator37
#ifndef vgautil
#define vgautil

// common
unsigned long strlen(const char* str);

// display initialization, etc.
void clr_scr();
void init_terminal();

// character display
unsigned short vga_entry(unsigned char uc, unsigned char color);
void out_string(const char* data);

// terminal routines
void terminal_setcolor(int bg, int fg);
void terminal_put_at(char c, unsigned char color, unsigned long x, unsigned long y);
void terminal_put_char(char c);
void terminal_write(const char* data, unsigned long size);

#endif