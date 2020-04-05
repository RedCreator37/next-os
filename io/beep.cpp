// // A simple x86 operating system kernel
// beep.cpp - preliminary testing of the PC chassis speaker operations
// 2020-01-24 by RedCreator37
#include "bios.hpp"

// play a sound using the chassis speaker
static void play_sound(unsigned int frequency) {
    unsigned int div;
    unsigned char tmp;

    // set the frequency
    div = 1193180 / frequency;
    outb(0x43, 0xb6);
    outb(0x42, (unsigned char)(div));
    outb(0x42, (unsigned char)(div >> 8));

    // send the signal
    tmp = inb(0x61);
    if (tmp != (tmp | 3)) outb(0x61, tmp | 3);
}

// mute the chassis speaker
static void nosound() {
    unsigned char tmp = inb(0x61) & 0xFC;
    outb(0x61, tmp);
}

// send a beep signal to the chassis speaker
void beep() {
    play_sound(1000);
    //timer_wait(10); fix the interrupts then enable this
    nosound();
}