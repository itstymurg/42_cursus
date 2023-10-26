#include "so_long.h"

int	ft_key_hook(int keycode, t_system *sys, t_window *window)
{
	t_data player;
	printf("(%d-%d)\n",  window->map.x, window->map.y);

	if (keycode == BEHIND)
	{
		player.img = mlx_xpm_file_to_image(sys->mlx, "xpm/PlayerFront.xpm", &window->map.x, &window->map.y);
		
	}
	if (keycode == FRONT)
	{
		player.img = mlx_xpm_file_to_image(sys->mlx, "xpm/PlayerBehind.xpm", &window->map.x, &window->map.y);
	}
	if (keycode == RIGHT)
	{
		player.img = mlx_xpm_file_to_image(sys->mlx, "xpm/PlayerRight.xpm", &window->map.x, &window->map.y);
	}
	if (keycode == LEFT)
	{
		player.img = mlx_xpm_file_to_image(sys->mlx, "xpm/PlayerLeft.xpm", &window->map.x, &window->map.y);
	}
	printf("\n\n%d-%d\n\n",  window->map.x, window->map.y);
	mlx_put_image_to_window(sys->mlx, sys->win, player.img, window->map.x, window->map.y);
	printf("\n\n%d-%d\n\n",  window->map.x, window->map.y);
	
	return (0);
}