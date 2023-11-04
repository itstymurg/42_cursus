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
			&& str[i] != 'E' && str[i] != 'C' && str[i] != '\n' && str[i] != 'N')
			return (1);
		i++;
	}
	return (0);
}

int	search(char *str, char c, t_system *sys, int iterator)
{
	int	i;
	t_data wall;
	wall.height = 1;
	wall.whidth = 1;
	
	i = 0;
	if (mistrchr(str) == 1)
		return (1);
	if (c == '1')
	{
		
		while (str[i] != '\n' && str[i] != '\0')
		{
			sys->window.wall[sys->window.walls].x = i * 100;
			sys->window.wall[sys->window.walls].y = iterator * 100;
			sys->window.walls++;
			if (str[i] != '1' && i != mistrlen(str))
				return (1);
			i++;
		}
	}
	
	else
	{
		while (str[i])
		{
			if (str[0] != '1' || str[sys->window.size_x - 1] != '1')
				return (1);
			if (str[i] == 'P')
			{
				
				sys->window.player++;
				sys->window.map.action = 'P';
				sys->window.map.x = i * 100;
				sys->window.map.y = iterator * 100;
				
			}
			if (str[i] == 'E')
			{
				sys->window.ex++;
				sys->window.exi.x = i * 100;
				sys->window.exi.y = iterator * 100;
			}
			if (str[i] == 'C')
			{
				sys->window.colect[sys->window.colecion].x = i * 100;
				sys->window.colect[sys->window.colecion].y = iterator * 100;
				sys->window.colecion++;
			}
			if (str[i] == '1')
			{
				sys->window.wall[sys->window.walls].x = i * 100;
				sys->window.wall[sys->window.walls].y = iterator * 100;
				sys->window.walls++;
				
			}
			if (str[i] == 'N')
			{
				sys->window.enemy[sys->window.enemies].x = i * 100;
				sys->window.enemy[sys->window.enemies].y = iterator * 100;
				sys->window.enemies++;
			}
			i++;
		}
	}
	return (0);
}

int	check_map(char *map, int fd, t_system *sys)
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
	sys->window.size_y = i;
	sys->window.size_x = count_original;
	return (i);
}

int	check_map2(char *map, int lines, t_system *sys)
{
	int			fd;
	int			i;

	i = 0;
	sys->window.colecion = 0;
	sys->window.enemies = 0;
	sys->window.walls = 0;
	sys->window.ex = 0;
	sys->window.player = 0;
	fd = open(map, O_RDONLY);
	
	if (search(get_next_line(fd), '1', sys, 0) == 1)
		return (1);
	
	while (lines > 2)
	{
		if (search(get_next_line(fd), '0', sys, i + 1) == 1)
			return (1);
		lines--;
		i++;
	}
	if (search(get_next_line(fd), '1', sys, sys->window.size_y - 1) == 1)
		return (1);
	
	if (sys->window.player != 1 || sys->window.ex != 1 || sys->window.colecion < 1)
		return (1);
	return (0);
}

int gif(t_system *sys)
{
	static int i = 0;
	static int j = 0;
	int			k = 0;

	if(sys->window.loose == 1)
	{
		print_game_over(sys);
		return (0);
	}
	if(sys->window.win == 1)
	{
		win_condition(sys);
		write(1, "You Won\n", 8);
		exit (0);
	}
	if (j >= 9)
		j = 0;

	if(i % 1000 == 0)
	{
		while (k < sys->window.enemies){
			mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[GROUND].img, sys->window.enemy[k].x, sys->window.enemy[k].y);
			mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[ENEMY1 + j].img, sys->window.enemy[k].x, sys->window.enemy[k].y);
			k++;
		}
		j++;
	}
	i++;
	return(0);
}

void vector_inicilize(t_system *sys)
{
	sys->mlx = mlx_init();
	sys->win = mlx_new_window(sys->mlx, sys->window.size_x * 100, sys->window.size_y * 100, "./so_long");
	
	sys->imgs[GROUND].whidth = 1;
	sys->imgs[GROUND].height = 1;
	
	sys->imgs[ENEMY].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy1.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[COIN].img = mlx_xpm_file_to_image(sys->mlx, "xpm/CoinMini2.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[GROUND].img = mlx_xpm_file_to_image(sys->mlx, "xpm/grass6.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[WALL].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Wall.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[EXIT].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Exit.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[PLAYER].img = mlx_xpm_file_to_image(sys->mlx, "xpm/PlayerFront.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[BLACK].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Black.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[ENEMY1].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy1.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[ENEMY2].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy2.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[ENEMY3].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy3.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[ENEMY4].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy4.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[ENEMY5].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy5.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[ENEMY6].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy6.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[ENEMY7].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy7.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[ENEMY8].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy8.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
	sys->imgs[ENEMY9].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Enemy9.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].height);
}

void	ground_inicialize(t_system *sys)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sys->window.size_x * 100)
	{
		while (j < sys->window.size_y * 100)
		{
			mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[GROUND].img, i, j);
			j += 100;
		}
		j = 0;
		i += 100;
	}
}

void	colecion_inicialize(t_system *sys)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sys->window.colecion)
	{
		mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[COIN].img, sys->window.colect[i].x + 25 ,sys->window.colect[i].y + 25);
		i++;
	}
}

void	walls_inicialize(t_system *sys)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sys->window.walls)
	{
		mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[WALL].img, sys->window.wall[i].x ,sys->window.wall[i].y);
		i++;
	}
}

void	enemies_inicialize(t_system *sys)
{
	int	i;

	i = 0;
	while (i < sys->window.enemies)
	{
		mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[ENEMY].img, sys->window.enemy[i].x ,sys->window.enemy[i].y);
		i++;
	}
}

void map_inicialize(t_system *sys)
{
	sys->window.coins = sys->window.colecion;
	sys->window.loose = 0;
	sys->window.contador = 1;
	sys->window.win = 0;
	vector_inicilize(sys);	
	ground_inicialize(sys);
	walls_inicialize(sys);
	colecion_inicialize(sys);
	mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[PLAYER].img, sys->window.map.x, sys->window.map.y);
	mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[EXIT].img, sys->window.exi.x, sys->window.exi.x);
}


void window_generator(t_system *sys)
{
	map_inicialize(sys);
	mlx_key_hook(sys->win, ft_key_hook, sys);
	mlx_hook(sys->win, 17, 1L << 0, (void *)exit, NULL);
	mlx_loop_hook(sys->mlx, gif, sys);
	mlx_loop(sys->mlx);
}

int	main(int argc, char *argv[])
{
	int			fd;
	int			int_checker;
	t_system	sys;	

	fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		write (1, "FORMATO INCORRECTO\n", 19);
		return (1);
	}
	int_checker = check_map(argv[1], fd, &sys);
	if (fd == -1 || int_checker == 1 ||check_map2(argv[1], int_checker, &sys))
	{
		write (1, "MAPA INCORRECTO\n", 16);
		return (1);
	}
	window_generator(&sys);
	close(fd);
}
