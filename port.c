#include "port.h"
uint8_t read8Bit(uint16_t portnum){
    uint8_t data;
    __asm__( "inb %w1, %b0": "=a"(data): "Nd"(portnum): "memory");
    return data;

}
uint16_t read16Bit(uint16_t portnum){
    uint16_t data;
    __asm__( "inw %1, %0": "=a"(data): "Nd"(portnum): "memory");
    return data;
}

void write8Bit(uint16_t portnum, uint8_t val){
     __asm__ volatile ( "outb %b0, %w1" : : "a"(val), "Nd"(portnum) : "memory");

}
void write16Bit(uint16_t portnum, uint16_t val){
     __asm__ volatile ( "outw %0, %1" : : "a"(val), "Nd"(portnum) : "memory");

}
