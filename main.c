#include "cub3d.h"

// @txtr = map textures structure
int main(int ac, char **av)
{
	t_map	txtr;

	if (ac < 2)
		return (1);
	if (parse_map_file(av[1], &txtr) == 0)
		return (1);
	free_mapstruct(&txtr);
}
