CP := cp
RM := rm -rf
LD := ld
MKDIR := mkdir -pv
CXX := g++
ASM := nasm

BIN := kernel
CFG := grub.cfg
ISO_PATH := iso
BOOT_PATH := $(ISO_PATH)/boot
GRUB_PATH := $(BOOT_PATH)/grub

SRC := io/bios.cpp tty/vgautil.cpp tty/vgacur.cpp
OBJ := vgautil.o bios.o vgacur.o

.PHONY: all bootloader objects linker iso clean
all: bootloader kernel linker iso
	@echo Done.

bootloader: boot.asm
	$(ASM) -f elf32 boot.asm -o boot.o

objects:
	$(CXX) -m32 -c $(SRC)

kernel: kernel.cpp objects
	$(CXX) -m32 -c kernel.cpp -o kernel.o

linker: linker.ld boot.o kernel.o
	$(LD) -m elf_i386 -T linker.ld -o kernel boot.o $(OBJ) kernel.o

iso: kernel
	$(MKDIR) $(GRUB_PATH)
	$(CP) $(BIN) $(BOOT_PATH)
	$(CP) $(CFG) $(GRUB_PATH)
	grub-file --is-x86-multiboot $(BOOT_PATH)/$(BIN)
	grub-mkrescue -o nextos-v1.iso $(ISO_PATH)

clean:
	-$(RM) *.o $(BIN) *iso io/*.o
