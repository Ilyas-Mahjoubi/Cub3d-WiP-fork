#include "./cub3d.h"

void	check_plr_dir(t_game *game)
{
	if (game->plr.p_dir == NORTH)
	{
		game->plr.ray_x = -1;
		game->plr.ray_y = 0;
		game->map.plane_x = 0;
		game->map.plane_y = 0.66f;
	}
	else if (game->plr.p_dir == SOUTH)
	{
		game->plr.ray_x = 1;
		game->plr.ray_y = 0;
		game->map.plane_x = 0;
		game->map.plane_y = -0.66f;
	}
	else if (game->plr.p_dir == EAST)
	{
		game->plr.ray_x = 0;
		game->plr.ray_y = 1;
		game->map.plane_x = 0.66f;
		game->map.plane_y = 0;
	}
	else if (game->plr.p_dir == WEST)
	{
		game->plr.ray_x = 0;
		game->plr.ray_y = -1;
		game->map.plane_x = -0.66f;
		game->map.plane_y = 0;
	}
}

void    initialize_player(t_game *game)
{
	game->plr.pos_x = 0;
	game->plr.pos_y = 0;
	game->plr.delta_x = 0;
	game->plr.delta_y = 0;
	game->plr.dist_x = 0;
	game->plr.dist_y = 0;
	game->plr.move_speed = 0.1;
	game->plr.perp_wall_dist = 0;
	game->plr.ray_dir_x = 0;
	game->plr.ray_dir_y = 0;
	game->plr.rot_speed = 0.04;
	check_plr_dir(game);
}

void    initialize_map(t_game *game)
{
	// game->map.n_txtr = NULL; INIZIALIZZATI NEL PARSING
	// game->map.s_txtr = NULL;
	// game->map.e_txtr = NULL;
	// game->map.w_txtr = NULL;
	// game->map.fcol = -1;
	// game->map.ccol = -1;
	// game->map.grid = NULL;
	// game->map.map_h = 0;
	// game->map.map_l = 0;
	// game->map.n_players = 0;
	game->map.plane_x = 0.0f;
	game->map.plane_y = 0.66f;
	game->map.camera_x = 0.0f;
	game->map.map_x = 0;
	game->map.map_y = 0;
	game->map.step_x = 0;
	game->map.step_y = 0;
	game->map.side = 0;
	game->map.wall_height = 0;
	game->map.x = 0;
	game->map.draw_start = 0;
	game->map.draw_end = 0;
	game->map.hex_color = 0;
}

////////////////////////////////////////////
void	setup_player_direction(t_game *game)
{
	printf("player direction: %d, pos (%f, %f)\n", game->plr.p_dir, game->plr.pos_x, game->plr.pos_y);
	check_plr_dir(game);
	printf("ray direction set to (%f, %f)\n", game->plr.ray_x, game->plr.ray_y);
	printf("plane direction set to (%f, %f)\n", game->map.plane_x, game->map.plane_y);
}
////////////////////////////////////////////

void	initialize_minimap(t_game *game)
{
	GMM.pos_x = GP.pos_x;
	GMM.pos_y = GP.pos_y;
	GMM.ray_x = GP.ray_x;
	GMM.ray_y = GP.ray_y;
	GMM.move_speed = 0.15f;
	GMM.rot_speed = 0.12f;
	// GMM.sync_with_player = true;
	printf("minimap initialized @ pos(%.2f, %.2f), ray(%.2f, %.2f)\n", GMM.pos_x, GMM.pos_y, GMM.ray_x, GMM.ray_y);
}

void    initialize_all(t_game *game)
{
	int	i;
	
	initialize_player(game);
	initialize_map(game);
	initialize_minimap(game);
	i = 0;
	while (i < 256)
	{
		game->keys[i] = false;
		i++;
	}
}
