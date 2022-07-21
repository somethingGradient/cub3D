#include "../../includes/cub3D.h"
//#include <X11/X.h>

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

int		mouse_hook(int x, int y)
{
	if (x != g_game.window.width / 2 || y != g_game.window.height / 2)
	{
		printf("%.3d %.3d\n", x - g_game.window.width / 2,
								y - g_game.window.height / 2);
		usleep(500);
		mlx_mouse_move(g_game.window.mlx, g_game.window.win,
			g_game.window.width / 2, g_game.window.height / 2);
	}
}

int		start_mlx(void)
{
	g_game.window.mlx = mlx_init();
	g_game.window.win = mlx_new_window(g_game.window.mlx, g_game.window.width,
		g_game.window.height, "Cub3D");
	if (open_textures() == 0)
		return (exit_msg("opentext"));
	updstate();
	g_game.img = create_img();
	g_game.orient = g_game.map[(int)g_game.posx][(int)g_game.posy];
	g_game.draw = init_draw(g_game.draw, 0);
	set_start_orient();
	draw();
	if (g_game.save == 0)
	{
		mlx_hook(g_game.window.win, KeyPress, KeyPressMask, key_hook,
														g_game.window.mlx);
		mlx_hook(g_game.window.win, DestroyNotify, StructureNotifyMask,
											close_hook, g_game.window.mlx);
		mlx_loop(g_game.window.mlx);
	}
	return (1);
}