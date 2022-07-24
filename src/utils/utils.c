#include "../../includes/cub3D.h"

size_t	ft_tablen(void **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return (i);
}

int		ft_nbwords(char **line)
{
	int		i;

	i = 0;
	while (line[i] != 0)
		i++;
	return (i);
}