
#include "../../includes/cub3D.h"

int resolution_aux(t_map *options, char *str, char *temp, int i, int k)
{
    if (options->R_width == -1 && options->R_height == -1)
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
			if (options->R_width == -1)
			{
				options->R_width = ft_atoi(temp);
				if (options->R_width <= 0)
					return (ERROR);
			}
			free(temp);
			options->R_height = ft_atoi(str + k + 1);
			if (options->R_height <= 0)
				return (ERROR);
			i += k;
		}
	}
	else
		return (ERROR);
}

int	get_resolution(t_map *options, char *line, int i, char *temp, int k)
{
	if (line[i] == 'R')
	{
		i = 0;
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
	}
	else
		return (SUCCESS);
	i = -1;
    if (resolution_aux(options, temp, NULL, i, k) == ERROR)
        free(temp);
    free(temp);
}