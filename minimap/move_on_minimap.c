#include "../cub3d.h"

//==================BROKEN==================-
/* // Returns 1 if next to a wall, 0 otherwise
bool	near_wall(t_game *game, t_dir dir)
{
	int	x;
	int	y;

	x = game->plr.pos_x;
	y = game->plr.pos_y;
	if (dir == NORTH)
		x = game->plr.pos_x - 0.1;
	else if (dir == SOUTH)
		x = game->plr.pos_x + 0.1;
	else if (dir == WEST)
		y = game->plr.pos_y - 0.1;
	else if (dir == EAST)
		y = game->plr.pos_y + 0.1;
	if (game->map.grid[x][y] == '1')
		return (1);
	return (0);
} */

// void	strafe_right_minimap(t_game *game)
// {
// 	float	new_x;
// 	float	new_y;

// 	new_x = GMM.pos_x + (GMM.ray_y * GMM.move_speed);
// 	new_y = GMM.pos_y - (GMM.ray_x * GMM.move_speed);
// 	if (new_x >= 0 && new_x < GM.map_h && new_y >= 0 && new_y < GM.map_l)
// 	{
// 		if (GM.grid[(int)new_x][(int)new_y] != '1')
// 		ft_printf(MAGENTA"___x=%d, y=%d___\n"NO_ALL, (int)new_x, (int)new_y);/////////////////
// 		{
// 			ft_padding(game, 0xFFFFFF, GMM.pos_x, GMM.pos_y);
// 			GMM.pos_x = new_x;
// 			GMM.pos_y = new_y;
// 			ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
// 		}
// 	}
// }

// void	strafe_left_minimap(t_game *game)
// {
// 	float	new_x;
// 	float	new_y;

// 	new_x = GMM.pos_x - (GMM.ray_y * GMM.move_speed);
// 	new_y = GMM.pos_y + (GMM.ray_x * GMM.move_speed);
// 	if (new_x >= 0 && new_x < GM.map_h && new_y >= 0 && new_y < GM.map_l)
// 	{
// 		if (GM.grid[(int)new_x][(int)new_y] != '1')
// 		ft_printf(MAGENTA"___x=%d, y=%d___\n"NO_ALL, (int)new_x, (int)new_y);/////////////////
// 		{
// 			ft_padding(game, 0xFFFFFF, GMM.pos_x, GMM.pos_y);
// 			GMM.pos_x = new_x;
// 			GMM.pos_y = new_y;
// 			ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
// 		}
// 	}
// }

// void	move_front_minimap(t_game *game)
// {
// 	float	new_x;
// 	float	new_y;

// 	new_x = GMM.pos_x + (GMM.ray_x * GMM.move_speed);
// 	new_y = GMM.pos_y + (GMM.ray_y * GMM.move_speed);
// 	if (new_x >= 0 && new_x < GM.map_h && new_y >= 0 && new_y < GM.map_l)
// 	{
// 		if (GM.grid[(int)new_x][(int)new_y] != '1')
// 		ft_printf(MAGENTA"___x=%d, y=%d___\n"NO_ALL, (int)new_x, (int)new_y);/////////////////
// 		{
// 			ft_padding(game, 0xFFFFFF, GMM.pos_x, GMM.pos_y);
// 			GMM.pos_x = new_x;
// 			GMM.pos_y = new_y;
// 			ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
// 		}
// 	}
// }

// void	move_back_minimap(t_game *game)
// {
// 	float	new_x;
// 	float	new_y;

// 	new_x = GMM.pos_x - (GMM.ray_x * GMM.move_speed);
// 	new_y = GMM.pos_y - (GMM.ray_y * GMM.move_speed);
// 	if (new_x >= 0 && new_x < GM.map_h && new_y >= 0 && new_y < GM.map_l)
// 	{
// 		if (GM.grid[(int)new_x][(int)new_y] != '1')
// 		ft_printf(MAGENTA"___x=%d, y=%d___\n"NO_ALL, (int)new_x, (int)new_y);/////////////////
// 		{
// 			ft_padding(game, 0xFFFFFF, GMM.pos_x, GMM.pos_y);
// 			GMM.pos_x = new_x;
// 			GMM.pos_y = new_y;
// 			ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
// 		}
// 	}
// }

