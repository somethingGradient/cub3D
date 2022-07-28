/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:21:51 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/29 11:21:52 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	get_pos(int x)
{
	return (MMP_DECA + (x * MMP_SIZE / 11));
}

t_img		hud_minimap_cadre(t_img img)
{
	int		x;
	int		y;
	int		i;
	t_color	color;

	color = create_rgbcolor('n');
	x = -1;
	y = -1;
	while (++x <= MMP_SIZE)
	{
		i = -1;
		while (++i <= 11)
			img_set_px(color, img, x + MMP_DECA, get_pos(i));
	}
	while (++y <= MMP_SIZE)
	{
		i = -1;
		while (++i <= 11)
			img_set_px(color, img, get_pos(i), y + MMP_DECA);
	}
	return (img);
}

t_img		hub_minimap_cube(t_img img, t_color color, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	x += 5;
	y += 5;
	while (++i <= MMP_SIZE / 11)
	{
		j = -1;
		while (++j <= MMP_SIZE / 11)
			img_set_px(color, img, get_pos(y) + j, get_pos(x) + i);
	}
	return (img);
}

t_img		hud_minimap_calcul(t_img img, t_draw draw)
{
	int		x;
	int		y;
	double	px;
	double	py;

	x = -6;
	while (++x <= 5)
		if ((px = draw.pos_x + x) >= 0 &&
			(size_t)px < ft_tablen((void**)g_game.map))
		{
			y = -6;
			while (++y <= 5)
				if ((py = draw.pos_y + y) >= 0 &&
					(size_t)py <= ft_strlen(g_game.map[(int)px]))
				{
					if (x == 0 && y == 0)
						hub_minimap_cube(img, create_rgbcolor('g'), x, y);
					else if ((g_game.map[(int)px][(int)py] >= '1'
							&& g_game.map[(int)px][(int)py] <= '3')
							|| g_game.map[(int)px][(int)py] == '5')
						hub_minimap_cube(img, create_rgbcolor('r'), x, y);
				}
		}
	return (img);
}

t_img		hud_minimap(t_img img, t_draw draw)
{
	img = hud_minimap_calcul(img, draw);
	img = hud_minimap_cadre(img);
	return (img);
}
