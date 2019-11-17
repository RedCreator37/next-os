// A simple x86 operating system kernel
// vgacur.cpp - bios cursor handling header
// 2019-11-16 by RedCreator37
#ifndef vgacur
#define vgacur

void enable_cursor(unsigned char cursor_start, unsigned char cursor_end);
void disable_cursor();
void move_cursor(int x, int y);
unsigned short get_cursor_position();

#endif