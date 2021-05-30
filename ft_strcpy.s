global _ft_strcpy

section .text

_ft_strcpy:
            mov rax, 0
loop:
            mov dl, byte[rsi + rax] ; rsi[rax]  ; или правильно с byte[rsi + rax] так же работает rsi[rax]
            mov byte[rdi + rax], dl  ; так же работает rdi[rax]
            cmp byte[rsi + rax], 0  ; а вот тут не работает
            je return
            inc rax
            jmp loop
return:
            mov rax, rdi
            ret
