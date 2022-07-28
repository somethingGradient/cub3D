/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_get_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:53:20 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/30 17:53:26 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		draw_get_dist(t_draw draw)
{
	if ((size_t)draw.map_x > ft_tablen((void**)g_game.map) ||
		(size_t)draw.map_y > ft_strlen(g_game.map[draw.map_x]) ||
		(g_game.map[draw.map_x][draw.map_y] >= '1' &&
		g_game.map[draw.map_x][draw.map_y] <= '3') ||
		g_game.map[draw.map_x][draw.map_y] == '5')
		return (1);
	return (0);
}

t_draw	draw_get_perpdist(t_draw draw)
{
	double	df;

	df = (double)((draw.w / 2) - abs(draw.x - (draw.w / 2))) / (draw.w / 2);
	draw.fog = 0;
	if (draw.perp_wall_dist > FOG + df)
	{
		draw.perp_wall_dist = FOG + df;
		draw.fog = 1;
	}
	return (draw);
}
