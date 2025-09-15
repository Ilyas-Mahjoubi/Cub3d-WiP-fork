#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <stdbool.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
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

/*~~~~~~~~~~~~~~~MORE~~~~~~~~~~~~~~~*/
# define BOLD "\e[1m"// "\e[1;4m" Bold and Underlined
# define NO_BOLD "\e[21m"

# define UNDERLINE "\e[4m"
# define NO_UNDERLINE "\e[24m"

# define BLINK "\e[5m"
# define NO_BLINK "\e[25m"

# define HIDE "\e[8m"
# define NO_HIDE "\e[28m"

/*~~~~~~~~~~~~~~~~VARs~~~~~~~~~~~~~~~~*/
# define WIN_LEN	1600
# define WIN_HEIGHT	900
# define M_PI		3.14159265358979323846

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

typedef struct	s_map
{
	char	*n_txtr;//	Path to North wall texture
	char	*s_txtr;//	Path to South wall texture
	char	*e_txtr;//	Path to East wall texture
	char	*w_txtr;//	Path to West wall texture
	int		fcol;//		Floor color
	int		ccol;//		Ceiling color
	char	**map;
	size_t	map_h;//	Map hight
	size_t	map_l;//	Map width (longest line)
	int		p_dir;//	Players starting facing directionn.
	int		n_players;
}	t_map;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*____________________________________parsing________________________________*/
bool	parse_map_file(char *mapfile, t_map *txtr);
bool	parse_textures(t_map *txtr, char **str, int fd);
bool	set_map_textures(t_map *txtr, char *str);
int		get_color(char *str);
int		rgb_to_int(int r, int g, int b);
bool	check_getcolor_fail(t_map *txtr, char *str);
bool	isprint_iter(char *str);
bool	parse_map(t_map *txtr, char **str, int fd);
bool	isvalid_chr(char *str);
bool	copy_map(t_map *txtr, char *str, int fd);
bool	valid_map(t_map *txtr, char **map);
bool	check_map_struct(t_map *txtr);

void	free_mapstruct(t_map *txtr);

#endif
