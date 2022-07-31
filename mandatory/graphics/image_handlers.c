/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <jannabel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:44:02 by jannabel          #+#    #+#             */
/*   Updated: 2022/07/31 20:44:03 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	make_image_from_xpm(void *mlx_ptr, t_img *img, char *xpm)
{
	if (!mlx_ptr || !img || !xpm)
		return ;
	img->img = mlx_xpm_file_to_image(mlx_ptr, xpm, &img->w, &img->h);
	if (img->img)
		img->addr = mlx_get_data_addr(img->img, &img->bpp,
				&img->line, &img->end);
}

void	make_image_blank(void *mlx_ptr, t_img *img, int w, int h)
{
	if (!mlx_ptr || !img || !w || !h)
		return ;
	img->img = mlx_new_image(mlx_ptr, w, h);
	if (img->img)
		img->addr = mlx_get_data_addr(img->img, &img->bpp,
				&img->line, &img->end);
	img->w = w;
	img->h = h;
}
