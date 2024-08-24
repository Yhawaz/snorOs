


#include "debugText.h"

void debug_putchar(char x) {
	// do conversion from char to ascii code in c, then just load it into assembly and only make assembly do:
	// mov $edi, $al
	// outb $0xe9, $al
	// ret
	print_to_qemu_console(x);
}

void debug_putstring(const char* data, size_t size){
	for(size_t i=0; i<size;i++)
		debug_putchar(data[i]);
}

void debug_writestring(const char*data){
	debug_putstring(data,strlen(data));
}

void debug_printcharbyte(unsigned char byte) {
    

    //programming is just realizing u did NOT fall out of a cocunut tree

    //im still clever tho
    const char *hex_digits = "0123456789ABCDEF";
    debug_putchar(hex_digits[(byte >> 4) & 0xF]); 
    debug_putchar(hex_digits[byte & 0xF]);         
}