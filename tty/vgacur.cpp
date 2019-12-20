// A simple x86 operating system kernel
// vgacur.cpp - bios cursor handling
// 2019-11-16 by RedCreator37
#include "vgadef.hpp"
#include "../io/bios.hpp"

// enable the cursor
void enable_cursor(unsigned char cursor_start, unsigned char cursor_end) {
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

// disable the cursor
void disable_cursor() {
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

// move the cursor
void move_cursor(int x, int y) {
	unsigned short pos = y * VGA_WIDTH + x;
	outb(0x3D4, 0x0F);
	outb(0x3D5, (unsigned char) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (unsigned char) ((pos >> 8) & 0xFF));
}

// get the cursor position
// to get X and Y: y = pos / VGA_WIDTH; x = pos % VGA_WIDTH;
unsigned short get_cursor_position() {
    unsigned short pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((unsigned short)inb(0x3D5)) << 8;
    return pos;
}
