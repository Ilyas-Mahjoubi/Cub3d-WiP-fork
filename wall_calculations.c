#include "./cub3d.h"

void    get_wall_height(t_game *game)
{
	// printf("=======PERP WALL DIST: %f=======\n", GP.perp_wall_dist);
	if (GP.perp_wall_dist < 0.001)
		GP.perp_wall_dist = 0.001;
	GM.wall_height = WINHEIGHT / GP.perp_wall_dist;
	GM.draw_start = (-GM.wall_height / 2) + (WINHEIGHT / 2);
	if (GM.draw_start < 0)
		GM.draw_start = 0;
	GM.draw_end = (GM.wall_height / 2) + (WINHEIGHT / 2);
	if (GM.draw_end >= WINHEIGHT)
		GM.draw_end = WINHEIGHT - 1;
}

void    draw_ver_line(t_game *game, int x)
{
	int		y;
	char	*dest;

	get_wall_height(game);
	if (GM.grid[GM.map_x] && GM.grid[GM.map_x][GM.map_y])
	{
		if (GM.grid[GM.map_x][GM.map_y] == '1')
			GM.hex_color = 0x0000FF;
		else if (GM.grid[GM.map_x][GM.map_y] == '0')
			GM.hex_color = 0xFF0000;
		else
			GM.hex_color = 0xFFFF00;
	}
	else
		GM.hex_color = 0x000000;
	if (GM.side == 1)
		GM.hex_color = GM.hex_color / 2;
	y = -1;
	while (++y < GM.draw_start)
	{
		if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
		{
			dest = GW.addr + (y * GW.line_len + x * (GW.bits_per_pixel / 8));
			*(unsigned int*)dest = GM.ccol;
		}
	}
	y = GM.draw_start - 1;
	while (++y <= GM.draw_end)
	{
		if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
		{
			dest = GW.addr + (y * GW.line_len + x * (GW.bits_per_pixel / 8));
			*(unsigned int*)dest = GM.hex_color;
		}
	}
	y = GM.draw_end;
	while (++y < WINHEIGHT)
	{
		if (y >= 0 && y < WINHEIGHT && x >= 0 && x < WINWIDTH)
		{
			dest = GW.addr + (y * GW.line_len + x * (GW.bits_per_pixel / 8));
			*(unsigned int*)dest = 0x222222;
		}
	}
}
