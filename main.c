#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/fcntl.h>

ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
size_t ft_strlen(const char *s);
char    *ft_strcpy(char *dst, char *src);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_strdup(const char *src);
int     ft_read(int fildes, void *buf, size_t nbyte);


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
    printf("TEST 1. STRINGS: %s & %s   \n", s1, s2);
	printf(" original: |    my:\n");
    printf("     %d        %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
    printf("\nTEST 2. STRINGS: %s & %s   \n", s2, s1);
    printf(" original: |    my:\n");
    printf("     %d        %d\n", strcmp(s2, s1), ft_strcmp(s2, s1));
    s1 = "";
    s2 = "0";
    printf("\nTEST 3. STRINGS: >>EMPTY<< %s& %s   \n", s1, s2);
    printf(" original: |    my:\n");
    printf("     %d        %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));

    s1 = "12345";
    s2 = "12345";
    printf("\nTEST 4. STRINGS: %s & %s \n", s1, s2);
    printf(" original: |    my:\n");
    printf("     %d           %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));

    printf("\n\n	FT_STRDUP\n");
    char *src = "12345";
    char *my_res = ft_strdup(src);
    char *their_res = strdup(src);
    printf("TEST 1. STRING: %s\n", src);
    printf(" original: |    my:\n");
    printf("  %s        %s\n", their_res, my_res);
    free(my_res);
    free(their_res);

    src = "";
    printf("\nTEST 2. STRING: >>EMPTY<<%s\n", src);
    char *m_res = ft_strdup(src);
    char *t_res = strdup(src);
    printf(" original: |    my:\n");
    printf("  %s        %s\n", t_res, m_res);
    free(m_res);
    free(t_res);

    char *l_s = "_1_01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_2_01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_3_01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_4_01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_5_01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    printf("\nTEST 3. LONG STRING: %s\n\n", l_s);
    char *m_r = ft_strdup(l_s);
    char *t_r = strdup(l_s);
    printf("original: \n%s\n\n", t_r);
    printf("my      : \n%s\n\n", m_r);
    printf("length of copies:\n");
    printf(" original: |    my:\n");
    printf("    %lu         %lu\n", strlen(t_r), strlen(m_r));
    free(t_r);
    free(m_r);

    printf("\n\n	FT_STRLEN\n");
    char *string = "12321";
    printf("TEST 1. STRING: %s\n", string);
    printf(" original: |    my:\n");
    printf("    %lu         %lu\n", strlen(string), ft_strlen(string));

    string = "";
    printf("\nTEST 2. STRING: >>EMPTY<<%s\n", string);
    printf(" original: |    my:\n");
    printf("    %lu         %lu\n", strlen(string), ft_strlen(string));

    printf("\nTEST 3. LONG STRING: %s\n\n", l_s);
    printf(" original: |    my:\n");
    printf("    %lu         %lu\n", strlen(l_s), ft_strlen(l_s));


    printf("\n\n	FT_READ\n");
    printf("TEST 1. From file __mfile__\n");
    char *m_buff = calloc(50, sizeof (char));
    char *t_buff = calloc(50, sizeof (char));
    int fd = open("mfile", O_RDONLY);
    int m_readbytes = ft_read(fd, m_buff, 5);
    close(fd);
     fd = open("mfile", O_RDONLY);
    int t_readbytes = read(fd, t_buff, 5);
    close(fd);
    printf(" original: |    my:\n");
    printf("  %s        %s\n", t_buff, m_buff);

    printf("TEST 2. Continue reading 1 - their, 2 - my \nFrom file __mfile__\n");
    fd = open("mfile", O_RDONLY);
    t_readbytes = read(fd, t_buff, 5);
    m_readbytes = ft_read(fd, m_buff, 5);
    close(fd);
    printf(" original: |    my:\n");
    printf("  %s        %s\n", t_buff, m_buff);

    printf("TEST 3. Continue reading 1 - my, 2 - their \nFrom file __mfile__\n");
    fd = open("mfile", O_RDONLY);
    m_readbytes = ft_read(fd, m_buff, 8);
    t_readbytes = read(fd, t_buff, 8);
    close(fd);
    printf(" original: |    my:\n");
    printf("  %s    %s\n", t_buff, m_buff);

    return 0;
}
