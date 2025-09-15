#include "../cub3d.h"

/////////////////////////////////////////////////////////////
void print_map_data(t_map *txtr)
{
	ft_printf(BRCYAN"\n");
	ft_printf("n_txtr: %s\n", txtr->n_txtr);
	ft_printf("s_txtr: %s\n", txtr->s_txtr);
	ft_printf("e_txtr: %s\n", txtr->e_txtr);
	ft_printf("w_txtr: %s\n", txtr->w_txtr);
	ft_printf("fcol: %d\n", txtr->fcol);
	ft_printf("ccol: %d\n", txtr->ccol);
	ft_printf("map hight: %d\n", txtr->map_h);
	ft_printf("map width: %d\n", txtr->map_l);
	ft_printf("n_players: %d\n", txtr->n_players);
	// if (!txtr->map)
	// {
	// 	ft_printf(NO_ALL"No map found.\n");
	// 	return ;
	// }
	// for (int i = 0; txtr->map[i]; i++)
	// 	ft_printf("%s\n", txtr->map[i]);
	ft_printf(NO_ALL"\n");
}
/////////////////////////////////////////////////////////////

void	init_mapvars(t_map *txtr)
{
	txtr->n_players = 0;
	txtr->n_txtr = NULL;
	txtr->s_txtr = NULL;
	txtr->e_txtr = NULL;
	txtr->w_txtr = NULL;
	txtr->map_h = 0;
	txtr->map_l = 0;
	txtr->p_dir = 0;
	txtr->fcol = -1;
	txtr->ccol = -1;
	txtr->map = NULL;
}

// Reads the .ber file to parse it and save the data found in it.
bool	parse_map_file(char *mapfile, t_map *txtr)
{
	int		fd;
	char	*str;

	str = NULL;
	init_mapvars(txtr);
	if (!ft_strrcmp(mapfile, ".cub", 4))// Parsing map file extension
		return (ft_printfd(2, RED"Error\nInvalid file extension\n"NO_ALL), 0);
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (ft_printfd(2, RED"Error\nCan't read from file\n"NO_ALL), 0);

	// Parsing e salvataggio delle textures
	if (!parse_textures(txtr, &str, fd))
		return (0);

	// Parsing e salvataggio della mappa
	if (!parse_map(txtr, &str, fd))
		return (0);

	print_map_data(txtr);////////////////////////////////
	return (close(fd), 1);
}
