#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>

ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
size_t ft_strlen(const char *s);
char    *ft_strcpy(char *dst, char *src);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strdup(const char *src);


int main()
{
    printf("Start testing...!\n\n");
    printf("	FT_WRITE\n");


    char *s_hi = "Hi asm!";
	printf("TEST 1. STRING: %s\n\n", s_hi);
    printf("  original:  |  my:\n");
	write(1, "  ", ft_strlen("  "));
    int res1 = write(1, s_hi, ft_strlen(s_hi));
    write(1, "    |   ", ft_strlen("   |   "));
    int res2 = ft_write(1, s_hi, ft_strlen(s_hi));
    printf("\n  res  %d     |  res %d", res1, res2);

    printf("\n");
    char *long_str;
    long_str = "adrftglweGJE'GLGKNDLKSDGH445340-DSLDLGNDSLGN;SDGL;DGNGKN;FDGNA;DFGNADFN;GNDAF;GN";
	printf("\nTEST 2. STRING: %s\n\n", long_str);
	printf("  original:\n");
	res1 = write(1, long_str, ft_strlen(long_str));
	printf("\nmy:\n");
	res2 = ft_write(1, long_str, ft_strlen(long_str));
	printf("\n  res  %d     |  res %d", res1, res2);

//	printf("\n");
//    printf("ft_strlen\n");
//    printf("строка 12345 длина: %d\n", (int)ft_strlen("12345"));

    printf("\n\n	FT_STRCPY\n");
	char *my_dst;
	char *orig_dist;
	char *cpy_str = "abcdefghijklmno";
	printf("TEST 1. STRING: %s\n", cpy_str);
	//без маллока не работает!
	my_dst = malloc(sizeof(char) * 40);
	orig_dist = malloc(sizeof(char) * 40);
    ft_strcpy(my_dst, cpy_str);
	strcpy(orig_dist, cpy_str);
	printf("  original:      |  my:\n");
	printf(" %s | %s\n", orig_dist, my_dst);

	printf("\nTEST 2. STRING (empty): %s\n", "");
	ft_strcpy(my_dst, "");
	strcpy(orig_dist, "");
	printf(" %s 		 | %s\n", orig_dist, my_dst);
	free(my_dst);
	free(orig_dist);

	printf("\n\n	FT_STRCMP\n");
	char *s1 = "12345";
	char *s2 = "123";
	printf("  		      original: |    my:\n");
	printf("strings: %s & %s   ", s1, s2);
    printf("  %d          %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
    printf("test 2:\n %d\n", ft_strcmp("123", "12345"));
    printf("test 3:\n %d\n", ft_strcmp("123", ""));
    printf("test 4:\n %d\n", ft_strcmp("12345", "12345"));

    printf("\nft_strdup\n");
    char *src = "12345";
    char *s = ft_strdup(src);
    printf("test 1:\ns = %s\n", s);
    free(s);
    printf("src after freeing: %s\n", src);
    return 0;
}
