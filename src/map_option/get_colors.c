
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
	while ((*temp_arr)[++i])
	{
		k = -1;
		while ((*temp_arr)[i][++k])
		{
			if (!ft_isdigit((*temp_arr)[i][k]) || i > 2)
			{
				free_2d((void **)(*temp_arr));
				return (ERROR);
			}
		}
	}
	return (SUCCESS);
}

int	put_color(char **temp_arr, char chosen_char)
{
	t_color	*temp;

	temp = NULL;
	if (chosen_char == 'F')
		temp = &g_game.texture.floor;
	if (chosen_char == 'C')
		temp = &g_game.texture.ceil;
	temp->r = ft_atoi(temp_arr[0]);
	temp->g = ft_atoi(temp_arr[1]);
	temp->b = ft_atoi(temp_arr[2]);
	free_2d((void **)temp_arr);
	if (temp->r > 255 || temp->r < 0
		|| temp->g > 255 || temp->g < 0
		|| temp->b > 255 || temp->b < 0)
		return (ERROR);
	temp = NULL;
	return (SUCCESS);
}

int get_color(char *line, int i, char chosen_char)
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
	if (ft_tablen((void **)temp_arr) != 3)
		return (ERROR);
	if (put_color(temp_arr, chosen_char) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
