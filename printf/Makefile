NAME =		libftprintf.a

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -f

LIB =		ar rc

HEADER =	ft_printf.h

SRCS =		ft_printf.c aux1.c aux2.c aux3.c

OBJS =		$(SRCS:.c=.o)

%.o:%.c		$(HEADER) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(LIB) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re