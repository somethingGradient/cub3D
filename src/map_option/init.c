/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:33:12 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/15 20:36:25 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_data(void)
{
	g_game.window.height = -1;
	g_game.window.width = -1;
	g_game.texture.north.path = NULL;
	g_game.texture.south.path = NULL;
	g_game.texture.west.path = NULL;
	g_game.texture.east.path = NULL;
	g_game.texture.sprite.path = NULL;
	g_game.texture.floor.path = NULL;
	g_game.texture.ceiling.path = NULL;
	g_game.next = NULL;
	g_game.map = NULL;
	g_game.error = NULL;
	g_game.posx = -1;
	g_game.posy = -1;
	g_game.life.life = -1;
	g_game.life.health = -1;
	g_game.life.inithealth = -1;
	g_game.life.sub = -1;
}
