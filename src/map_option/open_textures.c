#include "../../includes/cub3D.h"

int		open_textures_file(t_xpm *xpm)
{
	if ((xpm->img.ptr = mlx_xpm_file_to_image(g_game.window.mlx,
			xpm->path, &xpm->width, &xpm->height)) == NULL)
		return (0);
	xpm->img.data = mlx_get_data_addr(xpm->img.ptr, &xpm->img.bpp,
		&xpm->img.size, &xpm->img.endian);
	return (1);
}

int		open_textures(void)
{
	if (open_textures_file(&g_game.texture.nord) == 0)
		return (exit_msg("opentextures"));
	if (open_textures_file(&g_game.texture.east) == 0)
		return (exit_msg("opentextures"));
	if (open_textures_file(&g_game.texture.west) == 0)
		return (exit_msg("opentextures"));
	if (open_textures_file(&g_game.texture.south) == 0)
		return (exit_msg("opentextures"));
	if (open_textures_file(&g_game.texture.sprite) == 0)
		return (exit_msg("opentextures"));
	if (open_textures_file(&g_game.texture.floor) == 0)
		return (exit_msg("opentextures"));
	if (open_textures_file(&g_game.texture.ceiling) == 0)
		return (exit_msg("opentextures"));
	return (1);
}