global _ft_read
section .text
        mov rax, 0x2000004
        syscall
        jc set_err
        ret
set_err:
        push r10
        mov r10, rax
        call __error
        mov [rax], r10
        push r10
        mov rax, -1
        ret
