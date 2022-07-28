/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 02:05:29 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/27 02:05:31 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	img_set_px(t_color color, t_img img, int x, int y)
{
	if (!(color.r == -104 && color.g == 0 && color.b == -120))
	{
		*(img.data + (x * 4 + 2) + (img.size * y)) = (unsigned)color.r;
		*(img.data + (x * 4 + 1) + (img.size * y)) = (unsigned)color.g;
		*(img.data + (x * 4 + 0) + (img.size * y)) = (unsigned)color.b;
	}
}

t_color	img_get_px(t_img img, int x, int y)
{
	t_color	color;

	color.r = (unsigned)*(img.data + (x * 4 + 2) + (img.size * y));
	color.g = (unsigned)*(img.data + (x * 4 + 1) + (img.size * y));
	color.b = (unsigned)*(img.data + (x * 4 + 0) + (img.size * y));
	return (color);
}

t_img	create_background(t_img img)
{
	t_window	win;
	int			x;
	int			y;

	win = g_game.window;
	x = -1;
	while (++x < win.width)
	{
		y = -1;
		while (++y < win.height)
			if (y < win.height / 2 + g_game.draw.vertical)
				img_set_px(g_game.texture.ceil, img, x, y);
			else
				img_set_px(g_game.texture.floor, img, x, y);
	}
	return (img);
}

t_img	create_hud(t_img img, t_draw draw)
{
	img = hud_cross(img);
	img = hud_minimap(img, draw);
	img = hud_life(img);
	return (img);
}

t_img	create_img(void)
{
	t_img	img;

	img.ptr = mlx_new_image(g_game.window.mlx, g_game.window.width,
		g_game.window.height);
	img.data = mlx_get_data_addr(img.ptr, &img.bpp, &img.size, &img.endian);
	return (img);
}
