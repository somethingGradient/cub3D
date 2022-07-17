#include "../../includes/cub3D.h"

int		key_hook(int key)
{
	if (key == ARROW_LEFT || key == ARROW_RIGHT)
		hook_rotate(key, 0);
	else if (key == UP || key == DOWN)
		hook_move(key);
	else if (key == LEFT || key == RIGHT)
		hook_translate(key);
	else if (key == 49)
		hook_action();
	else if (key == ESC)
		endofprog();
	else if (key == 65289)
		mlx_mouse_show(g_game.window.mlx, g_game.window.win);
	else
		return (1);
	draw();
	return (1);
}

int		close_hook(int key)
{
	(void)key;
	endofprog();
	return (1);
}