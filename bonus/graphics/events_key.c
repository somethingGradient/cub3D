#include "../includes/cub3D.h"

int	on_key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		destroy_game(game, true);
	else if (key == KEY_LEFT)
		game->p.rotate_l = true;
	else if (key == KEY_RIGHT)
		game->p.rotate_r = true;
	else if (key == KEY_W)
		game->p.move_no = true;
	else if (key == KEY_S)
		game->p.move_so = true;
	else if (key == KEY_A)
		game->p.move_we = true;
	else if (key == KEY_D)
		game->p.move_ea = true;
	return (0);
}

int	on_key_release(int key, t_game *game)
{
	if (key == KEY_LEFT)
		game->p.rotate_l = false;
	else if (key == KEY_RIGHT)
		game->p.rotate_r = false;
	else if (key == KEY_W)
		game->p.move_no = false;
	else if (key == KEY_S)
		game->p.move_so = false;
	else if (key == KEY_A)
		game->p.move_we = false;
	else if (key == KEY_D)
		game->p.move_ea = false;
	return (0);
}
