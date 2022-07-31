/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_graphics.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <jannabel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:41:08 by jannabel          #+#    #+#             */
/*   Updated: 2022/07/31 20:41:09 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_GRAPHICS_H
# define CUB3D_GRAPHICS_H

# include "cub3D_structs.h"

t_color	create_tgrb(t_color t, t_color r, t_color g, t_color b);

void	put_px(int x, int y, t_color color, t_img *img);

t_color	get_px(int x, int y, t_img *img);

char	*init_graphics(t_cub_data *cub, t_game *game);

void	destroy_graphics(t_game *game);

void	make_image_from_xpm(void *mlx_ptr, t_img *img, char *xpm);

void	make_image_blank(void *mlx_ptr, t_img *img, int w, int h);

void	draw_screen(t_game *game, t_ray *rays);

void	draw_minimap(t_game *game, t_ray *rays);

/*	==== EVENT HANDLERS ==== */

int		on_loop(t_game *game);
int		on_key_press(int key, t_game *game);
int		on_key_release(int key, t_game *game);
int		on_mouse_move(int x, int y, t_game *game);
int		on_destroy_win(t_game *game);

#endif
