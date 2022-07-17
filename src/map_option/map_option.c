#include "../../includes/cub3D.h"

static int	read_map_file(int fd, char **result, int i)
{
	char	c;
	char	str[5000];
	int		bytes;

	if (read(fd, 0, 0) == -1 || fd < 0)
		return (ERROR);
	bytes = 1;
	i = 0;
	while (bytes)
	{
		bytes = read(fd, &c, 1);
		str[i++] = c;
	}
	(*result) = (char *)malloc(sizeof(char) * i + 1);
	if (!(*result))
		return (ERROR);
	bytes = -1;
	while (++bytes < i)
		(*result)[bytes] = str[bytes];
	(*result)[bytes - 1] = '\0';
	return (SUCCESS);
}

int get_element_by_sprites(char **vector, char *line, int i, char first_char, char second_char)
{
	if (line[i++] == first_char)
	{
		if (line[i++] == second_char)
		{
			while (line[i] == ' ')
				i++;
			if ((*vector) == NULL)
			{
				*vector = ft_substr(line, i, ft_strlen(*vector) - i);
				if (*vector == NULL)

					return (ERROR);
				i = -1;
				while ((*vector)[++i])
				{
					if ((*vector)[i] == ' ')
						return (ERROR);
				}
				if (access(*vector, 0) == -1 || access(*vector, 3) == -1)
					return (ERROR);
			}
			else
				return (ERROR);
		}
	}
}

int	get_sprites(t_map *options, char *line, int i)
{
	if (line[i] != 'R' && line[i] != 'F' && line[i] != 'C')
	{
		if (get_element_by_sprites(&options->nord, line, i, 'N', 'O') == ERROR
			|| get_element_by_sprites(&options->south, line, i, 'S', 'O') == ERROR
			|| get_element_by_sprites(&options->west, line, i, 'W', 'E') == ERROR
			|| get_element_by_sprites(&options->east, line, i, 'E', 'A') == ERROR
			|| get_element_by_sprites(&options->sprite, line, i, 'S', ' ') == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	check_chars(t_map *options, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ')
			continue ;
		if (line[i] == 'R' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == 'E'
			|| line[i] == 'F' || line[i] == 'C')
		{
			if (get_resolution(options, line, i, NULL, -1) == ERROR
				|| get_sprites(options, line, i) == ERROR)
				return (ERROR);
			return (SUCCESS);
		}
		if (line[i] == '1')
			return (2);
		if (line[i] != ' ' && line[i] != '\n')
			return (ERROR);
		if (line[i] == '\n')
			break ;
	}
	return (SUCCESS);
}

int	init_map_options(t_game *game)
{
	t_map	*options;

	options = NULL;
	options = (t_map *)malloc(sizeof(*options));
	if (!options)
		return (ERROR);
	options->nord = NULL;
	options->south = NULL;
	options->west = NULL;
	options->east = NULL;
	options->sprite = NULL;
	options->floor = NULL;
	options->ceil = NULL;
	options->R_width = -1;
	options->R_height = -1;
	game->options = options;
	game->map = NULL;
	options = NULL;
}

int	parse_options(t_map *options, char *map_tmp, int i, int k, char *line, int fd)
{
	int status;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 2)
		{
			status = check_chars(options, line);
			if (status == 2)
			{
				free(line);
				return (SUCCESS);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (ERROR);
}

char	**malloc_map(char *filename)
{
	int		fd_for_lines;
	int		count_lines;
	char	*line;
	char	**map;

	line = NULL;
	map = NULL;
	fd_for_lines = open(filename, O_RDONLY);
	if (fd_for_lines < 0)
		return (NULL);
	count_lines = 0;
	line = get_next_line(fd_for_lines);
	int i =-1;
	char *temp = NULL;
	while (line)
	{
		i = -1;
		while (line[++i] && !temp)
		{
			if (line[i] == ' ')
				continue ;
			if (line[i] != '1')
				break ;
			if (line[i] == '1')
				temp = ft_strdup(line);
		}
		count_lines++;
		free(line);
		line = get_next_line(fd_for_lines);
	}
	close(fd_for_lines);
	map = (char **)malloc(sizeof(char *) * count_lines + 1);
	if (!map)
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
}

int	get_map_options(t_game *game, char *filename)
{
	int		fd;
	char	*temp;

	temp = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	if (init_map_options(game) == ERROR)
	{
		printf("Error init map.");
		return (ERROR);
	}
	parse_options(game->options, temp, -1, -1, NULL, fd);
	
	game->map = malloc_map(filename);
	get_map(game, fd);


	// printf("%d\n", game->options->R_width);
	// printf("%d\n", game->options->R_height);
	// printf("%s", game->options->nord);
	// printf("%s", game->options->south);
	// printf("%s", game->options->west);
	// printf("%s", game->options->east);
	// printf("%s", game->options->sprite);


	close(fd);
	free(temp);
	
	return (SUCCESS);
}
