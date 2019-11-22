// A simple x86 operating system kernel
// vgautil.cpp - display routines
// 2019-11-16 by RedCreator37
#include "vgadef.hpp"

// current values
unsigned short *terminal_buffer;
unsigned long terminal_row;
unsigned long terminal_column;
unsigned char terminal_color;

// General

// calculate length of a string
unsigned long strlen(const char* str) {
    unsigned long len = 0;
    while (str[len]) len++;
    return len;
}

// Display initialization, etc.

// clear the screen
void clr_scr() {
    unsigned int index = 0;
    // 25 lines by 80 columns, each element takes 2 bytes
    while (index < VGA_WIDTH * VGA_HEIGHT * 2) {
        terminal_buffer[index] = ' ';
        index += 2;
    }
}

// initialize the terminal buffer
void init_terminal() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
    clr_scr();
}

// Character display

// put together the character
unsigned short vga_entry(unsigned char uc, unsigned char color)  {
    return (unsigned short)uc | (unsigned short)color << 8;
}

// Terminal routines

// set the color
void terminal_setcolor(int fg, int bg) {
    terminal_color = fg | bg << 4;
}

// put the character at the specified location, use the specified color
void terminal_put_at(char c, unsigned char color, unsigned long x, unsigned long y)  {
    const unsigned long index = y * VGA_WIDTH + x;
    terminal_buffer[index] = vga_entry(c, color);
}

// parse the characters (handles newlines)
void terminal_put_char(char c)  {
    if (c == '\n') {
        terminal_row++;
        terminal_column = 0;
        return;
    }

    terminal_put_at(c, terminal_color, terminal_column, terminal_row);
    if (++terminal_column == VGA_WIDTH) {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT)
            terminal_row = 0;
    }
}

// break a string into characters to display
void terminal_write(const char* data, unsigned long size)  {
    for (unsigned long i = 0; i < size; i++)
        terminal_put_char(data[i]);
}

// simplified way of displaying a string
void out_string(const char* data)  {
    terminal_write(data, strlen(data));
}
