#include "../includes/cub3D.h"

//t_game g_game;

static int game_start(char *filename)
{
	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 480, 320, "Hello world!");
	// mlx_loop(mlx);

	// t_game	*game;

	// game = NULL;
	// game = malloc(sizeof(*game));
	// get_map_options(game, filename);

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
	// return (1);
}

static int check_argv(int argc, char **argv)
{
	int len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if (argv[1][len - 1] == 'b' || argv[1][len - 2] == 'u' || argv[1][len - 3] == 'c' || argv[1][len - 4] == '.')
			return (1);
	}
	printf("Error.\nWrite correct map.\n");
	return (0);
}

int main(int argc, char **argv)
{
	if (check_argv(argc, argv))
	{
		if (!game_start(argv[1]))
			return (1);
	}
	return (0);
}
