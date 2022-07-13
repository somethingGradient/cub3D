/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akitty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:32:52 by akitty            #+#    #+#             */
/*   Updated: 2021/10/24 15:32:53 by akitty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	check_n(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static char	*check_buf(char **rem)
{
	size_t	i;
	char	*line;
	char	*temp;

	line = NULL;
	if (ft_strchr(*rem + 1, '\n'))
	{
		line = ft_strdup(*rem + 1);
		i = check_n(line);
		line[i + 1] = '\0';
		temp = *rem;
		*rem = ft_substr(*rem, i + 1, ft_strlen(*rem) - i);
		free (temp);
	}
	else
	{
		line = ft_strdup(*rem + 1);
		temp = *rem;
		*rem = ft_substr(*rem, ft_strlen(*rem), 0);
		free (temp);
	}
	return (line);
}

static int	read_file(char **buf, char **result, char **rem, int fd)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	while (!ft_strchr(*result, '\n') && bytes)
	{
		bytes = read(fd, *buf, BUFFER_SIZE);
		(*buf)[bytes] = '\0';
		temp = *result;
		*result = ft_strjoin(*result, *buf);
		free(temp);
		temp = NULL;
		temp = *rem;
		*rem = ft_strdup(ft_strchr(*buf, '\n'));
		free (temp);
		if (*rem)
		{
			(*result)[check_n(*result) + 1] = '\0';
			break ;
		}
	}
	if (!bytes && !ft_strlen(*result))
		return (-1);
	return (1);
}

static int	check_params(int fd, char **buf)
{
	int	n;

	*buf = (char *)malloc(BUFFER_SIZE + 1);
	if (read(fd, 0, 0) || fd < 0 || BUFFER_SIZE <= 0 || !(*buf))
	{
		free (*buf);
		return (0);
	}
	n = 0;
	while (n < BUFFER_SIZE)
		(*buf)[n++] = 0;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rem[1024];
	char		*buf;
	char		*result;
	int			r;

	buf = NULL;
	result = NULL;
	if (!check_params(fd, &buf))
		return (NULL);
	if (rem[fd])
		result = check_buf(&rem[fd]);
	else
		result = ft_strdup(buf);
	if (ft_strchr(result, '\n') == NULL)
	{
		r = read_file(&buf, &result, &rem[fd], fd);
		if (r == -1)
		{
			free (buf);
			free (result);
			return (NULL);
		}
	}
	free (buf);
	return (result);
}
