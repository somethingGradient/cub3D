/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 05:07:11 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/27 05:07:13 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_color	create_tcolor(int color)
{
	t_color		newcolor;

	newcolor.b = color % 1000;
	color /= 1000;
	newcolor.g = color % 1000;
	color /= 1000;
	newcolor.r = color % 1000;
	return (newcolor);
}

t_color	create_rgbcolor(char c)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if (c == 'r')
		color.r = 255;
	else if (c == 'l')
		color.r = 204;
	else if (c == 'g')
		color.g = 255;
	else if (c == 'b')
		color.b = 255;
	return (color);
}

int		set_color(char *opts, t_color *color)
{
	int		i;

	i = 0;
	(*color).r = 0;
	(*color).g = 0;
	(*color).b = 0;
	while (ft_isdigit(opts[i]))
		(*color).r = ((*color).r * 10) + (opts[i++] - '0');
	if (opts[i++] != ',')
		return (0);
	while (ft_isdigit(opts[i]))
		(*color).g = ((*color).g * 10) + (opts[i++] - '0');
	if ((opts[i++] != ','))
		return (0);
	while (ft_isdigit(opts[i]))
		(*color).b = ((*color).b * 10) + (opts[i++] - '0');
	return (1);
}
