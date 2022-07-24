/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 09:57:11 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/28 09:57:13 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		open_textures_file(t_xpm *xpm)
{
	printf("|%s|\n", xpm->path);
	if ((xpm->img.ptr = mlx_xpm_file_to_image(g_game.window.mlx,
			xpm->path, &xpm->width, &xpm->height)) == NULL)
		return (0);
	xpm->img.data = mlx_get_data_addr(xpm->img.ptr, &xpm->img.bpp,
		&xpm->img.size, &xpm->img.endian);
	return (1);
}

int		open_textures(void)
{
	if (open_textures_file(&g_game.texture.north) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_game.texture.east) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_game.texture.west) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_game.texture.south) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_game.texture.sprite) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_game.texture.floor) == 0)
		return (error_msg("opentextures"));
	if (open_textures_file(&g_game.texture.ceiling) == 0)
		return (error_msg("opentextures"));
	return (1);
}
