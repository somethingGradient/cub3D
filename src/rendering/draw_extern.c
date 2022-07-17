#include "../../includes/cub3D.h"

t_draw	draw_extern_get_pos(t_draw draw)
{
	draw.draw_start = (-draw.line_height / 2 + draw.h / 2);
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	draw.draw_end = (draw.line_height / 2 + draw.h / 2);
	if (draw.draw_end >= draw.h)
		draw.draw_end = draw.h - 1;
	if (draw.side == 0)
		draw.wall_x = draw.pos_y + draw.perp_wall_dist * draw.ray_dir_y;
	else
		draw.wall_x = draw.pos_x + draw.perp_wall_dist * draw.ray_dir_x;
	draw.wall_x -= floor(draw.wall_x);
	if (draw.side == 0 && draw.ray_dir_x > 0)
		draw.tex_x = draw.xpm.width - draw.tex_x - 1;
	if (draw.side == 1 && draw.ray_dir_y < 0)
		draw.tex_x = draw.xpm.width - draw.tex_x - 1;
	return (draw);
}

t_draw	draw_extern_get_orient(t_draw draw)
{
	if (draw.side == 0 && draw.ray_dir_x > 0)
	{
		draw.floor_x_w = draw.map_x;
		draw.floor_y_w = draw.map_y + draw.wall_x;
	}
	else if (draw.side == 0 && draw.ray_dir_x < 0)
	{
		draw.floor_x_w = draw.map_x + 1.0;
		draw.floor_y_w = draw.map_y + draw.wall_x;
	}
	else if (draw.side == 1 && draw.ray_dir_y > 0)
	{
		draw.floor_x_w = draw.map_x + draw.wall_x;
		draw.floor_y_w = draw.map_y;
	}
	else
	{
		draw.floor_x_w = draw.map_x + draw.wall_x;
		draw.floor_y_w = draw.map_y + 1.0;
	}
	draw.dist_w = draw.perp_wall_dist;
	draw.dist_player = 0.0;
	if (draw.draw_end < 0)
		draw.draw_end = draw.h;
	return (draw);
}

t_img	draw_extern_floor(t_draw draw, t_img img)
{
	draw.xpm = g_game.texture.floor;
	while (draw.draw_end < draw.h)
	{
		draw.dist_current = draw.h / (2.0 * draw.draw_end - draw.h);
		draw.weight = (draw.dist_current - draw.dist_player) / (draw.dist_w -
															draw.dist_player);
		draw.floor_x = draw.weight * draw.floor_x_w + (1.0 - draw.weight) *
																	draw.pos_x;
		draw.floor_y = draw.weight * draw.floor_y_w + (1.0 - draw.weight) *
																	draw.pos_y;
		draw.ftex_x = (int)(draw.floor_x * draw.xpm.width) % draw.xpm.width;
		draw.ftex_y = (int)(draw.floor_y * draw.xpm.height) % draw.xpm.height;
		draw.checker_board_pattern = (int)(draw.floor_x + draw.floor_y) % 2;
		draw.floor_texture = (draw.checker_board_pattern == 0 ? 3 : 4);
		draw.color = img_get_px(draw.xpm.img, draw.ftex_x, draw.ftex_y);
		img_set_px(draw.color, img, draw.x, draw.draw_end++);
	}
	return (img);
}

t_img	draw_extern_ceil(t_draw draw, t_img img)
{
	draw.xpm = g_game.texture.ceiling;
	while (draw.draw_end < draw.h)
	{
		draw.dist_current = draw.h / (2.0 * draw.draw_end - draw.h);
		draw.weight = (draw.dist_current - draw.dist_player) / (draw.dist_w -
															draw.dist_player);
		draw.floor_x = draw.weight * draw.floor_x_w + (1.0 - draw.weight) *
																	draw.pos_x;
		draw.floor_y = draw.weight * draw.floor_y_w + (1.0 - draw.weight) *
																	draw.pos_y;
		draw.ftex_x = (int)(draw.floor_x * draw.xpm.width) % draw.xpm.width;
		draw.ftex_y = (int)(draw.floor_y * draw.xpm.height) % draw.xpm.height;
		draw.checker_board_pattern = (int)(draw.floor_x + draw.floor_y) % 2;
		draw.floor_texture = (draw.checker_board_pattern == 0 ? 3 : 4);
		draw.color = img_get_px(draw.xpm.img, draw.ftex_x, draw.ftex_y);
		img_set_px(draw.color, img, draw.x, draw.h - draw.draw_end++);
	}
	return (img);
}

t_img	draw_extern(t_draw draw, t_img img)
{
	draw.perp_wall_dist = draw.init_wall_dist;
	draw.line_height = (int)(draw.h / (draw.perp_wall_dist));
	draw = draw_extern_get_pos(draw);
	draw = draw_extern_get_orient(draw);
	img = draw_extern_floor(draw, img);
	img = draw_extern_ceil(draw, img);
	return (img);
}