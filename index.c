#include "./cub3d.h"

void	sync_minimap_player(t_game *game)
{
	GMM.pos_x = GP.pos_x;
	GMM.pos_y = GP.pos_y;
	GMM.ray_x = GP.ray_x;
	GMM.ray_y = GP.ray_y;
}

int main(int argc, char **argv)
{
	t_game  game;
	int		i;
	
	i = 0;
	if (argc != 2)
		return (0);
	game = (t_game){0};
	game.scale = 10;// Fattore di distanziamento dei pixel della minimappa
	game.win.mlx_ptr = mlx_init();
	if (!game.win.mlx_ptr)
		return (0);
	game.win.win_ptr = mlx_new_window(game.win.mlx_ptr,
		WINWIDTH, WINHEIGHT, "cub3D");
	if (!game.win.win_ptr)
			return (0);
	initialize_all(&game);
	game.win.nimg = mlx_new_image(game.win.mlx_ptr, WINWIDTH, WINHEIGHT);
	game.win.addr = mlx_get_data_addr(game.win.nimg, &game.win.bits_per_pixel, \
		&game.win.line_len, &game.win.endian);
	//Alek u are preciuos and we love you a lot <3
	//if this was you leo, lets kis
	// (づ ￣ ³￣)づ
	// uwu
	if (parse_map_file(argv[1], &game.map, &game.plr) == 0)
	{
		mlx_destroy_image(game.win.mlx_ptr, game.win.nimg);
		mlx_destroy_window(game.win.mlx_ptr, game.win.win_ptr);
		mlx_destroy_display(game.win.mlx_ptr);
		free(game.win.mlx_ptr);
		return (1);
	}
	get_fps(&game);
	setup_player_direction(&game);
	sync_minimap_player(&game);
	execute_algorithm(&game);
	mlx_put_image_to_window(game.win.mlx_ptr, game.win.win_ptr, game.win.nimg, 0, 0);
	render_minimap(&game);
	ft_hooks(&game);
	mlx_loop(game.win.mlx_ptr);
}
