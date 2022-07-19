#include "../../includes/cub3D.h"

void	free_2d(void **arg)
{
	int		i;

	if (arg != NULL)
	{
		i = -1;
		while (arg[++i])
			free(arg[i]);
		free(arg);
		arg = NULL;
	}
}
