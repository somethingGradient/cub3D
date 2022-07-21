
#include "../../includes/cub3D.h"

int	distribute_char(char *line, int i)
{
	if (line[i] == 'R')
	{
		if (get_resolution(line, i, NULL) == ERROR)
			return (ERROR);
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (get_colors_arr(line, i, line[i]) == ERROR)
			return (ERROR);
	}
	else if (line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'W' || line[i] == 'E'
		|| line[i] == 'F' || line[i] == 'C')
	{
		if (get_sprites(line, i) == ERROR)
			return (ERROR);
	}
	else if (line[i] == '1')
		return (2);	
	else
		return (ERROR);

	return (SUCCESS);
}

int	check_chars(char *line, int i)
{
	int	status;

	while (line[++i])
	{
		if (line[i] == ' ')
			continue ;
		status = distribute_char(line, i);
		if (status == 2)
			return (2);
		else if (status == ERROR)
			return (ERROR);
		else
			return (SUCCESS);
		if (line[i] != ' ' && line[i] != '\n')
			return (ERROR);
		if (line[i] == '\n')
			break ;
	}
	return (SUCCESS);
}

int	parse_options(char *line, int fd)
{
	int	status;

	line = get_next_line(fd);
	while (line)
	{	
		if (ft_strlen(line) > 2)
		{
			status = check_chars(line, -1);
			if (status == 2)
			{
				free(line);
				return (SUCCESS);
			}
			else if (status == ERROR)
			{
				free(line);
				return (ERROR);
			}
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (SUCCESS);
}

int	check_sprites(void)
{
	if (!g_game.texture.nord.path || !g_game.texture.south.path
		|| !g_game.texture.west.path || !g_game.texture.east.path
		|| !g_game.texture.sprite.path)
		return (ERROR);
	return (SUCCESS);
}

int	get_map_options()
{
	int		fd;

	fd = open(g_game.pathmap, O_RDONLY);
	if (fd < 0)
		return (exit_msg("Couldn't open map file."));
	if (parse_options(NULL, fd) == ERROR)
		return (exit_msg("Couldn't parse map."));
	if (check_sprites() == ERROR)
		return (exit_msg("Incorrect sprite."));

	printf("%d %d\n", g_game.window.width, g_game.window.height);
	printf("%s\n", g_game.texture.nord.path);
	printf("%s\n", g_game.texture.south.path);
	printf("%s\n", g_game.texture.west.path);
	printf("%s\n", g_game.texture.east.path);
	printf("%s\n", g_game.texture.sprite.path);

	printf("%d %d %d\n", g_game.texture.floor_color[0], g_game.texture.floor_color[1], g_game.texture.floor_color[2] );
	printf("%d %d %d\n", g_game.texture.ceil_color[0], g_game.texture.ceil_color[1], g_game.texture.ceil_color[2] );
	// 	|| check_sprites(game->options) == ERROR)
	// {
	// 	printf("Error.\nInvalid map options.\n");
	// 	return (ERROR);
	// }
	// game->map = malloc_map(filename);
	// // get_map(game, fd);
	close(fd);
	return (SUCCESS);
}
