#include "./cub3d.h"

/*
	MOVIMENTO DEL PLAYER MANCANTE
*/

void    move_front(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = GP.pos_x + (GP.ray_x * GP.move_speed);
	new_y = GP.pos_y + (GP.ray_y * GP.move_speed);
	if (!(new_x >= 0 && new_x < GM.map_h && 
		(int)GP.pos_y >= 0 && (int)GP.pos_y < (int)GM.map_l &&
		GM.grid[(int)new_x]))
	{
		return ;
	}
	if (!(new_y >= 0 && new_y < GM.map_l &&
		(int)GP.pos_x >= 0 && (int)GP.pos_x < (int)GM.map_h &&
		GM.grid[(int)GP.pos_x]))
	{
		return ;
	}
	if (GM.grid[(int)new_x][(int)GP.pos_y] != '1')
		GP.pos_x = new_x;
	if (GM.grid[(int)GP.pos_x][(int)new_y] != '1')
		GP.pos_y = new_y;
	printf("Move front: pos(%.2f, %.2f)\n", GP.pos_x, GP.pos_y);
}

void	move_back(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = GP.pos_x - (GP.ray_x * GP.move_speed);
	new_y = GP.pos_y - (GP.ray_y * GP.move_speed);
	if (!(new_x >= 0 && new_x < GM.map_h && 
		(int)GP.pos_y >= 0 && (int)GP.pos_y < (int)GM.map_l &&
		GM.grid[(int)new_x]))
	{
		return ;
	}
	if (!(new_y >= 0 && new_y < GM.map_l &&
		(int)GP.pos_x >= 0 && (int)GP.pos_x < (int)GM.map_h &&
		GM.grid[(int)GP.pos_x]))
	{
		return ;
	}
	if (GM.grid[(int)new_x][(int)GP.pos_y] != '1')
		GP.pos_x = new_x;
	if (GM.grid[(int)GP.pos_x][(int)new_y] != '1')
		GP.pos_y = new_y;
	printf("Move back: pos(%.2f, %.2f)\n", GP.pos_x, GP.pos_y);
}

void	strafe_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = GP.pos_x + (GP.ray_y * GP.move_speed);
	new_y = GP.pos_y - (GP.ray_x * GP.move_speed);
	if (!(new_x >= 0 && new_x < GM.map_h && 
		(int)GP.pos_y >= 0 && (int)GP.pos_y < (int)GM.map_l &&
		GM.grid[(int)new_x]))
	{
		return ;
	}
	if (!(new_y >= 0 && new_y < GM.map_l &&
		(int)GP.pos_x >= 0 && (int)GP.pos_x < (int)GM.map_h &&
		GM.grid[(int)GP.pos_x]))
	{
		return ;
	}
	if (GM.grid[(int)new_x][(int)GP.pos_y] != '1')
		GP.pos_x = new_x;
	if (GM.grid[(int)GP.pos_x][(int)new_y] != '1')
		GP.pos_y = new_y;
	printf("Strafe right: pos(%.2f, %.2f)\n", GP.pos_x, GP.pos_y);
}

void	strafe_left(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = GP.pos_x - (GP.ray_y * GP.move_speed);
	new_y = GP.pos_y + (GP.ray_x * GP.move_speed);
	if (!(new_x >= 0 && new_x < GM.map_h && 
		(int)GP.pos_y >= 0 && (int)GP.pos_y < (int)GM.map_l &&
		GM.grid[(int)new_x]))
	{
		return ;
	}
	if (!(new_y >= 0 && new_y < GM.map_l &&
		(int)GP.pos_x >= 0 && (int)GP.pos_x < (int)GM.map_h &&
		GM.grid[(int)GP.pos_x]))
	{
		return ;
	}
	if (GM.grid[(int)new_x][(int)GP.pos_y] != '1')
		GP.pos_x = new_x;
	if (GM.grid[(int)GP.pos_x][(int)new_y] != '1')
		GP.pos_y = new_y;
	printf("Strafe left: pos(%.2f, %.2f)\n", GP.pos_x, GP.pos_y);
}

void	rotate_right(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;
	
	old_ray_x = GP.ray_x;
	old_plane_x = GM.plane_x;
	GP.ray_x = GP.ray_x * cos(-GP.rot_speed) - GP.ray_y * sin(-GP.rot_speed);
	GP.ray_y = old_ray_x * sin(-GP.rot_speed) + GP.ray_y * cos(-GP.rot_speed);
	GM.plane_x = GM.plane_x * cos(-GP.rot_speed) - GM.plane_y * sin(-GP.rot_speed);
	GM.plane_y = old_plane_x * sin(-GP.rot_speed) + GM.plane_y * cos(-GP.rot_speed);
	printf("Rotate left: ray(%.2f, %.2f)\n", GP.ray_x, GP.ray_y);
}

void	rotate_left(t_game *game)
{
	float	old_ray_x;
	float	old_plane_x;
	
	old_ray_x = GP.ray_x;
	old_plane_x = GM.plane_x;
	GP.ray_x = GP.ray_x * cos(GP.rot_speed) - GP.ray_y * sin(GP.rot_speed);
	GP.ray_y = old_ray_x * sin(GP.rot_speed) + GP.ray_y * cos(GP.rot_speed);
	GM.plane_x = GM.plane_x * cos(GP.rot_speed) - GM.plane_y * sin(GP.rot_speed);
	GM.plane_y = old_plane_x * sin(GP.rot_speed) + GM.plane_y * cos(GP.rot_speed);
	printf("Rotate right: ray(%.2f, %.2f)\n", GP.ray_x, GP.ray_y);
}
