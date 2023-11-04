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

#ifndef SO_LONG_H
# define SO_LONG_H

# include <time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"

# define GROUND 3
# define COIN 4
# define PLAYER 5
# define WALL 6
# define EXIT 7
# define ENEMY 8
# define BLACK 9
# define ENEMY1 10
# define ENEMY2 11
# define ENEMY3 12
# define ENEMY4 13
# define ENEMY5 14
# define ENEMY6 15
# define ENEMY7 16
# define ENEMY8 17
# define ENEMY9 18
# define GREEN 19

# define PATH 0

# define FRONT 13
# define BEHIND 1
# define RIGHT 2
# define LEFT 0
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define KEY_ESC 53



typedef struct s_box
{
	int		x;
	int		y;
	char	action;
}t_box;

typedef struct s_window
{
	int		size_x;
	int		size_y;
	int		colecion;
	int		player;
	int		ex;
	int		walls;
	int		enemies;
	t_box	exi;
	t_box	map;
	t_box	colect[1000];
	t_box	wall[1000];
	t_box	enemy[200];
	int		loose;
	int		win;
	int		coins;
	int		contador;
}t_window;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		whidth;
	int		height;
	int		endian;
	int		line_length;
}t_data;

typedef struct s_system
{
	void		*mlx;
	void		*win;
	t_window	window;
	t_data		imgs[200];
}t_system;

int		ft_key_hook(int keycode, t_system *sys);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);
size_t	ft_strlen(char *str);
void	print_game_over(t_system *sys);
void	win_condition(t_system *sys);

#endif
