// A simple x86 operating system kernel
// kernel.cpp - main source file
// 2019-11-16 by RedCreator37
#include "tty/vgadef.hpp"
#include "tty/vgautil.hpp"
#include "tty/vgacur.hpp"

// entry point
int main() {
    init_terminal();

	terminal_setcolor(VGA_WHITE, VGA_BLACK);
    out_string("    _   _________  ____________   _____        ___      \n");
    out_string("   / | / / ____/ |/ /_  __/ __ \\/ ___/   _   _<  /     \n");
    out_string("  /  |/ / __/  |   / / / / / / /\\__ \\   | | / / /     \n");
    out_string(" / /|  / /___ /   | / / / /_/ /___/ /   | |/ / /        \n");
    out_string("/_/ |_/_____//_/|_|/_/  \\____//____/    |___/_/        \n\n");
	out_string("Starting NEXTOS v1.0... Hold on...\n");

    // print the hello world message
    terminal_setcolor(VGA_YELLOW, VGA_BLACK);
    out_string("Hello World! This is a custom operating system kernel, written by RedCreator37.\n");
    out_string("Status: ");
    terminal_setcolor(VGA_BRIGHT_GREEN, VGA_BLACK);
    out_string("OK\n");
    terminal_setcolor(VGA_BRIGHT_RED, VGA_BLACK);
    out_string("Goodbye!");
    move_cursor(9, 9);

    return 0;
}
