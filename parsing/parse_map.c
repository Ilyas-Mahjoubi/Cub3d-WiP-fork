#include "../cub3d.h"

// Saves the map sizes and the map itself as a char matrix in the map struct.
bool	copy_map(t_map *txtr, char *str, int fd)
{
	size_t	len;

	len = 0;
	while (str)
	{
		if (!isprint_iter(str) || !isvalid_chr(str))
			return (free_mapstruct(txtr), free(str), close(fd), 0);
		txtr->map = ft_realloc(txtr->map, (txtr->map_h) * sizeof(char *), \
										(txtr->map_h + 1) * sizeof(char *));
		txtr->map[txtr->map_h] = ft_strdup(str);
		ft_printf(BRCYAN"%s"NO_ALL, txtr->map[txtr->map_h]);////////////////////////////////
		len = ft_strlen(txtr->map[txtr->map_h]);
		if (len > txtr->map_l)
			txtr->map_l = len;
		txtr->map_h++;
		free(str);
		str = get_next_line(fd);
	}
	if (!txtr->map)
		return (free_mapstruct(txtr), free(str), close(fd), 0);
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
static bool	valid_surroundings(t_map *txtr, char **map, size_t i, size_t j)
{
	if (is_player(map[i][j]))
		txtr->n_players++;
	if (j < 1 || map[i][j - 1] == '\n' || map[i][j - 1] == ' ')
		return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
	else if (!map[i][j + 1] || map[i][j + 1] == '\n' || map[i][j + 1] == ' ')
		return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
	else if (i < 1 || j >= ft_strlen(map[i - 1]) || map[i - 1][j] == ' ')
		return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
	else if (!map[i + 1] || j >= ft_strlen(map[i + 1]) || map[i + 1][j] == ' ')
		return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
	return (1);
}

bool	valid_map(t_map *txtr, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i] && txtr->n_players < 2)
	{
		if (map[i][0] == '\n')
			return ((ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0));
		while (map[i][j])
		{
			if (map[i][j] == '0' ||  is_player(map[i][j]))
				if (!valid_surroundings(txtr, map, i, j))
					return (ft_printfd(2, RED"Error\nInvalid map\n"NO_ALL), 0);
			j++;
		}
		j = 0;
		i++;
	}
	if (txtr->n_players != 1)
		return ((ft_printfd(2, \
				RED"Error\nInvalid number of players\n"NO_ALL), 0));
	return (1);
}

// Parsing e salvataggio della mappa
bool	parse_map(t_map *txtr, char **str, int fd)
{
	while (*str && !ft_strchr(*str, '1'))// Parsa e skippa linee vuote fino alla mappa
	{
		if (*str[0] != '\n')
			return (ft_printfd(2, \
				RED"Error \nInvalid line found in map file: %s"NO_ALL, *str),
				free_mapstruct(txtr), free(*str), close(fd), 0);
		free(*str);
		*str = get_next_line(fd);
	}
	if (!copy_map(txtr, *str, fd))
		return (0);
	close(fd);
	if (!valid_map(txtr, txtr->map))
		return (free_mapstruct(txtr), close(fd), 0);
	return (1);
}
