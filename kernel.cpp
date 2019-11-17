// A simple x86 operating system kernel
// kernel.cpp - main source file
// 2019-11-16 by RedCreator37
#include "vgadef.hpp"

unsigned short *terminal_buffer;
//unsigned int vga_index;
unsigned long terminal_row;
unsigned long terminal_column;
unsigned char terminal_color;

// screen handling
void clr_scr() {
    int index = 0;
    // 25 lines by 80 columns, each element takes 2 bytes
    while (index < VGA_WIDTH * VGA_HEIGHT * 2) {
        terminal_buffer[index] = ' ';
        index += 2;
    }
}

// compiles the color values
unsigned char vga_put_color(int fg, int bg)  {
	return fg | bg << 4;
}

// set the color
void terminal_setcolor(unsigned char color) {
	terminal_color = color;
}

// put together the character
unsigned short vga_entry(unsigned char uc, unsigned char color)  {
	return (unsigned short)uc | (unsigned short)color << 8;
}

void terminal_putentryat(char c, unsigned char color, unsigned long x, unsigned long y)  {
	const unsigned long index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}
 
void terminal_putchar(char c)  {
	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VGA_HEIGHT)
			terminal_row = 0;
	}
}

unsigned long strlen(const char* str) {
	unsigned long len = 0;
	while (str[len]) len++;
	return len;
}

void terminal_write(const char* data, unsigned long size)  {
	for (unsigned long i = 0; i < size; i++)
		terminal_putchar(data[i]);
}
 
void terminal_writestring(const char* data)  {
	terminal_write(data, strlen(data));
}

// deprecated
//void print_str(char *str, unsigned char color) {
//    int index = 0;
//    while (str[index]) {
//        terminal_buffer[vga_index] = (unsigned short)str[index] | (unsigned short)color << 8;
//        index++;
//        vga_index++;
//    }
//}

void init_terminal() {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_put_color(VGA_YELLOW, VGA_BLACK);
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
    clr_scr();
}

int main() {
    // todo: change
    init_terminal();

    terminal_writestring("Hello World! This is a custom os kernel!\nHello Again!");

    //vga_index = 0;
    //print_str("Hello World! This is a custom operating system kernel, written by RedCreator37.", VGA_YELLOW);
    //vga_index = 80;     // next line
    //print_str("Status: ", VGA_YELLOW);
    //vga_index = 89;
    //print_str("OK", VGA_GREEN);
    //vga_index = 160;
    //print_str("Goodbye!", VGA_BRIGHT_RED);
    return 0;
}
