#include "../../includes/cub3D.h"

void	free_2d(void **arg)
{
	int	i;

	if (arg != NULL)
	{
		i = -1;
		while (arg[++i])
			free(arg[i]);
		free(arg);
		arg = NULL;
	}
}

void	free_img(t_xpm *xpm)
{
	if ((*xpm).path != NULL)
	{		
		free((*xpm).path);
		if ((*xpm).img.ptr != NULL)
			mlx_destroy_image(g_game.window.mlx, (*xpm).img.ptr);
	}
}

int	game_end(void)
{
	if (g_game.error != NULL)
		free(g_game.error);
	if (g_game.map != NULL)
		free_2d((void**)g_game.map);
	free_img(&(g_game.texture.south));
	free_img(&(g_game.texture.nord));
	free_img(&(g_game.texture.west));
	free_img(&(g_game.texture.east));
	free_img(&(g_game.texture.sprite));
	// mlx_destroy_image(g_game.window.mlx, g_game.img.ptr);
	// free(g_game.window.win);
	// free(g_game.window.mlx);
	//printf("End at state %d\n", updstate());
	exit(EXIT_SUCCESS);
}