
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

int	get_resolution_aux(t_map *options, char *temp, char *str)
{
	int	i;
	int	k;

	// if (options->R_width == -1 && options->R_height == -1)
	// {
		i = -1;
		while (str[++i] && str[i] != '\n')
		{
			k = -1;
			while (str[++k] != ' ')
			{
				if (!ft_isdigit(str[k]))
				{
					printf("Ошибка в настройках размера окна.\n");
					free(str);
					str = NULL;
					return (ERROR);
				}
			}
			temp = ft_substr(str, i, k);
			i += k;
			if (options->R_width == -1)
			{
				options->R_width = ft_atoi(temp);
				if (options->R_width <= 0)
				{
					printf("Некорректная ширина окна.\n");
					free(temp);
					free(str);
					str = NULL;
					return (ERROR);
				}
			}

			free(temp);
			options->R_height = ft_atoi(temp);
			if (options->R_height <= 0)
			{
				printf("Некорректная высота окна.\n");
				free(temp);
				free(str);
				str = NULL;
				return (ERROR);
			}
			free(temp);
		}
		free(str);
	// }
}

int	get_resolution(t_map *options, char *line, int i)
{
	char	*str;
	int		k;

	str = NULL;
	if (line[i] == 'R')
	{
		i = 0;
		while (!ft_isdigit(line[++i]))
		{
			if (line[i] == ' ')
				continue ;
			if (!ft_isdigit(line[i]))
			{
				printf("Ошибка в настройках размера окна №1.\n");
				return (ERROR);
			}
		}
		str = ft_substr(line, i, ft_strlen(line) - i);
		if (!str)
			return (ERROR);
	}
	else
		return (SUCCESS);
	i = -1;
	if (options->R_width == -1 && options->R_height == -1)
	{
		while (str[++i] && str[i] != '\n')
		{
			k = -1;
			while (str[++k] != ' ')
			{  
				if (!ft_isdigit(str[k]))
				{
					printf("Ошибка в настройках размера окна №2.\n");
					free(str);
					str = NULL;
					return (ERROR);
				}
			}
			line = ft_substr(str, i, k);
			if (options->R_width == -1)
			{
				options->R_width = ft_atoi(line);
				if (options->R_width <= 0)
				{
					printf("Некорректная ширина окна.\n");
					free(str);
					str = NULL;
					return (ERROR);
				}
			}
			free(line);
			options->R_height = ft_atoi(str + k + 1);
			if (options->R_height <= 0)
			{
				printf("Некорректная высота окна.\n");
				free(str);
				str = NULL;
				return (ERROR);
			}
			i += k;
			
		}
		free(str);
	}
	else
	{
		free(str);
		printf("Дубликация параметров окна.\n");
		return (ERROR);
	}
}

int get_element_by_sprites(char **vector, char *line, int i, char first_char, char second_char)
{
	if (line[i++] == first_char)
	{
		if (line[i] == second_char && line[i++] != ' ')
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
				printf("|%s|\n", *vector);
				if (access(*vector, 0) == -1 || access(*vector, 3) == -1)
				{
					printf("Файл спрайта недоступен.\n");
					return (ERROR);
				}
			}
			else
			{
				printf("Дубликация параметра спрайта.\n");
				return (ERROR);
			}
		}
		else
		{
			printf("Ошибка в названии параметра.\n");
			return (ERROR);
		}
	}
	else
		return (SUCCESS);
}

int	get_sprites(t_map *options, char *line, int i)
{
	char	*temp;
	int		k;

	if (get_element_by_sprites(&options->nord, line, i, 'N', 'O') == ERROR
		|| get_element_by_sprites(&options->south, line, i, 'S', 'O') == ERROR
		|| get_element_by_sprites(&options->west, line, i, 'W', 'E') == ERROR
		|| get_element_by_sprites(&options->east, line, i, 'E', 'A') == ERROR
		|| get_element_by_sprites(&options->sprite, line, i, 'S', ' ') == ERROR)
	{

		printf("Ошибка в настройке спрайтов.");
		return (ERROR);
	}

}

