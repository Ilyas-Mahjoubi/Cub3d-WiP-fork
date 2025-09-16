#include "cub3d.h"

void	free_mapstruct(t_map *txtr)
{
	if (txtr->n_txtr)
		free(txtr->n_txtr);
	if (txtr->s_txtr)
		free(txtr->s_txtr);
	if (txtr->e_txtr)
		free(txtr->e_txtr);
	if (txtr->w_txtr)
		free(txtr->w_txtr);
	if (txtr->grid)
		free_dpc(txtr->grid);
}
