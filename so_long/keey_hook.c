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

void print_game_over(t_system *sys)
{
	t_data black;


	black.img = mlx_xpm_file_to_image(sys->mlx, "xpm/Black.xpm", &black.endian, &black.whidth);
	black.endian = 100;
	black.whidth = 100;

	int i = 0, j = 0;
	while (i < sys->window.size_x * 100)
		{
			while (j < sys->window.size_y * 100)
			{
				mlx_put_image_to_window(sys->mlx, sys->win, black.img, i, j);
				j += 100;
			}
			j = 0;
			i += 100;
		}
		mlx_string_put(sys->mlx,  sys->win, (sys->window.size_x / 2 * 100) - 10, (sys->window.size_y / 2 * 100) + 20, 0xFFFF0000, "GAME OVER :(");
}

void	inicial_keycode(t_system *sys)
{		
	mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[GROUND].img, 0, 0);
	mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[WALL].img, 0, 0);
	
	mlx_string_put(sys->mlx, sys->win, 10, 15, 0xFFFF00FF, ft_itoa(sys->window.contador));
	mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[GROUND].img, sys->window.map.x, sys->window.map.y);
}

void	movements(int keycode, t_system *sys)
{
	if (sys->window.map.x == sys->window.exi.x && sys->window.map.y == sys->window.exi.y)
		mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[EXIT].img, sys->window.map.x, sys->window.map.y);
	if (keycode == BEHIND || keycode == KEY_DOWN)
	{
		sys->window.map.y = sys->window.map.y + 100;
		sys->imgs[PLAYER].img = mlx_xpm_file_to_image(sys->mlx, "xpm/PlayerFront.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].whidth);
	}
	if (keycode == FRONT || keycode == KEY_UP)
	{
		sys->imgs[PLAYER].img = mlx_xpm_file_to_image(sys->mlx, "xpm/PlayerBehind.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].whidth);
		sys->window.map.y = sys->window.map.y - 100;
	}
	if (keycode == RIGHT || keycode == KEY_RIGHT)
	{
		sys->imgs[PLAYER].img = mlx_xpm_file_to_image(sys->mlx, "xpm/PlayerRight.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].whidth);
		sys->window.map.x = sys->window.map.x + 100;
	}
	if (keycode == LEFT || keycode == KEY_LEFT)
	{
		sys->imgs[PLAYER].img = mlx_xpm_file_to_image(sys->mlx, "xpm/PlayerLeft.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].whidth);
		sys->window.map.x = sys->window.map.x - 100;
	}
}

void loose_condition(t_system *sys)
{
	int	j;

	j = 0;
	while (j < sys->window.enemies)
	{
		if (sys->window.map.x == sys->window.enemy[j].x && sys->window.map.y == sys->window.enemy[j].y)
		{
			write(1, "Game Over\n", 10);
			print_game_over(sys);
			sys->window.loose = 1;
		}
		j++;
	}
}

void	win_condition(t_system *sys)
{
	int	i;
	int	j;

	sys->imgs[GREEN].img = mlx_xpm_file_to_image(sys->mlx, "xpm/Green.xpm", &sys->imgs[GROUND].whidth, &sys->imgs[GROUND].whidth);
	if ((sys->window.map.x == sys->window.exi.x && sys->window.map.y == sys->window.exi.y) && sys->window.colecion == 0)
	{
		i = 0;
		j = 0;
		sys->window.win = 1;
		while (i < sys->window.size_x * 100)
		{
			while (j < sys->window.size_y * 100)
			{
				mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[GREEN].img, i, j);
				j += 100;
			}
			j = 0;
			i += 100;
		}
	}
}

void	ft_exit(void)
{
	exit(0);
}

void	hit_walls(int keycode, t_system *sys)
{
	int	i;

	i = 0;
	while (i < sys->window.walls)
	{
		sys->window.contador++;
		
		if(sys->window.map.x == sys->window.wall[i].x && sys->window.map.y == sys->window.wall[i].y)
		{
			if (keycode == BEHIND || keycode == KEY_DOWN)
				sys->window.map.y = sys->window.map.y - 100;	
			if (keycode == FRONT || keycode == KEY_UP)
				sys->window.map.y = sys->window.map.y + 100;
			if (keycode == RIGHT || keycode == KEY_RIGHT)
				sys->window.map.x = sys->window.map.x - 100;
			if (keycode == LEFT || keycode == KEY_LEFT)
				sys->window.map.x = sys->window.map.x + 100;
			sys->window.contador--;
		}
		i++;
	}
}

void	colect(int keycode, t_system *sys)
{
	int i = 0;
		while (i < sys->window.coins)
		{
			if(sys->window.map.x == sys->window.colect[i].x && sys->window.map.y == sys->window.colect[i].y)
			{
				sys->window.colect[i].x = 0;
				sys->window.colect[i].y = 0;
				sys->window.colecion--;
				mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[GROUND].img, sys->window.map.x, sys->window.map.y);
				break ;
			}
			i++;
		}
		if(sys->window.loose == 0 || sys->window.win == 0)
		{
			hit_walls(keycode, sys);
				mlx_put_image_to_window(sys->mlx, sys->win, sys->imgs[PLAYER].img, sys->window.map.x, sys->window.map.y);
		}
}

int	ft_key_hook(int keycode, t_system *sys)
{	
	if(sys->window.loose == 1 || sys->window.win == 1)
		exit(0);	
	inicial_keycode(sys);
	
	movements(keycode, sys);
	
	if (keycode == KEY_ESC)
	{
		print_game_over(sys);
		sys->window.loose = 1;
	}
	loose_condition(sys);
	win_condition(sys);
	colect(keycode, sys);
	
	return (0);
}