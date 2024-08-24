.global print_to_qemu_console
print_to_qemu_console:
      mov 4(%esp),%eax
      outb %al,$0xe9
     # mov $0x0a,%al
     # outb %al, $0xf
    ret
.global whos_cs
whos_cs:
    push %cs             # Push the CS register value onto the stack
    pop %eax             # Pop the CS value into EAX
    ret
