CP := cp
RM := rm -rf
MKDIR := mkdir -pv
CXX := g++

BIN = kernel
CFG = grub.cfg
ISO_PATH := iso
BOOT_PATH := $(ISO_PATH)/boot
GRUB_PATH := $(BOOT_PATH)/grub

SRC := io/bios.cpp io/int.cpp tty/vgautil.cpp tty/vgacur.cpp
OBJ := vgautil.o bios.o vgacur.o

.PHONY: all bootloader objects linker iso clean
all: bootloader kernel linker iso
	@echo Done.

bootloader: boot.asm
	nasm -f elf32 boot.asm -o boot.o

objects:
	$(CXX) -m32 -c $(SRC)
	nasm -f elf32 ./io/idt.asm -o ./io/idt.o

kernel: kernel.cpp objects
	$(CXX) -m32 -c kernel.cpp -o kernel.o

linker: linker.ld boot.o kernel.o
	ld -m elf_i386 -T linker.ld -o kernel boot.o ./io/idt.o $(OBJ) kernel.o

iso: kernel
	$(MKDIR) $(GRUB_PATH)
	$(CP) $(BIN) $(BOOT_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot $(BOOT_PATH)/$(BIN)
	grub-mkrescue -o nextos-v1.iso $(ISO_PATH)

clean:
	-$(RM) *.o $(BIN) *iso io/*.o
