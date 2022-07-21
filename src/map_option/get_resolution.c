
#include "../../includes/cub3D.h"

static int resolution_aux(char *str, char *temp, int i, int k)
{
	while (str[++i] && str[i] != '\n')
	{
		k = -1;
		while (str[++k] != ' ')
		{
			if (!ft_isdigit(str[k]))
				return (ERROR);
		}
		temp = ft_substr(str, i, k);
		if (g_game.window.width == -1)
		{
			g_game.window.width = ft_atoi(temp);
			if (g_game.window.width <= 0)
				return (ERROR);
		}
		free(temp);
		g_game.window.height = ft_atoi(str + k + 1);
		if (g_game.window.height <= 0)
			return (ERROR);
		i += k;
	}
	return (SUCCESS);
}

int	get_resolution(char *line, int i, char *temp)
{
	int	status;

	if (line[i] == 'R')
	{
		while (!ft_isdigit(line[++i]))
		{
			if (line[i] == ' ')
				continue ;
			if (!ft_isdigit(line[i]))
				return (ERROR);
		}
		temp = ft_substr(line, i, ft_strlen(line) - i);
		if (!temp)
			return (ERROR);
		if (g_game.window.width == -1 && g_game.window.height == -1)
			status = resolution_aux(temp, NULL, -1, -1);
		else
			status = ERROR;
	}
	else
		return (SUCCESS);
	free(temp);
	return (status);
}
