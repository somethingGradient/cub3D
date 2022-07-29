#include "../../includes/cub3D.h"

int		open_textures_file(t_xpm *xpm)
{
	if ((xpm->img.ptr = mlx_xpm_file_to_image(g_game.window.mlx,
			xpm->path, &xpm->width, &xpm->height)) == NULL)
		return (ERROR);
	xpm->img.data = mlx_get_data_addr(xpm->img.ptr, &xpm->img.bpp,
		&xpm->img.size, &xpm->img.endian);
	return (SUCCESS);
}

int		open_textures(void)
{
	if (open_textures_file(&g_game.texture.nord) == ERROR)
		return (exit_msg("Failure to open nord."));
	if (open_textures_file(&g_game.texture.south) == ERROR)
		return (exit_msg("Failure to open south."));
	if (open_textures_file(&g_game.texture.east) == ERROR)
		return (exit_msg("Failure to open east."));
	if (open_textures_file(&g_game.texture.west) == ERROR)
		return (exit_msg("Failure to open west."));
	if (g_game.texture.sprite.path != NULL)
	{
		if (open_textures_file(&g_game.texture.sprite) == ERROR)
			return (exit_msg("Failure to open sprite."));
	}
	// if (open_textures_file(&g_game.texture.floor) == 0)
	// 	return (exit_msg("Failure to open floor."));
	// if (open_textures_file(&g_game.texture.ceil) == 0)
	// 	return (exit_msg("Failure to open ceil."));
	return (SUCCESS);
}