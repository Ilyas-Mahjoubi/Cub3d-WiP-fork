#include "../cub3d.h"

// Saves the map sizes and the map itself as a char matrix in the map struct.
bool	copy_map(t_map *map, char *str, int fd)
{
	size_t	len;

	len = 0;
	while (str)
	{
		if (!isprint_iter(str) || !isvalid_chr(str))
			return (free_mapstruct(map), free(str), close(fd), 0);
		map->grid = ft_realloc(map->grid, (map->map_h) * sizeof(char *), \
										(map->map_h + 1) * sizeof(char *));
		map->grid[map->map_h] = ft_strdup(str);
		ft_printf(BRCYAN"%s"NO_ALL, map->grid[map->map_h]);////////////////////////////////
		len = ft_strlen(map->grid[map->map_h]);
		if (len > map->map_l)
			map->map_l = len;
		map->map_h++;
		free(str);
		str = get_next_line(fd);
	}
	if (!map->grid)
		return (free_mapstruct(map), free(str), close(fd), 0);
	return (1);
}

static bool	is_player(int c)
{
	if (c == 'N')
		return (1);
	else if (c == 'S')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'W')
		return (1);
	return (0);
}

// i = line
// j = column
static bool	valid_surroundings(t_map *map, char **grid, size_t i, size_t j)
{
	if (is_player(grid[i][j]))
		map->n_players++;
	if (j < 1 || grid[i][j - 1] == '\n' || grid[i][j - 1] == ' ')
		return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
	else if (!grid[i][j + 1] || grid[i][j + 1] == '\n' || grid[i][j + 1] == ' ')
		return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
	else if (i < 1 || j >= ft_strlen(grid[i - 1]) || grid[i - 1][j] == ' ')
		return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
	else if (!grid[i + 1] || j >= ft_strlen(grid[i + 1]) || grid[i + 1][j] == ' ')
		return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
	return (1);
}

bool	valid_map(t_map *map, char **grid)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (grid[i] && map->n_players < 2)
	{
		if (grid[i][0] == '\n')
			return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
		while (grid[i][j])
		{
			if (grid[i][j] == '0' ||  is_player(grid[i][j]))
				if (!valid_surroundings(map, grid, i, j))
					return (ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0);
			j++;
		}
		j = 0;
		i++;
	}
	if (map->n_players != 1)
		return ((ft_printfd(2, \
				RED"Error\nInvalid number of players\n"NO_ALL), 0));
	return (1);
}

// Parsing e salvataggio della mappa
bool	parse_map(t_map *map, char **str, int fd)
{
	while (*str && !ft_strchr(*str, '1'))// Parsa e skippa linee vuote fino alla mappa
	{
		if (*str[0] != '\n')
			return (ft_printfd(2, \
				RED"Error \nInvalid line found in map file: %s"NO_ALL, *str),
				free_mapstruct(map), free(*str), close(fd), 0);
		free(*str);
		*str = get_next_line(fd);
	}
	if (!copy_map(map, *str, fd))
		return (0);
	close(fd);
	if (!valid_map(map, map->grid))
		return (free_mapstruct(map), close(fd), 0);
	return (1);
}
