// A simple x86 operating system kernel
// vgadef.h - basic VGA defines
// 2019-11-16 by RedCreator37
#ifndef vgadef
#define vgadef

// video memory begins here
#define VGA_ADDRESS 0xB8000

// display properties
const unsigned long VGA_WIDTH = 80;
const unsigned long VGA_HEIGHT = 25;

// all 16 VGA colors
enum VGA_COLOR {
    VGA_BLACK          = 0x0,
    VGA_BLUE           = 0x1,
    VGA_GREEN          = 0x2,
    VGA_CYAN           = 0x3,
    VGA_RED            = 0x4,
    VGA_MAGENTA        = 0x5,
    VGA_BROWN          = 0x6,
    VGA_GRAY           = 0x7,
    VGA_DARK_GRAY      = 0x8,
    VGA_BRIGHT_BLUE    = 0x9,
    VGA_BRIGHT_GREEN   = 0xA,
    VGA_BRIGHT_CYAN    = 0xB,
    VGA_BRIGHT_RED     = 0xC,
    VGA_BRIGHT_MAGENTA = 0xD,
    VGA_YELLOW         = 0xE,
    VGA_WHITE          = 0xF
};

#endif
