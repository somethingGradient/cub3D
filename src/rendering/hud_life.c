/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_life.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:22:26 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/30 22:22:38 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	sub_life(void)
{
	g_game.life.health -= g_game.life.sub;
	if (g_game.life.health <= 0)
	{
		g_game.life.health = g_game.life.inithealth;
		g_game.life.life--;
	}
	if (g_game.life.life <= 0)
		game_end();
	g_game.draw.pos_x = g_game.posx;
	g_game.draw.pos_y = g_game.posy;
	g_game.draw = init_draw(g_game.draw, 0);
	set_start_orient();
}

t_img	hud_life_health(t_img img)
{
	t_color	color[3];
	int		x;
	int		y;
	double	xperc;

	x = -1;
	color[1] = create_rgbcolor('n');
	while (++x < (g_game.window.width / 6))
	{
		xperc = (double)x / (g_game.window.width / 6 - 4) * 100;
		color[0] = create_rgbcolor((g_game.life.health > 25 ? 'g' : 'l'));
		y = -1;
		while (++y < (g_game.window.height / 30))
		{
			if (x < 3 || x >= (g_game.window.width / 6) - 3 ||
				y < 3 || y >= (g_game.window.height / 30) - 3 ||
				g_game.life.health < xperc)
				color[2] = color[1];
			else
				color[2] = color[0];
			img_set_px(color[2], img, g_game.window.width * 0.94 - x,
				g_game.window.height * 0.95 - y);
		}
	}
	return (img);
}

t_img	hud_life_life(t_img img)
{
	t_color	color;
	int		i;
	int		xinit;
	int		x;
	int		y;

	i = -1;
	xinit = g_game.window.width * 0.94 + g_game.window.width * 0.01;
	color = create_rgbcolor('b');
	while (++i < g_game.life.life)
	{
		x = -1;
		while (++x < (g_game.window.width / 100))
		{
			y = -1;
			while (++y < (g_game.window.height / 30))
				img_set_px(color, img, xinit + g_game.window.width / 80 * i + x,
					g_game.window.height * 0.95 - y);
		}
	}
	return (img);
}

t_img	hud_life(t_img img)
{
	img = hud_life_health(img);
	img = hud_life_life(img);
	return (img);
}
