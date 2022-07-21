
#include "../../includes/cub3D.h"

char *find_first_wall(int fd, char *temp, int i, int *count_lines)
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

char	**malloc_map(char *filename)
{
	int		fd_for_lines;
	int		count_lines;
	char	**map;
	char *temp;

	map = NULL;
	fd_for_lines = open(filename, O_RDONLY);
	if (fd_for_lines < 0)
		return (NULL);
	temp = find_first_wall(fd_for_lines, NULL, -1, &count_lines);
	map = (char **)malloc(sizeof(char *) * count_lines + 1);
	if (!map || !temp)
		return (NULL);
	map[0] = temp;
	temp = NULL;
	map[count_lines] = NULL;
	return (map);
}

int	get_map(t_game *game, int fd)
{
	char	*line;
	int		i;

	line = NULL;
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		game->map[++i] = line;
		line = NULL;
		line = get_next_line(fd);
	}
	return (SUCCESS);
}