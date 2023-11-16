NAME := pipex

GCC := gcc

RM := rm -rf

CFLAGS := -Wall -Wextra -Werror

HEADER := pipex.h

SRCS := ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c main.c childs.c aux_functions.c path.c exits.c

OBJS := $(SRCS:.c=.o)

%.o:%.c	$(HEADER) Makefile
	$(GCC) $(CFLAGS) -c $< -o $@
	
all:	$(NAME)

$(NAME):	$(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $(NAME) -fsanitize="address,undefined" -g

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re