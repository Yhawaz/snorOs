#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "terminalText.h"
#include "debugText.h"
#include "port.h"
#include "keyboard.h"

#ifndef GDT_H
#define GDT_H




void init_idt();

void init_hardware();

#endif