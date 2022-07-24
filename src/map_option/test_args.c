/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:38:58 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 00:20:10 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		test_args(int argc, char **argv)
{
	g_game.iserrno = 0;
	if (argc >= 2)
	{
		g_game.pathmap = argv[1];
		g_game.exec = argv[0];
		if (argc >= 3)
			if (ft_strcmp(argv[2], "-save") == 0)
				g_game.save = 1;
			else
				return (error_msg("saveopt"));
		else
			g_game.save = 0;
		return (1);
	}
	return (error_msg("entrymap"));
}