// rotate the player icon (WIP)
void	rotate_right_minimap(t_game *game)
{
	float	old_ray_x;

	old_ray_x = GMM.ray_x;
	GMM.ray_x = GMM.ray_x * cos(-GMM.rot_speed) - GMM.ray_y * sin(-GMM.rot_speed);
	GMM.ray_y = old_ray_x * sin(-GMM.rot_speed) + GMM.ray_y * cos(-GMM.rot_speed);
	// ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
}

// rotate the player icon (WIP)
void	rotate_left_minimap(t_game *game)
{
	float	old_ray_x;

	old_ray_x = GMM.ray_x;
	GMM.ray_x = GMM.ray_x * cos(GMM.rot_speed) - GMM.ray_y * sin(GMM.rot_speed);
	GMM.ray_y = old_ray_x * sin(GMM.rot_speed) + GMM.ray_y * cos(GMM.rot_speed);
	// ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
}

void	move_on_minimap(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{
		// if (near_wall(game, NORTH))
		// 	return ;
		move_front(game);
		execute_algorithm(game);
		render_minimap(game);
		// move_front_minimap(game);
		// mlx_do_sync(GW.mlx_ptr);
		// mlx_put_image_to_window(GW.mlx_ptr, GW.win_ptr, GW.nimg, 0, 0);
		printf(YELLOW"posx:%f, minim-posx:%f\n"NO_ALL, GP.pos_x, GMM.pos_x);/////////////////////////////
		printf(YELLOW"posy:%f, minim-posy:%f\n"NO_ALL, GP.pos_y, GMM.pos_y);/////////////////////////////
	}
	else if (keysym == XK_s)
	{
		// if (near_wall(game, SOUTH))
		// 	return ;
		move_back(game);
		execute_algorithm(game);
		render_minimap(game);
		// move_back_minimap(game);
		// mlx_do_sync(GW.mlx_ptr);
		// mlx_put_image_to_window(GW.mlx_ptr, GW.win_ptr, GW.nimg, 0, 0);
		printf(YELLOW"posx:%f, minim-posx:%f\n"NO_ALL, GP.pos_x, GMM.pos_x);/////////////////////////////
		printf(YELLOW"posy:%f, minim-posy:%f\n"NO_ALL, GP.pos_y, GMM.pos_y);/////////////////////////////
	}
	else if (keysym == XK_a)
	{
		// if (near_wall(game, WEST))
		// 	return ;
		strafe_left(game);
		execute_algorithm(game);
		render_minimap(game);
		// strafe_left_minimap(game);
		// mlx_do_sync(GW.mlx_ptr);
		// mlx_put_image_to_window(GW.mlx_ptr, GW.win_ptr, GW.nimg, 0, 0);
		printf(YELLOW"posx:%f, minim-posx:%f\n"NO_ALL, GP.pos_x, GMM.pos_x);/////////////////////////////
		printf(YELLOW"posy:%f, minim-posy:%f\n"NO_ALL, GP.pos_y, GMM.pos_y);/////////////////////////////
	}
	else if (keysym == XK_d)
	{
		// if (near_wall(game, EAST))
		// 	return ;
		strafe_right(game);
		execute_algorithm(game);
		render_minimap(game);
		// strafe_right_minimap(game);
		// mlx_do_sync(GW.mlx_ptr);
		// mlx_put_image_to_window(GW.mlx_ptr, GW.win_ptr, GW.nimg, 0, 0);
		printf(YELLOW"posx:%f, minim-posx:%f\n"NO_ALL, GP.pos_x, GMM.pos_x);/////////////////////////////
		printf(YELLOW"posy:%f, minim-posy:%f\n"NO_ALL, GP.pos_y, GMM.pos_y);/////////////////////////////
	}
	else if (keysym == XK_Right || keysym == XK_e)
	{
		// if (near_wall(game, EAST))
		// 	return ;
		rotate_right(game);
		execute_algorithm(game);
		render_minimap(game);
		// rotate_right_minimap(game);
		// rotate_right_minimap(game);
		// mlx_do_sync(GW.mlx_ptr);
		// mlx_put_image_to_window(GW.mlx_ptr, GW.win_ptr, GW.nimg, 0, 0);
	}
	else if (keysym == XK_Left || keysym == XK_q)
	{
		// if (near_wall(game, EAST))
		// 	return ;
		rotate_left(game);
		execute_algorithm(game);
		render_minimap(game);
		// rotate_left_minimap(game);
		// rotate_left_minimap(game);
		// mlx_do_sync(GW.mlx_ptr);
		// mlx_put_image_to_window(GW.mlx_ptr, GW.win_ptr, GW.nimg, 0, 0);
	}
}
