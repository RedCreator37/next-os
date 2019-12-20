// A simple x86 operating system kernel
// bios.cpp - BIOS-level interrupt handling
// 2019-11-16 by RedCreator37

// send a value to an I/O location
void outb(unsigned short port, unsigned char val) {
    asm volatile ("outb %0, %1" : : "a"(val), "Nd"(port));
}

// recieve a value from an I/O location
unsigned char inb(unsigned short port) {
    unsigned char ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}
