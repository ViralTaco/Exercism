default rel

section .data
    msg db "Hello, World!", 0    ; str + '\0'

section .text
    global hello
        
hello:
    lea rax, [msg] ; load effective address [msg] 
    ret
