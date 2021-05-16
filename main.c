#include <stdio.h>
#include	<unistd.h>


ssize_t ft_write(int fildes, const void *buf, size_t nbyte);

int main() {
    printf("Hello, World!\n");
    int i =  (int)ft_write(1, "hi asm!\n", 8);
    printf("i = %d", i);
    return 0;
}
