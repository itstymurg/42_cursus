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

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

# define PLAYER P
# define COLECIONABLE C
# define EXIT E
# define WEAPON W
# define ENEMY N
# define WALL 1
# define PATH 0

# define FRONT 13
# define BEHIND 1
# define RIGHT 2
# define LEFT 0

typedef struct s_system
{
	void	*mlx;
	void	*win;
}t_system;

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
	t_box	map;
	t_box	colect[20];
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

int	ft_key_hook(int keycode, t_system *sys, t_window *window);

#endif
