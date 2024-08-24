#ifndef DEBUGTEXT_H
#define DEBUGTEXT_H
#include "terminalText.h"
#include "debugText.h"

extern void print_to_qemu_console(int x);
extern uint16_t whos_cs();

void debug_putchar(char x);
void debug_putstring(const char* data, size_t size);
void debug_writestring(const char*data);
void debug_printcharbyte(unsigned char byte); 



#endif