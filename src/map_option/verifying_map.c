#include "../../includes/cub3D.h"

static int	check_closing(char *line, int k, int i, int arr_len)
{
	if (i == 0 || i == arr_len - 1)
	{
		while (line[++k])
		{
			if (line[k] == ' '  || line[k] == '\n'
				|| line[k] == '1')
				continue ;
			else
				return (ERROR);
		}
	}
	k = -1;
	while (line[++k])
	{
		if (line[k] == ' ')
			continue ;
		if (line[k] != '1')
			return (ERROR);
		else
			break ;
	}
	if (line[ft_strlen(line) - 2] != '1')
		return (ERROR);
	return (SUCCESS);
}

static int	check_closing_col_aux(int i, int k)
{
	if (g_game.map[i - 1])
	{
		if (g_game.map[i - 1][k])
		{
			if (g_game.map[i - 1][k] != ' '
				&& g_game.map[i - 1][k] != '1'
				&& g_game.map[i - 1][k] != '\n')
				return (ERROR);
		}
	}
	if (g_game.map[i + 1])
	{
		if (g_game.map[i + 1][k])
		{
			if (g_game.map[i + 1][k] != ' '
				&& g_game.map[i + 1][k] != '1'
				&& g_game.map[i + 1][k] != '\n')
				return (ERROR);
		}
	}
	return (SUCCESS);
}

static int	check_closing_col(int i, int k, int arr_len)
{
	if (i == 0 || i == arr_len - 1)
		return (SUCCESS);
	while (g_game.map[i][++k])
	{
		if (g_game.map[i][k] == '0')
		{
			if (!g_game.map[i - 1][k] || !g_game.map[i + 1][k])
				return (ERROR);
		}
		if (g_game.map[i][k] == ' ')
		{
			if (check_closing_col_aux(i, k) == ERROR)
				return (ERROR);
		}
	}
	return (SUCCESS);
}

static int	check_closing_row(int i, char *line, int k, int arr_len)
{
	if (i == 0 || i == arr_len - 1)
		return (SUCCESS);
	while (line[++k])
	{
		if (line[k] == ' ')
		{
			if (line[k + 1] && ((k + 1) < ft_strlen(line)))
			{
				if (line[k + 1] != '1' && line[k + 1] != ' ' && line[k + 1] != '\n')
					return (ERROR);
			}
			if (line[k - 1] && k != 0)
			{
				if (line[k - 1] != '1' && line[k - 1] != ' ' && line[k - 1] != '\n')
					return (ERROR);
			}
			continue ;
		}
	}
	return (SUCCESS);
}

int		get_pos(int n)
{
	static int	i = 0;

	i += n;
	return (i);
}

static int	check_allowing_chars(char *line, int i, int k)
{
	while (line[++k])
	{
		if (line[k] == ' ' || line[k] == '\n'
			|| line[k] == '0' || line[k] == '1')
			continue ;
		else if (line[k] == '2')
		{
			if (g_game.texture.sprite.path == NULL)
			{
				printf("Sprite's params isn't correct.");
				return (ERROR);
			}
			continue ;
		}
		else if (line[k] == 'N' || line[k] == 'S'
				|| line[k] == 'W' || line[k] == 'E')
		{
			if (g_game.posx == -1 && g_game.posy == -1)
			{
				g_game.posx = get_pos(0) + 0.5;
				g_game.posy = i + 0.5;
				continue ;
			}
			else
				return (ERROR);
		}
		else
			return (ERROR);
	}
	return (SUCCESS);
}

int	verifying_map(void)
{
	int i;
	int arr_len;

	i = -1;
	arr_len = ft_tablen((void **)g_game.map);
	while (g_game.map[++i])
	{
		if (check_closing(g_game.map[i], -1, i, arr_len) == ERROR)
			return (exit_msg("Map not closed."));
		if (check_closing_col(i, -1, arr_len) == ERROR)
			return (exit_msg("Map not closed. COL."));
		if (check_closing_row(i, g_game.map[i], -1, arr_len) == ERROR)
			return (exit_msg("Map not closed. ROW."));
		if (check_allowing_chars(g_game.map[i], i, -1) == ERROR)
			return (exit_msg("The map includes unexpected symbols."));
	}
	return (SUCCESS);
}