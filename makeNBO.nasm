section .rodata
    format db "%d", 10, 0    ; Format string for printf, with newline

section .text
    global _main             ; MacOS uses leading underscore for symbols
    extern _swap_bytes       ; External C function for byte swapping
    extern _printf           ; External printf function from libc

_main:
    ; Call _swap_bytes with 12345
    mov x0, 12345
    bl _swap_bytes           ; Call the C function to swap bytes
    mov x1, x0               ; Move result to x1 for printf
    adr x0, format           ; Address of the format string
    bl _printf               ; Print the result

    ; Repeat for different values
    mov x0, 54321
    bl _swap_bytes
    mov x1, x0
    adr x0, format
    bl _printf

    mov x0, 98765
    bl _swap_bytes
    mov x1, x0
    adr x0, format
    bl _printf

    mov x0, 56789
    bl _swap_bytes
    mov x1, x0
    adr x0, format
    bl _printf

    mov x0, 19283
    bl _swap_bytes
    mov x1, x0
    adr x0, format
    bl _printf

    ; Exit the program
    mov x0, 0                ; Use x0 to load return value
    ret                      ; Return from _main
