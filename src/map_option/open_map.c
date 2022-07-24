/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:51:16 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 01:32:54 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		open_map(void)
{
	int		len;

	len = ft_strlen(g_game.pathmap);
	printf("|%s|\n", g_game.pathmap);
	if ((g_game.fd = open(g_game.pathmap, O_RDWR)) == -1)
	{
		g_game.iserrno = 1;
		return (error_msg("openmap"));
	}
	else if (len <= 4 || ft_strcmp(g_game.pathmap + len - 4, ".cub") != 0)
		return (error_msg("openmap"));
	return (1);
}
