/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_vision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:03:42 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/28 15:03:44 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	hook_rotate(int key, double initrot)
{
	t_draw	*d;
	double	rot;

	rot = ((initrot == 0) ? ROT : initrot);
	d = &g_game.draw;
	if (key == 123)
	{
		d->old_dir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(rot) - d->dir_y * sin(rot);
		d->dir_y = d->old_dir_x * sin(rot) + d->dir_y * cos(rot);
		d->old_plane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(rot) - d->plane_y * sin(rot);
		d->plane_y = d->old_plane_x * sin(rot) + d->plane_y * cos(rot);
	}
	else
	{
		d->old_dir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(-rot) - d->dir_y * sin(-rot);
		d->dir_y = d->old_dir_x * sin(-rot) + d->dir_y * cos(-rot);
		d->old_plane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(-rot) - d->plane_y * sin(-rot);
		d->plane_y = d->old_plane_x * sin(-rot) + d->plane_y * cos(-rot);
	}
}

void	hook_vertical(int key)
{
	t_draw	*d;

	d = &g_game.draw;
	if (key == 126)
	{
		if (d->vertical < g_game.window.height / 3)
			d->vertical += g_game.window.height / 50;
	}
	else if (key == 125)
	{
		if (d->vertical > -g_game.window.height / 3)
			d->vertical -= g_game.window.height / 50;
	}
}
