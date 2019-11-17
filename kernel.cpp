// A simple x86 operating system kernel
// kernel.cpp - main source file
// 2019-11-16 by RedCreator37
#include "vgadef.hpp"

unsigned short *terminal_buffer;
unsigned int vga_index;

void clr_scr() {
    int index = 0;
    // 25 lines by 80 columns, each element takes 2 bytes
    while (index < 80 * 25 * 2) {
        terminal_buffer[index] = ' ';
        index += 2;
    }
}

void print_str(char *str, unsigned char color) {
    int index = 0;
    while (str[index]) {
        terminal_buffer[vga_index] = (unsigned short)str[index] | (unsigned short)color << 8;
        index++;
        vga_index++;
    }
}

int main() {
    // todo: change
    terminal_buffer = (unsigned short *)VGA_ADDRESS;
    vga_index = 0;

    clr_scr();
    print_str("Hello World! This is a custom operating system kernel, written by RedCreator37.", YELLOW);
    vga_index = 80;     // next line
    print_str("Status: ", YELLOW);
    vga_index = 89;
    print_str("OK", GREEN);
    vga_index = 160;
    print_str("Goodbye!", BRIGHT_RED);
    return 0;
}
