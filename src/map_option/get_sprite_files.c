
#include "../../includes/cub3D.h"

int put_vector(char **vector, char *line, int i)
{
	if ((*vector) == NULL)
	{
		(*vector) = ft_substr(line, i, ft_strlen(line) - i - 1);
		if ((*vector) == NULL)
			return (ERROR);
		i = -1;
		while ((*vector)[++i])
		{
			if ((*vector)[i] == ' ')
				return (ERROR);
		}
		if (access((*vector), 0) == -1
			|| access((*vector), 3) == -1)
			return (ERROR);
	}
	else
		return (ERROR);
	return (SUCCESS);
}

int	get_element_by_sprites(char **vector, char *line, int i, char first_char, char second_char)
{
	if (line[i++] == first_char)
	{
		if (line[i++] == second_char)
		{
			while (line[i] == ' ')
				i++;
			if (put_vector(vector, line, i) == ERROR)
				return (ERROR);
		}
	}
	return (SUCCESS);
}

int	get_sprites(char *line, int i)
{
	if (line[i] != 'R' && line[i] != 'F' && line[i] != 'C')
	{
		if (get_element_by_sprites(&(g_game.texture.nord.path), line, i, 'N', 'O') == ERROR
			|| get_element_by_sprites(&(g_game.texture.south.path), line, i, 'S', 'O') == ERROR
			|| get_element_by_sprites(&(g_game.texture.west.path), line, i, 'W', 'E') == ERROR
			|| get_element_by_sprites(&(g_game.texture.east.path), line, i, 'E', 'A') == ERROR
			|| get_element_by_sprites(&(g_game.texture.sprite.path), line, i, 'S', ' ') == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}
