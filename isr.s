.global isr_wrapper
.align 4

isr_wrapper:
    push %eax                   # Save general-purpose registers
    push %ecx
    push %edx
    push %ebx
    push %esp
    push %ebp
    push %esi
    push %edi

    cld                        # Clear the direction flag
    call keyboard_handler     # Call the C handler

    pop %edi                    # Restore general-purpose registers
    pop %esi
    pop %ebp
    pop %esp
    pop %ebx
    pop %edx
    pop %ecx
    pop %eax

    iret                       # Return from interrupt
