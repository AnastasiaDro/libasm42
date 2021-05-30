global _ft_strdup
section .text
        extern _malloc
        extern _ft_strlen
        extern _ft_strcpy

_ft_strdup:
            push rdi
            call _ft_strlen
            mov rdi, rax
            inc rdi
            ;
        ;    mov rdi, 0
            ;
            call _malloc
            jz malloc_err
           ; cmp rax, 0
         ;   je malloc_err
            mov rdi, rax
            pop rsi
            call _ft_strcpy
            mov rdi, rsi
            ret
malloc_err:
           pop rdi
           mov rax, 0
           ret
