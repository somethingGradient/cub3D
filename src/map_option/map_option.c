
#include "../../includes/cub3D.h"

static int	distribute_char(char *line, int i)
{
	if (line[i] == 'R')
	{
		if (get_resolution(line, i, NULL) == ERROR)
			return (exit_msg("Window resolution is incorrect."));
	}
	else if (line[i] == 'F' || line[i] == 'C')
	{
		if (get_color(line, i, line[i]) == ERROR)
			return (exit_msg("Colors RGB are incorrect."));
	}
	else if (line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'W' || line[i] == 'E')
	{
		if (get_sprites(line, i) == ERROR)
			return (exit_msg("Sprite files opening error."));
	}
	else if (line[i] == '1')
		return (2);
	else
		return (ERROR);
	return (SUCCESS);
}

static int	check_chars(char *line, int i)
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

static int	parse_options(char *line, int fd, int status)
{
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

static int	check_sprites(void)
{
	if (!g_game.texture.nord.path || !g_game.texture.south.path
		|| !g_game.texture.west.path || !g_game.texture.east.path)
		return (ERROR);
	if (g_game.window.width == -1 || g_game.window.height == -1)
	{
		g_game.window.width = SCREEN_W;
		g_game.window.height = SCREEN_H;
	}
	return (SUCCESS);
}

int	get_map_options()
{
	g_game.fd = open(g_game.pathmap, O_RDONLY);
	if (g_game.fd < 0)
		return (exit_msg("Couldn't open map file."));
	if (parse_options(NULL, g_game.fd, 0) == ERROR)
		return (ERROR);
	if (check_sprites() == ERROR)
		return (exit_msg("Not enough parameters to start."));
	return (SUCCESS);
}
