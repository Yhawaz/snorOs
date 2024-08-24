# Set the target binary name
TARGET = snorOs

# Define the source files
ASMSOURCES = boot.s 
CXXSOURCES = kernel.c

# Define the object files
ASMOBJECTS = $(ASMSOURCES:.s=.o)
CXXOBJECTS = $(CXXSOURCES:.c=.o)
OBJECTS = $(ASMOBJECTS) $(CXXOBJECTS)

# Define the ISO directory and Grub configuration
ISODIR = isodir
GRUBCFG = grub.cfg

# Compiler and assembler flags
AS = i686-elf-as
GXX = i686-elf-g++
GCC = i686-elf-gcc
CFLAGS = -ffreestanding -O2 -Wall -Wextra -fno-exceptions -m32

# Linker flags
LDFLAGS = -T linker.ld -ffreestanding -O2 -nostdlib -lgcc

# Target rules
all: $(TARGET).iso

%.o: %.s
	$(AS) $< -o $@

%.o: %.c
	$(GCC) -c $< -o $@ $(CFLAGS)

$(TARGET).bin: $(OBJECTS)
	$(GCC) $(LDFLAGS) -o $@ $(OBJECTS)

$(TARGET).iso: $(TARGET).bin
	mkdir -p $(ISODIR)/boot/grub
	cp $(TARGET).bin $(ISODIR)/boot/$(TARGET).bin
	cp $(GRUBCFG) $(ISODIR)/boot/grub/grub.cfg
	grub-mkrescue -o $(TARGET).iso $(ISODIR)

clean:
	rm -f $(OBJECTS) $(TARGET).bin
	rm -rf $(ISODIR)

# Phony targets
.PHONY: all clean iso


