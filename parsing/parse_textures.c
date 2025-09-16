#include "../cub3d.h"

static bool	check_doubles(t_map *map, char *str)
{
	if (ft_strncmp(str, "NO", 2) == 0 && map->n_txtr != NULL)
		return (0);
	else if (ft_strncmp(str, "SO", 2) == 0 && map->s_txtr != NULL)
		return (0);
	else if (ft_strncmp(str, "EA", 2) == 0 && map->e_txtr != NULL)
		return (0);
	else if (ft_strncmp(str, "WE", 2) == 0 && map->w_txtr != NULL)
		return (0);
	else if (ft_strncmp(str, "F ", 2) == 0 && map->fcol != -1)
		return (0);
	else if (ft_strncmp(str, "C ", 2) == 0 && map->ccol != -1)
		return (0);
	return (1);
}

static bool	valid_texture_extension(char *str)
{
	if (ft_strncmp(str, "NO", 2) == 0 && !ft_strrcmp(str, ".xpm\n", 5))
		return (0);
	else if (ft_strncmp(str, "SO", 2) == 0 && !ft_strrcmp(str, ".xpm\n", 5))
		return (0);
	else if (ft_strncmp(str, "EA", 2) == 0 && !ft_strrcmp(str, ".xpm\n", 5))
		return (0);
	else if (ft_strncmp(str, "WE", 2) == 0 && !ft_strrcmp(str, ".xpm\n", 5))
		return (0);
	return (1);
}

// Saves the data found in the .ber file in the t_map structure.
// Returns 0 if an invalid identifier is found.
bool	set_map_textures(t_map *map, char *str)
{
	if (check_doubles(map, str) == 0)
		return (ft_printfd(2, RED"Error\nDuplicate types found\n"NO_ALL), 0);
	if (ft_strncmp(str, "NO", 2) == 0)
		map->n_txtr = ft_strdup(ft_strchr2(str, ' '));
	else if (ft_strncmp(str, "SO", 2) == 0)
		map->s_txtr = ft_strdup(ft_strchr2(str, ' '));
	else if (ft_strncmp(str, "EA", 2) == 0)
		map->e_txtr = ft_strdup(ft_strchr2(str, ' '));
	else if (ft_strncmp(str, "WE", 2) == 0)
		map->w_txtr = ft_strdup(ft_strchr2(str, ' '));
	else if (ft_strncmp(str, "F ", 2) == 0)
		map->fcol = get_color(str);
	else if (ft_strncmp(str, "C ", 2) == 0)
		map->ccol = get_color(str);
	else if (str[0] != '\n')
		return (ft_printfd(2, RED"Error\nInvalid type identifier\n"NO_ALL), 0);
	if (ft_strncmp(str, "C ", 2) == 0 || ft_strncmp(str, "F ", 2) == 0)
		return (check_getcolor_fail(map, str));
	else if (!valid_texture_extension(str))
		return (ft_printfd(2, \
				RED"Error\nInvalid texture extension: %s"NO_ALL, str), 0);
	return (1);
}

// Parsing e salvataggio delle textures
bool	parse_textures(t_map *map, char **str, int fd)
{
	*str = get_next_line(fd);
	while (*str && check_map_struct(map) == 0)
	{
		if (!isprint_iter(*str))
			return (free_mapstruct(map), free(*str), 0);
		if (!set_map_textures(map, *str))
			return (free_mapstruct(map), free(*str), 0);
		free(*str);
		*str = get_next_line(fd);
	}
	if (check_map_struct(map) == 0)
		return (free_mapstruct(map), free(*str), close(fd), 0);
	if (!*str)
		return (free_mapstruct(map), close(fd), 0);
	return (1);
}
