#include "../../includes/cub3D.h"

void	free_img(t_xpm *xpm)
{
	if ((*xpm).path != NULL)
	{
		free((*xpm).path);
		mlx_destroy_image(g_game.window.mlx, (*xpm).img.ptr);
	}
}

int		endofprog(void)
{
	free_img(&(g_game.texture.south));
	free_img(&(g_game.texture.north));
	free_img(&(g_game.texture.west));
	free_img(&(g_game.texture.east));
	free_img(&(g_game.texture.sprite));
	free_img(&(g_game.texture.floor));
	free_img(&(g_game.texture.ceiling));
	if (g_game.next != NULL)
		free(g_game.next);
	if (g_game.map != NULL)
		free_2d((void**)g_game.map);
	mlx_destroy_image(g_game.window.mlx, g_game.img.ptr);
	free(g_game.window.win);
	free(g_game.window.mlx);
	//ft_printf("End at state %d\n", updstate());
	exit(EXIT_SUCCESS);
}