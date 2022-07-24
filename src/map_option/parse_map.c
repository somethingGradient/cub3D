/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 21:27:22 by ybayart           #+#    #+#             */
/*   Updated: 2019/11/16 02:52:39 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int		parse_map_line(char **opts, int nbopts)
{
	if (ft_strcmp(opts[0], "R") == 0)
		return (parse_map_opts_r(opts, nbopts));
	else if (ft_strcmp(opts[0], "NO") == 0)
		return (parse_map_opts_t(opts, nbopts, 'N'));
	else if (ft_strcmp(opts[0], "SO") == 0)
		return (parse_map_opts_t(opts, nbopts, 'S'));
	else if (ft_strcmp(opts[0], "WE") == 0)
		return (parse_map_opts_t(opts, nbopts, 'W'));
	else if (ft_strcmp(opts[0], "EA") == 0)
		return (parse_map_opts_t(opts, nbopts, 'E'));
	else if (ft_strcmp(opts[0], "S") == 0)
		return (parse_map_opts_t(opts, nbopts, 'O'));
	else if (ft_strcmp(opts[0], "F") == 0)
		return (parse_map_opts_t(opts, nbopts, 'F'));
	else if (ft_strcmp(opts[0], "C") == 0)
		return (parse_map_opts_t(opts, nbopts, 'C'));
	else if (ft_strcmp(opts[0], "NE") == 0)
		return (parse_map_opts_n(opts, nbopts));
	else if (ft_strcmp(opts[0], "LI") == 0)
		return (parse_map_opts_l(opts, nbopts));
	else
		return (0);
	return (1);
}

int		gest_line(char *line)
{
	int		nbopts;
	char	**opts;

	opts = NULL;
	if (line[0] != '\n' && (opts = ft_split(line, ' ')) != 0)
	{
		if ((nbopts = ft_nbwords(opts)) >= 2)
		{
			if (parse_map_line(opts, nbopts) == 0)
			{
				free_2d((void**)opts);
				return (0);
			}
		}
		else if (nbopts != 0)
		{
			free_2d((void**)opts);
			return (0);
		}
		free_2d((void**)opts);
	}
	return (1);
}

int		parse_map(void)
{
	int		loop;
	char	*line;

	loop = 1;
	line = NULL;
	//printf("|lol|\n");
	while (loop)
	{
		line = get_next_line(g_game.fd);
		printf("%s\n", line);
		if (line == NULL)
		{
			printf("|break|\n");
			break;
		}
		if (gest_line(line) == 0 && parse_map_matrix(line) == 0)
		{
			free(line);
			return (error_msg("parsemap"));
		}
		free(line);
	}
	return (1);
}
