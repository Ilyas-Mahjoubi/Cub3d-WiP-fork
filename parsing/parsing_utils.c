#include "../cub3d.h"

// Verifies all characters in the string are printable or '\n'.
bool	isprint_iter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isprint(str[i]) && str[i] != '\n')
		{
			ft_printfd(2, \
				RED"Error\nInvalid character found in map file\n"NO_ALL);
			return (0);
		}
		i++;
	}
	return (1);
}

// Verifies all map variables have been set.
bool	check_map_struct(t_map *txtr)
{
	if (!txtr->n_txtr)
		return (0);
	if (!txtr->s_txtr)
		return (0);
	if (!txtr->e_txtr)
		return (0);
	if (!txtr->w_txtr)
		return (0);
	if (txtr->fcol == -1 || txtr->ccol == -1)
		return (0);
	return (1);
}

bool	check_getcolor_fail(t_map *txtr, char *str)
{
	if (ft_strncmp(str, "F ", 2) == 0 && txtr->fcol == -1)
		return (0);
	else if (ft_strncmp(str, "C ", 2) == 0 && txtr->ccol == -1)
		return (0);
	return (1);
}

// Valid characters for the map: 1, 0, N, S, E, W, \n, white spaces.
bool	isvalid_chr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\n' && str[i] != '1' && str[i] != '0' && \
			str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && \
			str[i] != 'E' && str[i] != ' ')
		{
			ft_printfd(2, \
				RED"Error\nInvalid character found in map\n"NO_ALL);
			return (0);
		}
		i++;
	}
	return (1);
}
