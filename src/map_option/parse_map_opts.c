/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_opts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 02:04:36 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 02:52:40 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		parse_map_opts_r(char **opts, int nbopts)
{
	int		n1;
	int		n2;

	if (nbopts == 3 && g_game.window.width == -1 && g_game.window.height == -1)
	{
		n1 = ft_atoi(opts[1]);
		n2 = ft_atoi(opts[2]);
		if ((g_game.window.width = (n1 > SCREEN_W ? SCREEN_W : n1)) == -1)
			return (0);
		if ((g_game.window.height = (n2 > SCREEN_H ? SCREEN_H : n2)) == -1)
			return (0);
	}
	else
		return (0);
	return (1);
}

int		parse_map_opts_t(char **opts, int nbopts, char texture)
{
	if (nbopts == 2)
	{
		if (texture == 'N' && g_game.texture.north.path == NULL)
			g_game.texture.north.path = ft_strdup(opts[1]);
		else if (texture == 'S' && g_game.texture.south.path == NULL)
			g_game.texture.south.path = ft_strdup(opts[1]);
		else if (texture == 'W' && g_game.texture.west.path == NULL)
			g_game.texture.west.path = ft_strdup(opts[1]);
		else if (texture == 'E' && g_game.texture.east.path == NULL)
			g_game.texture.east.path = ft_strdup(opts[1]);
		else if (texture == 'O' && g_game.texture.sprite.path == NULL)
			g_game.texture.sprite.path = ft_strdup(opts[1]);
		else if (texture == 'F' && g_game.texture.floor.path == NULL)
			g_game.texture.floor.path = ft_strdup(opts[1]);
		else if (texture == 'C' && g_game.texture.ceiling.path == NULL)
			g_game.texture.ceiling.path = ft_strdup(opts[1]);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int		parse_map_opts_n(char **opts, int nbopts)
{
	if (nbopts == 2 && g_game.next == NULL)
	{
		g_game.next = ft_strdup(opts[1]);
		return (1);
	}
	return (0);
}

int		parse_map_opts_l(char **opts, int nbopts)
{
	if (nbopts == 5 && g_game.life.life == -1)
	{
		g_game.life.life = ft_atoi(opts[1]);
		g_game.life.health = ft_atoi(opts[2]);
		g_game.life.inithealth = ft_atoi(opts[3]);
		g_game.life.sub = ft_atoi(opts[4]);
		return (1);
	}
	return (0);
}
