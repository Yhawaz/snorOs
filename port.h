#include <stddef.h>
#include <stdint.h>

#ifndef PORT_H
#define PORT_H

uint8_t read8Bit(uint16_t portnum);
uint16_t read16Bit(uint16_t portnum);

void write8Bit(uint16_t portnum, uint8_t val);
void write16Bit(uint16_t portnum, uint16_t val);


#endif 