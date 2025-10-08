#include "cub3d.h"

void	free_mapstruct(t_map *map)
{
	if (map->n_txtr)
		free(map->n_txtr);
	if (map->s_txtr)
		free(map->s_txtr);
	if (map->e_txtr)
		free(map->e_txtr);
	if (map->w_txtr)
		free(map->w_txtr);
	if (map->grid)
		free_dpc(map->grid);
}
