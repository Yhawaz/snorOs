#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "terminalText.h"
#include "debugText.h"
#include "idt.h"

/* Check if the compiler thinks you are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif


// HEY YABI DO THIS: uncomment this when u post the bin u wanna put on github


/* This tutorial will only work for the 32-bit ix86 targets. */
// #if !defined(__i386__)
// #error "This tutorial needs to be compiled with a ix86-elf compiler"
// #endif

/* Hardware text mode color constants. */

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	terminal_writestring("hai");
	idt_init();
	__asm__ ("int $0x80");
	char buf[6] = {0x1,0x1,0x1,0x2,0x1,0x1} ;
	__asm__("sidt %0" : : "m"(buf[0]));
	for (int i = 0; i < 6; i++) {
    	debug_printcharbyte(buf[i]);
	}	


}
