NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c keey_hook.c ft_itoa.c ft_strdup.c flood.c

OBJECTS = $(CFILES:%.c=%.o)

all: subsystems $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(MLX_FLAGS) -Imlx -c -o $@ $<

subsystems:
	make -C mlx

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) libmlx.dylib $(OBJECTS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -g

clean:
	rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norm