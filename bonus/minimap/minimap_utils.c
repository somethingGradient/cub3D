/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <jannabel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:41:49 by jannabel          #+#    #+#             */
/*   Updated: 2022/07/31 20:41:50 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	rect(t_img *img, t_shape shape, int color)
{
	int	i;
	int	j;

	i = shape.y;
	while (i < shape.y + shape.height && i < img->w)
	{
		j = shape.x;
		while (j < shape.x + shape.width && j < img->h)
		{
			put_px(i, j, color, img);
			++j;
		}
		++i;
	}
}

void	draw_line(t_img *img, t_vector s, t_vector e, double angle)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltax = cos(angle);
	deltay = sin(angle);
	pixels = round(sqrt(pow(s.x - e.x, 2) + pow(s.y - e.y, 2))) + 2;
	while (pixels && s.x > 0 && s.y > 0 && s.x < img->w && s.y < img->h)
	{
		put_px((int)s.x, (int)s.y, 0xD5A576, img);
		s.x += deltax;
		s.y += deltay;
		--pixels;
	}
}

void	circle(t_img *img, t_shape s, int color)
{
	int		i;
	int		j;
	double	dist;

	i = s.y;
	while (i < s.y + s.height && i < img->w)
	{
		j = s.x;
		while (j < s.x + s.width && j < img->h)
		{
			dist = sqrt(pow(i - (s.y + s.height / 2), 2)
					+ pow(j - (s.x + s.width / 2), 2));
			if (dist < s.width / 2.0)
				put_px(i, j, color, img);
			++j;
		}
		++i;
	}
}
