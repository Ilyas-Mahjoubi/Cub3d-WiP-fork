#include "./cub3d.h"

int on_destroy(t_game *game)
{
	mlx_destroy_image(game->win.mlx_ptr, game->win.nimg);
	mlx_destroy_window(game->win.mlx_ptr, game->win.win_ptr);
	mlx_destroy_display(game->win.mlx_ptr);
	free(game->win.mlx_ptr);
	free_mapstruct(&game->map);
	exit(0);
}

void	ft_moveplayer(int keysym, t_game *game)
{
	// if (keysym == XK_w)
	// 	move_front(game);
	// else if (keysym == XK_s)
	// 	move_behind(game);
	// else if (keysym == XK_a)
	// 	strafe_left(game);
	// else if (keysym == XK_d)
	// 	strafe_right(game);
	// else if (keysym == XK_Left)
	// 	rotate_left(game);
	// else if (keysym == XK_Right)
	// 	rotate_right(game);
	render_minimap(game);
	move_on_minimap(keysym, game);
	// execute_algorithm(game);
	mlx_put_image_to_window(game->win.mlx_ptr, game->win.win_ptr, game->win.nimg, 0, 0);
}

static int	on_keypress(int keysym, t_game *game)
{
	(void)game;
	if (keysym == XK_Escape)
		on_destroy(game);
	else if (keysym == XK_d || keysym == XK_a || keysym == XK_w || \
					keysym == XK_s || keysym == XK_e || keysym == XK_q || \
					keysym == XK_Left || keysym == XK_Right)
		ft_moveplayer(keysym, game);
	return (1);
}

void	ft_hooks(t_game *game)
{
	mlx_hook(game->win.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, game);
	mlx_hook(game->win.win_ptr, 2, 1L << 0,
		&on_keypress, game);
}
