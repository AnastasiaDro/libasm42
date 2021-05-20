NAME		= libasm.a
SRC			= ft_strlen.s ft_strcpy.s ft_strcmp.s\
				ft_write.s ft_read.s ft_strdup.s
NASM		= nasm -f macho64
CC			= cc
OBJS		= $(SRC:.s=.o)
CFLAGS		=	-Wall -Wextra -Werror
MAIN		= main.c
TESTNAME	= results

%.o: %.s
			$(NASM) $< -o $@

$(NAME):	$(OBJS)
			ar rcs $(NAME) $?

testlib:    $(NAME)
			$(CC) $(FLAGS) $(MAIN) $(NAME) -o $(TESTNAME)

all:        $(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re testlib