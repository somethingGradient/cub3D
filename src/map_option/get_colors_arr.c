
#include "../../includes/cub3D.h"

int	get_color_arr(char *line, int i, char *temp_str, char ***temp_arr)
{
	int	k;

	temp_str = ft_substr(line, i, ft_strlen(line) - i - 1);
	if (!temp_str)
		return (ERROR);
	(*temp_arr) = ft_split(temp_str, ',');
	free(temp_str);
	if (!(*temp_arr))
		return (ERROR);
	i = -1;
	while (++i < 3)
	{
		k = -1;
		while ((*temp_arr)[i][++k])
		{
			if (!ft_isdigit((*temp_arr)[i][k]))
			{
				free_2d((void **)(*temp_arr));
				return (ERROR);
			}
		}
	}
	return (SUCCESS);
}

int	malloc_color_arr(char chosen_char)
{
	if (chosen_char == 'F')
	{
		if (g_game.texture.floor_color != NULL)
			return (ERROR);
		g_game.texture.floor_color = (int *)malloc(sizeof(int) * 3);
		if (!g_game.texture.floor_color)
			return (ERROR);
	}
	if (chosen_char == 'C')
	{
		if (g_game.texture.ceil_color != NULL)
			return (ERROR);
		g_game.texture.ceil_color = (int *)malloc(sizeof(int) * 3);
		if (!g_game.texture.ceil_color)
			return (ERROR);
	}
	return (SUCCESS);
}

int	put_color(char **temp_arr, char chosen_char)
{
	int	i;

	if (malloc_color_arr(chosen_char) == ERROR)
		return (ERROR);
	i = -1;
	while (temp_arr[++i] && chosen_char == 'F')
	{
		g_game.texture.floor_color[i] = ft_atoi(temp_arr[i]);
		if (g_game.texture.floor_color[i] > 255
			|| g_game.texture.floor_color[i] < 0)
			return (ERROR);
	}
	i = -1;
	while (temp_arr[++i] && chosen_char == 'C')
	{
		g_game.texture.ceil_color[i] = ft_atoi(temp_arr[i]);
		if (g_game.texture.ceil_color[i] > 255
			|| g_game.texture.ceil_color[i] < 0)
			return (ERROR);
	}
	return (SUCCESS);
}

int get_colors_arr(char *line, int i, char chosen_char)
{
	char	**temp_arr;

	temp_arr = NULL;
	while (line[++i])
	{
		if (ft_isdigit(line[i]))
			break ;
		if (line[i] != ' ')
			return (ERROR);
	}
	if (get_color_arr(line, i, NULL, &temp_arr) == ERROR)
		return (ERROR);
	if (put_color(temp_arr, chosen_char) == ERROR)
	{
		free_2d((void **)temp_arr);
		return (ERROR);
	}
	free_2d((void **)temp_arr);
	return (SUCCESS);
}