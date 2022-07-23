
#include "../../includes/cub3D.h"

static char	*find_first_wall(int fd, char *temp, int i, int *count_lines)
{
	char	*first_wall;

	first_wall = NULL;
	temp = get_next_line(fd);
	while (temp)
	{
		i = -1;
		while (temp[++i] && !first_wall)
		{
			if (temp[i] == ' ')
				continue ;
			if (temp[i] != '1')
				break ;
			if (temp[i] == '1')
				first_wall = ft_strdup(temp);
		}
		(*count_lines)++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (first_wall);
}

static int	malloc_map(void)
{
	int		fd_for_lines;
	int		count_lines;
	char	*temp;

	temp = NULL;
	fd_for_lines = open(g_game.pathmap, O_RDONLY);
	if (fd_for_lines < 0)
		return (ERROR);
	temp = find_first_wall(fd_for_lines, NULL, -1, &count_lines);
	g_game.map = (char **)malloc(sizeof(char *) * count_lines + 1);
	if (!g_game.map || !temp)
		return (ERROR);
	g_game.map[0] = temp;
	temp = NULL;
	g_game.map[count_lines] = NULL;
	return (SUCCESS);
}

int	get_map(void)
{
	int		i;
	char	*line;

	if (malloc_map() == ERROR)
		return (exit_msg("Error of alloc map."));
	line = NULL;
	line = get_next_line(g_game.fd);
	i = 0;
	while (line)
	{
		g_game.map[++i] = line;
		line = NULL;
		line = get_next_line(g_game.fd);
	}
	close(g_game.fd);
	if (verifying_map() == ERROR)
		return (ERROR);
	return (SUCCESS);
}