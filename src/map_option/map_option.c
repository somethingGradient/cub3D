
#include "../../includes/cub3D.h"

static int	read_map_file(int fd, char **result, int i)
{
	char	c;
	char	str[3000];
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
			return (i);
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
	options = NULL;
}

int	parse_options(t_map *options, char *map_tmp, int i, int k, char *line)
{
	int status;
	int index_begin_map;

	while (map_tmp[++i])
	{
		k = i;
		while (map_tmp[k] && map_tmp[k] != '\n')
			k++;
		line = NULL;
		line = ft_substr(map_tmp, i, k - i);
		if (ft_strlen(line) > 2)
		{
			status = check_chars(options, line);
			if (status > 2)
				index_begin_map = status;
			else if (status == ERROR)
				return (ERROR);
		}
		free(line);
		i = k;
	}
	return (index_begin_map);
}

int	get_map_options(t_game *game, char *filename)
{
	int		fd;
	char	*temp;

	temp = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	if (read_map_file(fd, &temp, 0) == ERROR
		|| init_map_options(game) == ERROR)
	{
		printf("Error init map.");
		return (ERROR);
	}
	printf("|%d|\n", parse_options(game->options, temp, -1, -1, NULL));

close(fd);
free(temp);
free(game->options);
return (SUCCESS);
}
