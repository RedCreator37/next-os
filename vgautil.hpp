// A simple x86 operating system kernel
// vgautil.hpp - display routines header
// 2019-11-16 by RedCreator37
#ifndef vgautil
#define vgautil

void init_terminal();
void clr_scr();
unsigned char vga_put_color(int fg, int bg);
void terminal_setcolor(unsigned char color);
unsigned short vga_entry(unsigned char uc, unsigned char color);
void terminal_put_at(char c, unsigned char color, unsigned long x, unsigned long y);
void terminal_put_char(char c);
unsigned long strlen(const char* str);
void terminal_write(const char* data, unsigned long size);
void out_string(const char* data);

#endif