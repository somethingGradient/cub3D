/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:03:37 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/28 15:03:39 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	hook_move(int key)
{
	t_draw	*d;
	char	x;
	char	y;
	double	op;

	d = &g_game.draw;
	op = (key == 13 ? d->pos_x + d->dir_x * MOV * COL : d->pos_x - d->dir_x *
																	MOV * COL);
	x = g_game.map[(int)(op)][(int)d->pos_y];
	op = (key == 13 ? d->pos_y + d->dir_y * MOV * COL : d->pos_y - d->dir_y *
																	MOV * COL);
	y = g_game.map[(int)d->pos_x][(int)(op)];
	if (x == '0' || x == '5')
		d->pos_x += (key == 13 ? 1 : -1) * (d->dir_x * MOV);
	if (y == '0' || y == '5')
		d->pos_y += (key == 13 ? 1 : -1) * (d->dir_y * MOV);
	if (x == '4' || y == '4')
		next_map();
	else if (x == '7' || y == '7')
		sub_life();
}

void	hook_translate(int key)
{
	t_draw	*d;
	char	x;
	char	y;
	double	op;

	d = &g_game.draw;
	op = (key == 0 ? d->pos_x - d->dir_y * MOV * COL : d->pos_x + d->dir_y *
																	MOV * COL);
	x = g_game.map[(int)(op)][(int)d->pos_y];
	op = (key == 0 ? d->pos_y + d->dir_x * MOV * COL : d->pos_y - d->dir_x *
																	MOV * COL);
	y = g_game.map[(int)d->pos_x][(int)(op)];
	if (x == '0' || x == '5')
		d->pos_x += (key == 0 ? -1 : 1) * (d->dir_y * MOV);
	if (y == '0' || y == '5')
		d->pos_y += (key == 0 ? 1 : -1) * (d->dir_x * MOV);
	if (x == '4' || y == '4')
		next_map();
	else if (x == '7' || y == '7')
		sub_life();
}

void	hook_action(void)
{
	t_draw	*d;
	int		i;
	int		j;

	d = &g_game.draw;
	i = -2;
	while (++i <= 1)
	{
		j = -2;
		while (++j <= 1)
		{
			if (g_game.map[(int)d->pos_x + i][(int)d->pos_y + j] == '3')
			{
				g_game.map[(int)d->pos_x + i][(int)d->pos_y + j] = '0';
				draw();
				break ;
			}
		}
	}
}
