/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:21:46 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/29 11:21:47 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_img	hud_cross(t_img img)
{
	int		x;
	int		y;
	t_color	color;

	color = create_rgbcolor('r');
	x = g_game.window.width / 2 - (g_game.window.width / 50) - 1;
	y = g_game.window.height / 2 - (g_game.window.height / 50) - 1;
	while (++x < g_game.window.width / 2 + (g_game.window.width / 50))
		img_set_px(color, img, x, g_game.window.height / 2);
	while (++y < g_game.window.height / 2 + (g_game.window.height / 50))
		img_set_px(color, img, g_game.window.width / 2, y);
	return (img);
}
