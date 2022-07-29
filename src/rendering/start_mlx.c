/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:56:13 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/18 02:56:25 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_start_orient(void)
{
	char	pos;
	int		deg;

	pos = g_game.orient;
	g_game.map[(int)g_game.posx][(int)g_game.posy] = '0';
	deg = 0;
	if (pos == 'E')
		deg = 90;
	else if (pos == 'W')
		deg = -90;
	else if (pos == 'S')
		deg = 180;
	if (deg != 0)
		hook_rotate(0, (deg) * M_PI / 180.0);
}

int		start_mlx(void)
{

	g_game.window.mlx = mlx_init();
	g_game.window.win = mlx_new_window(g_game.window.mlx, g_game.window.width,
		g_game.window.height, "Cub3D");
	if (open_textures() == ERROR)
		return (exit_msg("Failure to open sprites."));
	
	// updstate();
	g_game.img = create_img();
	g_game.orient = g_game.map[(int)g_game.posx][(int)g_game.posy];
	g_game.draw = init_draw(g_game.draw, 0);
	set_start_orient();
	// if (g_game.save == 1)
	// 	printf("Saving image...\n");
	draw();
	// // if (g_game.save == 0)
	// // {
		mlx_hook(g_game.window.win, 2, 1L << 0, key_hook, g_game.window.mlx);
		mlx_hook(g_game.window.win, 17, 1L << 0, close_hook, g_game.window.mlx);
		mlx_loop(g_game.window.mlx);
	// }
	// else
		// printf("Saved !\n");
	return (1);
}