t_bool check_chars(t_map *options, char *line)
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
			get_resolution(options, line, i);

			if (get_sprites(options, line, i) == -1)
				return (ERROR);

			return (SUCCESS);
		}
		if (line[i] == '1')
			return (2);
		if (line[i] != ' ' && line[i] != '\n')
		{
			printf("Лишний символ в строке.\n");
			return (ERROR);
		}
		if (line[i] == '\n')
			break ;
	}
	return (SUCCESS);
}


int	get_map_options(t_game *game, char *filename)
{
	int	fd;
	char *temp = NULL;
	t_map	*options;

	temp = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	if (read_map_file(fd, &temp, 0) == ERROR)
	{
		printf("Error in reading map.");
		return (ERROR);
	}
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


	char *line = NULL;
	int k = -1;
	int	i = -1;
	while (temp[++i])
	{
		k = i - 1;
		while (temp[++k])
		{
			if (temp[k] == '\n')
				break ;
		}
		line = NULL;
		line = ft_substr(temp, i, k - i);

		if (ft_strlen(line) > 2)
		{
			if (check_chars(options, line) == ERROR)
				return (ERROR);

		}
		


		free(line);
		i = k;
	}
	printf("|%s|\n", options->nord);
	// printf("%d %d\n", options->R_width, options->R_height);

	/*
	temp = get_next_line(fd);
	while (temp)
	{
		if (ft_strlen(temp) > 2)
		{
			flag = che+-ck_chars(temp);
			if (flag == ERROR)
			{
				printf("Лишний символ.\n");
				free(options);
				free(temp);
				temp = NULL;
				return (ERROR);
			}
			else if (flag == 2)
				break ;
			// if (get_resolution(options, temp) == ERROR)
			// {
			// 	// printf("Лишний символ в пустой строке.\n");
			// 	free(options);
			// 	free(temp);
			// 	return (ERROR);
			// }
	// 		// if (temp[0] == 'R' && temp[1] == ' ')
	// 		// 	value = ft_substr(temp, 2, ft_strlen(temp) - 3);
	// 		// get_resolution(options, temp);

	// 		// else if (temp[0] == 'S' && temp[1] == ' ')
	// 		// 	value = ft_substr(temp, 2, ft_strlen(temp) - 3);

	// 		// else if (temp[0] == 'F' && temp[1] == ' ')
	// 		// 	value = ft_substr(temp, 2, ft_strlen(temp) - 3);

	// 		// else if (temp[0] == 'C' && temp[1] == ' ')
	// 		// 	value = ft_substr(temp, 2, ft_strlen(temp) - 3);

	// 		// else if (temp[0] == 'N' && temp[1] == 'O' && temp[2] == ' ')
	// 		// 	value = ft_substr(temp, 3, ft_strlen(temp) - 4);

	// 		// else if (temp[0] == 'S' && temp[1] == 'O' && temp[2] == ' ')
	// 		// 	value = ft_substr(temp, 3, ft_strlen(temp) - 4);

	// 		// else if (temp[0] == 'W' && temp[1] == 'E' && temp[2] == ' ')
	// 		// 	value = ft_substr(temp, 3, ft_strlen(temp) - 4);

	// 		// else if (temp[0] == 'E' && temp[1] == 'A' && temp[2] == ' ')
	// 		// 	value = ft_substr(temp, 3, ft_strlen(temp) - 4);

	// 		// else
	// 		// 	printf("Bad params.\n");

	// 		// printf("|%s|", temp);

		
		}
		free(temp);
		temp = get_next_line(fd);
		// printf("%s\n", value);
	}
	*/


// printf("%d %d", options->R_width, options->R_height);

close(fd);
free(temp);
free(options);
return (SUCCESS);
}