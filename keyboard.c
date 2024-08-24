
#include "keyboard.h"

void keyboard_handler() {
    // Read the status register of the keyboard controller
    unsigned char status = read8Bit(0x64);
    debug_putchar('x');

    // Check if data is available

    if (status & 0x01) {
        // Read the scan code from the keyboard controller
        unsigned char scan_code = read8Bit(0x60);

        // Print a placeholder character '*' every time any key is pressed
        terminal_putchar('*');
    }


    // Acknowledge the interrupt to the PICs
    write8Bit(0x20, 0x20); // Acknowledge interrupt from master PIC
    write8Bit(0xA0, 0x20); // Acknowledge interrupt from slave PIC (if applicable)
}
