/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:03:29 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/27 03:03:30 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

/*
** 123: LEFT
** 124: RIGHT
** 125: DOWN
** 126: UP
** printf("key: %d\n", key);
*/

int		key_hook(int key)
{
	if (key == 123 || key == 124)
		hook_rotate(key, 0);
	else if (key == 1 || key == 13)
		hook_move(key);
	else if (key == 0 || key == 2)
		hook_translate(key);
	else if (key == 125 || key == 126)
		hook_vertical(key);
	else if (key == 49)
		hook_action();
	else if (key == 53)
		game_end();
	else
		return (1);
	draw();
	return (1);
}

int		close_hook(int key)
{
	(void)key;
	game_end();
	return (1);
}
