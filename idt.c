#include "idt.h"


typedef struct {
    uint16_t    handler_low;      //huh
    uint16_t    kernel_cs;    //0x08
    uint8_t     zero;   // this is always 0 i hope  
    uint8_t     flags;   
    uint16_t    handler_high;   //double huh 
} __attribute__((packed)) idt_entry;

static idt_entry idt[256]; 

typedef struct { uint16_t limit;  uint32_t base;} __attribute__((packed)) idt_ptr;

static idt_ptr idt_allocate;

//IM STARTING TO FUCK WITH POINTERS 
void (*handler_table[256])() = {NULL};

void idt_set_gate(uint8_t entry, void(*handler)(), uint8_t flags){

    //toss it in da idt
    handler_table[entry]=handler;
    //setting those things
    idt[entry].handler_low=(uint32_t)handler & 0xFFFF; //ive prob seen this code lik 80 times but now it makes sense
    idt[entry].kernel_cs=0x0010;
    idt[entry].zero=0; //WOAHHHHHHHHH THIS IS CRAZYYYY
    idt[entry].flags=flags ; //who be choosing these numbers bro
    idt[entry].handler_high=((uint32_t)handler>> 16) & 0xFFFF;

}

void bare_bonestest(){
    terminal_writestring("\n VICTORY OVER MY PAST SELF \n");
    debug_writestring("got here");
}

void idt_init(){
    idt_allocate.limit=sizeof(idt)-1;
    idt_allocate.base=(uint32_t)&idt;

    //we debug terry davis would be proud
    // uint8_t* byte=(uint8_t*)&idt_allocate;
    // for(int i=0;i<6;i++){
    //     debug_printcharbyte(byte[i]);
    // }
    debug_putchar('\n');
    idt_set_gate(0x80,bare_bonestest,0x8E);
    __asm__("lidt %0" : : "m"(idt_allocate));
    
}
