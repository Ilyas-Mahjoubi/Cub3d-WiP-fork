#include "../cub3d.h"

// Colors the main pixel and fills the space around it.
void	ft_padding(t_game *game, int color, float x, float y)
{
	int	px;
	int	py;
	int	pixel_index;

	// Add bounds checking
	if (x < 0 || x >= GM.map_h || y < 0 || y >= GM.map_l)
		return;

	py = 0;
	while (py < game->scale)
	{
		px = 0;
		while (px < game->scale)
		{
			int pixel_x = (int)(y * game->scale + px);  // Note: y comes first for X coordinate
			int pixel_y = (int)(x * game->scale + py);  // Note: x comes first for Y coordinate

			// Check if within window bounds
			if (pixel_x >= 0 && pixel_x < WINWIDTH && pixel_y >= 0 && pixel_y < WINHEIGHT)
			{
				pixel_index = (pixel_y * game->win.line_len) + \
							(pixel_x * (game->win.bits_per_pixel / 8));
				*(unsigned int*)(game->win.addr + pixel_index) = color;
			}
			px++;
		}
		py++;
	}
}

// Determines the pixel's color.
static int	pick_color(t_game *game, size_t i, size_t j)
{
	if (game->map.grid[i][j] == 'N' || game->map.grid[i][j] == 'S' \
				|| game->map.grid[i][j] == 'E' || game->map.grid[i][j] == 'W')
		return (0xFFFFFF);//0xFF0000 red
	else if (game->map.grid[i][j] == '0')
		return (0xFFFFFF);
	else if (game->map.grid[i][j] == '1')
		return (0x000000);
	else
		return (-1);
}

// void	render_minimap(t_game *game)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		color;

// 	printf("DEBUG 1: Starting render_minimap\n");
// 	printf("DEBUG: Map dimensions: %zu x %zu\n", GM.map_h, GM.map_l);
// 	printf("DEBUG: Player position: %.2f, %.2f\n", GP.pos_x, GP.pos_y);

// 	// Check if grid exists
// 	if (!GM.grid)
// 	{
// 		printf("ERROR: GM.grid is NULL!\n");
// 		return;
// 	}

// 	i = 0;
// 	while (i < game->map.map_h)
// 	{
// 		if (!GM.grid[i])
// 		{
// 			printf("ERROR: GM.grid[%zu] is NULL!\n", i);
// 			i++;
// 			continue;
// 		}

// 		j = 0;
// 		while (j < ft_strlen(game->map.grid[i]))
// 		{
// 			color = pick_color(game, i, j);
// 			if (color < 0)
// 			{
// 				j++;
// 				continue ;
// 			}
// 			ft_padding(game, color, (float)i, (float)j);
// 			j++;
// 		}
// 		i++;
// 	}

// 	printf("DEBUG: Map rendered, now drawing player\n");

// 	// Sync both position AND direction vectors
// 	GMM.pos_x = GP.pos_x;
// 	GMM.pos_y = GP.pos_y;
// 	GMM.ray_x = GP.ray_x;
// 	GMM.ray_y = GP.ray_y;

// 	ft_padding(game, 0xFF0000, GMM.pos_x, GMM.pos_y);
// 	printf("DEBUG: render_minimap completed successfully\n");
// }

// // ADD THIS FUNCTION to show player direction
// void	draw_player_direction(t_game *game)
// {
// 	float	end_x, end_y;
// 	int		i;
// 	int		px, py;
// 	int		pixel_index;

// 	// Simple: draw 2-3 pixels in the direction
// 	for (i = 1; i <= 2; i++)
// 	{
// 		end_x = GMM.pos_x + (GMM.ray_x * 0.2f * i);
// 		end_y = GMM.pos_y + (GMM.ray_y * 0.2f * i);

// 		// Check bounds to avoid segmentation fault
// 		if (end_x < 0 || end_x >= GM.map_h || end_y < 0 || end_y >= GM.map_l)
// 			continue;

// 		// Draw a small dot at the end point
// 		for (py = 0; py < game->scale / 4 && py < game->scale; py++)
// 		{
// 			for (px = 0; px < game->scale / 4 && px < game->scale; px++)
// 			{
// 				// Calculate pixel position carefully
// 				int pixel_x = (int)(end_x * game->scale) + px;
// 				int pixel_y = (int)(end_y * game->scale) + py;

// 				// Check if within image bounds
// 				if (pixel_x >= 0 && pixel_x < WINWIDTH && pixel_y >= 0 && pixel_y < WINHEIGHT)
// 				{
// 					pixel_index = (pixel_y * game->win.line_len) + \
// 								(pixel_x * (game->win.bits_per_pixel / 8));
// 					*(unsigned int*)(game->win.addr + pixel_index) = 0x00FF00; // Green
// 				}
// 			}
// 		}
// 	}
// }

// // ADD THIS FUNCTION for line drawing
// void	draw_line(t_game *game, float x0, float y0, float x1, float y1, int color)
// {
// 	float	dx = fabs(x1 - x0);
// 	float	dy = fabs(y1 - y0);
// 	float	sx = (x0 < x1) ? 1 : -1;
// 	float	sy = (y0 < y1) ? 1 : -1;
// 	float	err = dx - dy;
// 	float	x = x0;
// 	float	y = y0;
// 	int		pixel_index;

// 	while (1)
// 	{
// 		// Draw pixel at (x, y)
// 		int px, py;
// 		for (py = 0; py < game->scale / 2; py++)
// 		{
// 			for (px = 0; px < game->scale / 2; px++)
// 			{
// 				pixel_index = ((x * game->scale + py) * game->win.line_len) + \
// 							((y * game->scale + px) * (game->win.bits_per_pixel / 8));
// 				*(unsigned int*)(game->win.addr + pixel_index) = color;
// 			}
// 		}

// 		if (x == x1 && y == y1)
// 			break;

// 		float e2 = 2 * err;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y += sy;
// 		}
// 	}
// }
