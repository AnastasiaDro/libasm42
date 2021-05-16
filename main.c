#include <stdio.h>
#include	<unistd.h>


ssize_t ft_write(int fildes, const void *buf, size_t nbyte);

int main() {
    printf("Hello, World!\n");
    ft_write(1, "hi asm!", 7);
    return 0;
}
