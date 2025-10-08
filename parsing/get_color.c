#include "../cub3d.h"

//Converts the color code.
int	rgb_to_int(int r, int g, int b)
{
	int	color;

	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (ft_printfd(2, RED"Error\nInvalid rgb color\n"NO_ALL), -1);
	color = r;
	color = (color << 8) | g;
	color = (color << 8) | b;
	return (color);
}

// Parsing of the rgb color code string.
static bool	check_rgb_nums(char **split_num)
{
	int	i;
	int	j;
	char	*trimmed_s;

	i = -1;
	j = 0;
	while (++i < 3)
	{
		trimmed_s = ft_strdup(split_num[i]);
		trimmed_s = ft_strtrim(ft_strtrim(trimmed_s, "\n"), " ");
		if (!trimmed_s || !trimmed_s[0])
			return (ft_printfd(2, RED"Error\nInvalid rgb color\n"NO_ALL), \
													free(trimmed_s), 0);
		while (trimmed_s[j])
		{
			if (!ft_isdigit(trimmed_s[j]))
				return (ft_printfd(2, \
					RED"Error\nInvalid rgb color\n"NO_ALL), \
													free(trimmed_s), 0);
			j++;
		}
		j = 0;
		free(trimmed_s);
	}
	return (1);
}

// Identifies the rgb color code and returns it as an integer. 
int	get_color(char *str)
{
	char	*num_triplet;
	char	**split_num;
	int		color;

	num_triplet = ft_strdup(ft_strchr2(str, ' '));
	if (!num_triplet)
		return (ft_printfd(2, RED"Error\nMalloc fail\n"NO_ALL), -1);
	split_num = ft_split(num_triplet, ',');
	free(num_triplet);
	if (!split_num)
		return (ft_printfd(2, RED"Error\nMalloc fail\n"NO_ALL), -1);
	else if (!split_num[1] || !split_num[2] || split_num[3])
		return (ft_printfd(2, RED"Error\nInvalid rgb color\n"NO_ALL), \
												free_dpc(split_num), -1);
	else if (!check_rgb_nums(split_num))
		return (free_dpc(split_num), -1);
	color = rgb_to_int(ft_atoi(split_num[0]), ft_atoi(split_num[1]), \
												ft_atoi(split_num[2]));
	free_dpc(split_num);
	return (color);
}
