#include "./cub3d.h"

void    get_ray_derivates(t_game *game)
{
	GM.map_x = (int)GP.pos_x;
	GM.map_y = (int)GP.pos_y;
	GM.camera_x = 2 * GM.x / (double)WINWIDTH - 1;
	GP.ray_dir_x = GP.ray_x + GM.plane_x * GM.camera_x;
	GP.ray_dir_y = GP.ray_y + GM.plane_y * GM.camera_x;
	if (GP.ray_dir_x == 0)
		GP.delta_x = 1e30;
	else
		GP.delta_x = fabs(1 / GP.ray_dir_x);
		
	if (GP.ray_dir_y == 0)
		GP.delta_y = 1e30;
	else
		GP.delta_y = fabs(1 / GP.ray_dir_y);
}

void	calculate_nearest_coords(t_game *game)
{
	if (GP.ray_dir_x < 0)
	{
		GM.step_x = -1;
		GP.dist_x = (GP.pos_x - GM.map_x) * GP.delta_x;
	}
	else
	{
		GM.step_x = 1;
		GP.dist_x = ((float)GM.map_x + 1.0 - GP.pos_x) * GP.delta_x;
	}
	if (GP.ray_dir_y < 0)
	{
		GM.step_y = -1;
		GP.dist_y = (GP.pos_y - GM.map_y) * GP.delta_y;
	}
	else
	{
		GM.step_y = 1;
		GP.dist_y = ((float)GM.map_y + 1.0 - GP.pos_y) * GP.delta_y;
	}
}

void	get_next_position(t_game *game)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (GP.dist_x < GP.dist_y)
		{
			if ((GM.map_x + GM.step_x) < 0 || (GM.map_x + GM.step_x) >= (int)GM.map_h)/* || (GM.map_y) < 0 || (GM.map_y) >= (int)GM.map_l */
				return ;
			GM.map_x += GM.step_x;
			GP.dist_x += GP.delta_x;
			GM.side = 0;
		}
		else
		{
			if ((GM.map_y + GM.step_y) < 0 || (GM.map_y + GM.step_y) >= (int)GM.map_l)
				return ;
			GM.map_y += GM.step_y;
			GP.dist_y += GP.delta_y;
			GM.side = 1;
		}
		if (GM.grid[GM.map_x] && GM.grid[GM.map_x][GM.map_y] == '1')
			hit = 1;
	}
}

void    execute_algorithm(t_game *game)
{
	int     i;
	double  time;

	i = -1;
	time = get_current_time();
	while (++i < WINWIDTH)
	{
		GM.x = i;
		get_ray_derivates(game);
		calculate_nearest_coords(game);
		get_next_position(game);
		if (GM.side)
			GP.perp_wall_dist = GP.dist_y - GP.delta_y;
		else
			GP.perp_wall_dist = GP.dist_x - GP.delta_x;
		draw_ver_line(game, i);
	}
	mlx_put_image_to_window(GW.mlx_ptr, GW.win_ptr, GW.nimg, 0, 0);
}
	