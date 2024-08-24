
#include "keyboard.h"

void keyboard_handler() {
    //JUST PRINT SOMETHING DUDE
    unsigned char status = read8Bit(0x64);
    debug_putchar(status);

    // Check if data is available

    if (status & 0x01) {
        // Read the scan code from the keyboard controller
        unsigned char scan_code = read8Bit(0x60);
        
        debug_putchar('x');

        terminal_writestring("ReadKeyboardInterrupt");
    }


    write8Bit(0x20, 0x20); //semantics 
    write8Bit(0xA0, 0x20);  //semantics 

}
