NAME = libft.a

HEADER = libft.h

SRCS = ft_strncmp.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_strstrim.c ft_strjoin.c ft_calloc.c ft_bzero.c ft_strdup.c ft_substr.c ft_split.c ft_itoa.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c
SRCSBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)
OBJSBONUS = ${SRCSBONUS:.c=.o}

LIB = ar rcs

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)
    
%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c -o $@ $<
	
bonus:		${OBJS} ${OBJSBONUS}
		ar rcs ${NAME} ${OBJS} ${OBJSBONUS}

clean:
	rm -f $(OBJS) ${OBJSBONUS}

fclean: clean
	rm -f $(NAME) bonus

re: fclean all

.PHONY: all clean fclean re
