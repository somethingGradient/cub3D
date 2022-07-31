/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <jannabel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:39:10 by jannabel          #+#    #+#             */
/*   Updated: 2022/07/31 20:39:11 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*skip_chars(char *str, char c)
{
	if (str)
	{
		while (*str == c)
			str++;
	}
	return (str);
}

bool	str_has_charset(char *str, char *charset)
{
	if (!str || !charset)
		return (false);
	if (*charset == 0)
		return (true);
	while (*charset)
		if (ft_strchr(str, *(charset++)))
			return (true);
	return (false);
}

bool	array_has_str(char *str, char **arr)
{
	if (!str || !arr)
		return (false);
	while (*arr)
	{
		if (!ft_strcmp(str, *arr))
			return (true);
		arr++;
	}
	return (false);
}

bool	check_file_ext(char *fname, char *ext)
{
	size_t	len;

	if (!fname || !ext)
		return (false);
	len = ft_strlen(fname);
	if (len < ft_strlen(ext) + 1)
		return (false);
	if (ft_strcmp(ext, &fname[len - 4]))
		return (false);
	return (true);
}

bool	can_read_file(char *fname)
{
	int		fd;
	long	br;
	char	c;

	if (!fname)
		return (false);
	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (false);
	br = read(fd, &c, 1);
	close(fd);
	return (br == 1);
}
