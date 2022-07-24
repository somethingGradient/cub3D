/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 01:43:26 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 01:43:38 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		verif_map_diff(int i)
{
	int		l1;
	int		l2;
	char	**map;

	map = g_game.map;
	if (i > 0)
	{
		l1 = ft_strlen(map[i]);
		l2 = ft_strlen(map[i - 1]);
		if (l1 > l2)
		{
			while (l1 > l2)
				if (map[i][l2++] != '1')
					return (0);
		}
		else if (l1 < l2)
			while (l1 < l2)
				if (map[i - 1][l1++] != '1')
					return (0);
	}
	return (1);
}

int		verif_map_matrix(void)
{
	int		i;
	int		j;

	if (g_game.map == NULL)
		return (0);
	i = -1;
	while (g_game.map[++i])
	{
		if (g_game.map[i][0] != '1' ||
			g_game.map[i][ft_strlen(g_game.map[i]) - 1] != '1' ||
			verif_map_diff(i) == 0)
			return (0);
	}
	j = -1;
	i -= 1;
	while (g_game.map[i][++j])
		if (g_game.map[i][j] != '1')
			return (0);
	j = -1;
	while (g_game.map[0][++j])
		if (g_game.map[0][j] != '1')
			return (0);
	return (1);
}

int		verif_map(void)
{
	t_texture	tex;

	tex = g_game.texture;
	if (g_game.window.height == -1 || g_game.window.width == -1 ||
		tex.north.path == NULL || tex.south.path == NULL ||
		tex.west.path == NULL || tex.east.path == NULL ||
		tex.floor.path == NULL || tex.ceiling.path == NULL ||
		g_game.map == NULL || g_game.posx == -1 || g_game.posy == -1 ||
		g_game.life.life == -1)
		return (error_msg("missinfo"));
	else if (verif_map_matrix() == 0)
		return (error_msg("parsemap"));
	return (1);
}
