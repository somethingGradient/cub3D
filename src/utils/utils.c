#include "../../includes/cub3D.h"

size_t	ft_tablen(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}