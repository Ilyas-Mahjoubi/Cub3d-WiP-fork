#ifndef CUB3D_H
# define CUB3D_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>
# include <readline/readline.h>
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MACROS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~~*/
# define NO_ALL "\033[0m"

# define NO_COLOR "\e[39m"
# define BLACK "\e[30m"
# define RED "\033[31m"
# define GREEN "\e[32m"
# define BRGREEN "\033[32;1m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[95m"
# define BRCYAN "\033[96m"

/*~~~~~~~~~~~~BACKGROUNDS~~~~~~~~~~~~~*/
# define BGMAGENTA "\033[45m"
# define BLACK_ON_WHITE "\e[107;30m"
# define NO_BG "\e[49m"

/*~~~~~~~~~~~~~~~~MORE~~~~~~~~~~~~~~~~*/
# define BOLD "\e[1m"// "\e[1;4m" Bold and Underlined
# define NO_BOLD "\e[21m"

# define UNDERLINE "\e[4m"
# define NO_UNDERLINE "\e[24m"

# define BLINK "\e[5m"
# define NO_BLINK "\e[25m"

# define HIDE "\e[8m"
# define NO_HIDE "\e[28m"

/*~~~~~~~~~~~~~~~~VARs~~~~~~~~~~~~~~~~*/
// to be switched with dynamic map sizes
# define WINWIDTH 1820
# define WINHEIGHT 920

/*~~~~~~~~~~~~ABBREVIATIONS~~~~~~~~~~~~*/
# define GM game->map
# define GP game->plr
# define GW game->win
# define GMM game->minimap

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*+++++++++++++++++++++++++++++++++++STRUCTS+++++++++++++++++++++++++++++++++*/

typedef enum	s_dir
{
	MISSING,
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_dir;

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*nimg;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_win;

typedef struct	s_player
{
	int		p_dir;//	Players starting facing direction.
	float	pos_x;//	Current player position(line)
	float	pos_y;// 	Current player position (column)
	float	ray_x;
	float	ray_y;
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_x;
	float	delta_y;
	float	dist_x;
	float	dist_y;
	float	perp_wall_dist;
	float	move_speed;
	float	rot_speed;
}	t_player;

typedef struct	s_map
{
	char	*n_txtr;//	Path to North wall texture
	char	*s_txtr;//	Path to South wall texture
	char	*e_txtr;//	Path to East wall texture
	char	*w_txtr;//	Path to West wall texture
	int		fcol;//		Floor color
	int		ccol;//		Ceiling color
	char	**grid;
	size_t	map_h;//	Map hight
	size_t	map_l;//	Map width (longest line)
	int		n_players;
	float	plane_x;
	float	plane_y;
	float	camera_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		wall_height;
	int		x;
	int 	draw_start;
	int 	draw_end;
	int		hex_color;
}	t_map;

typedef struct	s_minimap
{
	float	pos_x;
	float	pos_y;
	float	ray_x;
	float	ray_y;
	float	move_speed;
	float	rot_speed;
	bool	sync_with_player;
}	t_minimap;

typedef struct	s_game
{
	t_win		win;
	t_map		map;
	t_player	plr;
	t_minimap	minimap;
	int			scale;
	bool		keys[256];
}	t_game;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*____________________________________hooks.c________________________________*/
void	ft_hooks(t_game	*game);
int		on_destroy(t_game *game);

/*____________________________________parsing________________________________*/
bool	parse_map_file(char *mapfile, t_map *map, t_player *plr);
bool	parse_textures(t_map *map, char **str, int fd);
bool	set_map_textures(t_map *map, char *str);
int		get_color(char *str);
int		rgb_to_int(int r, int g, int b);
bool	check_getcolor_fail(t_map *map, char *str);
bool	isprint_iter(char *str);
bool	parse_map(t_map *map, char **str, int fd);
bool	isvalid_chr(char *str);
bool	copy_map(t_map *map, char *str, int fd);
bool	valid_map(t_map *map, char **grid);
bool	check_map_struct(t_map *map);

/*___________________________________minimap.c_______________________________*/
void	render_minimap(t_game *game);
void	ft_padding(t_game *game, int color, float x, float y);

/*_______________________________move_on_minimap.c___________________________*/
void	move_on_minimap(int keysym, t_game *game);
void	sync_minimap_with_player(t_game *game);
void	sync_player_with_minimap(t_game *game);
void	toggle_minimap_sync(t_game *game);
void	strafe_right_minimap(t_game *game);
void	strafe_left_minimap(t_game *game);
void	move_front_minimap(t_game *game);
void	move_back_minimap(t_game *game);
void	rotate_right_minimap(t_game *game);
void	rotate_left_minimap(t_game *game);

/*___________________________________free_mem________________________________*/
void	free_mapstruct(t_map *map);

/*____________________________________time_calc_______________________________*/
float	get_current_time(void);
void    get_fps(t_game *game);

/*____________________________________wall_calc_______________________________*/
void	get_wall_height(t_game *game);
void	draw_ver_line(t_game *game, int x);

/*____________________________________ray_calc________________________________*/
void    execute_algorithm(t_game *game);

/*____________________________________init____________________________________*/
void    initialize_player(t_game *game);
void	initialize_all(t_game *game);
void	initialize_minimap(t_game *game);
void	setup_player_direction(t_game *game);

/*____________________________________movement____________________________________*/
void    move_front(t_game *game);
void    move_back(t_game *game);
void    strafe_right(t_game *game);
void    strafe_left(t_game *game);
void    rotate_right(t_game *game);
void    rotate_left(t_game *game);

#endif