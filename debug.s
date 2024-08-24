.global print_to_qemu_console
print_to_qemu_console:
      mov 4(%esp),%eax
      outb %al,$0xe9
     # mov $0x0a,%al
     # outb %al, $0xf
    ret