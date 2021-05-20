global _ft_write
section .text
        extern ___error

_ft_write:
        mov rax, 0x2000004
        syscall
        jc set_err
        ret
set_err:
        push r10
        mov r10, rax    ;в rax записывается номер ошибки
        call ___error    ;теперь в rax у нас адрес errno
        mov [rax], r10
        push r10
        mov rax, -1
        ret
