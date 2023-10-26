/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiyarash <tiyarash@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:44:43 by tiyarash          #+#    #+#             */
/*   Updated: 2023/08/15 11:10:57 by tiyarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mistrlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		else
			i++;
	}
	return (i);
}

int	mistrchr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != 'C' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	search(char *str, char c, t_window *window, int lines)
{
	int	i;

	i = 0;
	if (mistrchr(str) == 1)
		return (1);
	if (c == '1')
	{
		while (str[i])
		{
			if (str[i] != '1' && i != mistrlen(str))
				return (1);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (str[0] != '1' || str[window->size_x - 1] != '1')
				return (1);
			if (str[i] == 'P')
			{
				window->player++;
				window->map.action = 'P';
				window->map.x = i * 100;
				window->map.y = (7 - lines) * 100;
				
			}
			if (str[i] == 'E')
				window->ex++;
			if (str[i] == 'C')
			{
				window->colect[window->colecion].x = i * 100;
				window->colect[window->colecion].y = (7 - lines) * 100;
				window->colecion++;
			}
			i++;
		}
	}
	return (0);
}

int	check_map(char *map, int fd, t_window *window)
{
	int		count_original;
	int		count;
	int		i;

	i = 0;
	if (map[ft_strlen(map) - 1] != 'r' || map[ft_strlen(map) - 2]
		!= 'e' || map[ft_strlen(map) - 3] != 'b'
		|| map[ft_strlen(map) - 4] != '.')
		printf("Mal\n");
	count_original = mistrlen(get_next_line(fd));
	count = count_original;
	if (count < 0)
		return (1);
	while (count > 0)
	{
		count = mistrlen(get_next_line(fd));
		if (count != 0 && count != count_original)
			return (1);
		i++;
	}
	window->size_y = i;
	window->size_x = count_original;
	return (i);
}

int	check_map2(char *map, int lines, t_window *window)
{
	int			fd;

	window->colecion = 0;
	window->ex = 0;
	window->player = 0;
	fd = open(map, O_RDONLY);
	if (search(get_next_line(fd), '1', window, lines) == 1)
		return (1);
	while (lines > 2)
	{
		if (search(get_next_line(fd), '0', window, lines) == 1)
			return (1);
		lines--;
	}
	if (search(get_next_line(fd), '1', window, lines) == 1)
		return (1);
	if (window->player != 1 || window->ex != 1 || window->colecion < 1)
		return (1);
	return (0);
}

void window_generator(t_window window)
{
	t_system	sys;
	t_data		img;
	t_data		colection;
	t_data		player;
	int			i;
	int			j;

	i = 0;
	j = 0;
	
	sys.mlx = mlx_init();
	
	sys.win = mlx_new_window(sys.mlx, window.size_x * 100, window.size_y * 100, "./so_long");
	img.whidth = 1;
	img.height = 1;
	img.img = mlx_xpm_file_to_image(sys.mlx, "xpm/grass6.xpm", &img.whidth, &img.height);	
	colection.img = mlx_xpm_file_to_image(sys.mlx, "xpm/Coleccionable.xpm", &img.whidth, &img.height);
	player.img = mlx_xpm_file_to_image(sys.mlx, "xpm/PlayerBehind.xpm", &img.whidth, &img.height);
		printf("(%d %d)\n", window.map.x, window.map.y);

	while (i < window.size_x * 100)
	{
		while (j < window.size_y * 100)
		{
			mlx_put_image_to_window(sys.mlx, sys.win, img.img, i, j);
			j += 100;
		}
		j = 0;
		i += 100;
	}
	i = 0;
	while (i < window.colecion)
	{
		mlx_put_image_to_window(sys.mlx, sys.win, colection.img, window.colect[i].x ,window.colect[i].y);
		i++;
	}	
	mlx_put_image_to_window(sys.mlx, sys.win, player.img, window.map.x, window.map.y);
	printf("(%d-%d)\n",  window.map.x, window.map.y);
	mlx_key_hook(sys.win, ft_key_hook, &sys);

	mlx_loop(sys.mlx);
}

int	main(int argc, char *argv[])
{
	int			fd;
	int			int_checker;
	t_window	window;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		write (1, "FORMATO INCORRECTO\n", 19);
		return (1);
	}
	int_checker = check_map(argv[1], fd, &window);
	if (fd == -1 || int_checker == 1
		||check_map2(argv[1], int_checker, &window))
	{
		write (1, "MAPA INCORRECTO\n", 16);
		return (1);
	}
	window_generator(window);
	close(fd);
	printf ("HA LLEGADO AL FINAL DEL MAIN BIEN\n");
}
