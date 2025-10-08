#include "./cub3d.h"

float	get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

void    get_fps(t_game *game)
{
	float	old_time;
	float	time;
	float	frame_time;
	int		fps_value;
	char	*fps_string;

	old_time = 0;
	time = get_current_time();
	if (old_time > 0)
	{
		frame_time = (time - old_time) / 1000.0;
		if (frame_time > 0)
		{
			fps_value = (int)(1.0 / frame_time);
			fps_string = ft_itoa(fps_value);
			mlx_string_put(GW.mlx_ptr, GW.win_ptr,
				WINWIDTH - 5, WINHEIGHT - 5, 0xFF0000, fps_string);
			free(fps_string);
		}
	}
	old_time = time;
}
