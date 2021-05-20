#include <stdio.h>
#include	<unistd.h>
#include <stdlib.h>
#include <strings.h>


ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
size_t ft_strlen(const char *s);
char    *ft_strcpy(char *dst, char *src);
int     ft_strcmp(const char *s1, const char *s2);

int main()
{
    printf("Hello, World!\n");
    int i =  (int)ft_write(1, "hi asm!\n", 8);
    printf("i = %d\n", i);
    printf("ft_strlen\n");
    printf("строка 12345 длина: %d\n", (int)ft_strlen("12345"));

    printf("\nft_strcpy\n");
//    char *dst = "abcde";
//    dst[3] = 'p';
    char *dst;
    dst = ft_strcpy(dst, "abcdefghijklmno");
    printf("dist %s\n", dst);

    printf("\nft_strcmp\n");
    printf("test 1:\n %d\n", ft_strcmp("12345", "123"));
    printf("test 2:\n %d\n", ft_strcmp("123", "12345"));
    printf("test 3:\n %d\n", ft_strcmp("123", ""));
    printf("test 4:\n %d\n", ft_strcmp("12345", "12345"));
    return 0;
}
