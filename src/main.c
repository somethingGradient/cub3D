#include "../includes/cub3D.h"

void	init_game(void)
{
	g_game.window.height = -1;
	g_game.window.width = -1;
	g_game.texture.nord.path = NULL;
	g_game.texture.south.path = NULL;
	g_game.texture.west.path = NULL;
	g_game.texture.east.path = NULL;
	g_game.texture.sprite.path = NULL;
	g_game.texture.floor_color = NULL;
	g_game.texture.ceil_color = NULL;
	g_game.texture.floor.path = NULL;
	g_game.texture.ceiling.path = NULL;
	g_game.next = NULL;
	g_game.map = NULL;
	g_game.error = NULL;
	g_game.posx = -1;
	g_game.posy = -1;
	g_game.life.life = -1;
	g_game.life.health = -1;
	g_game.life.inithealth = -1;
	g_game.life.sub = -1;
}

static int game_start()
{
	init_game();
	if (get_map_options() == ERROR)
		return (ERROR);

	// int i = -1;
	// while (game->map[++i])
	// 	printf("%s", game->map[i]);

	// game->mlx = mlx_init();
	// open_sprites(game);
	// ft_new_window(game);
	// mlx_key_hook(game->window.reference, keys_hook, game);
	// mlx_loop_hook(game->mlx, animations, game);
	// mlx_loop(game->mlx);
	// free(game->options->nord);
	// free(game->options->south);
	// free(game->options->west);
	// free(game->options->east);
	// free(game->options->sprite);
	// if (game->map)
	// {
	// 	int i = -1;
	// 	while (game->map[++i])
	// 	{
	// 		free(game->map[i]);
	// 		game->map[i] = NULL;
	// 	}
	// 	game->map = NULL;
	// }

	// free(game->options);
	// free(game);
	return (exit_msg("SUCCESS"));
}

static int check_argv(int argc, char **argv)
{
	int len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if (argv[1][len - 1] == 'b' || argv[1][len - 2] == 'u'
			|| argv[1][len - 3] == 'c' || argv[1][len - 4] == '.')
			g_game.pathmap = argv[1];
		else
			return (exit_msg("Wrong filename."));
	}
	else
		return (exit_msg("Wrong number of arguments."));
	return (SUCCESS);
}

int main(int argc, char **argv)
{
	if (check_argv(argc, argv) == SUCCESS)
	{
		if (game_start() == SUCCESS)
		{
			game_end();
			return (SUCCESS);
		}
	}
	if (g_game.error != NULL)
		printf("%s", g_game.error);
	game_end();
	return (ERROR);
}
