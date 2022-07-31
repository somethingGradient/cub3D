/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_file_handlers.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <jannabel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:44:33 by jannabel          #+#    #+#             */
/*   Updated: 2022/07/31 20:44:34 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_FILE_HANDLERS_H
# define CUB3D_FILE_HANDLERS_H

# include "cub3D_structs.h"

char	*skip_chars(char *str, char c);

bool	str_has_charset(char *str, char *charset);

bool	array_has_str(char *str, char **arr);

bool	check_file_ext(char *fname, char *ext);

bool	can_read_file(char *fname);

void	init_cub_data(t_cub_data *cub);

void	free_cub_data(t_cub_data *cub);

char	*parse_cub(t_cub_data *cub, int fd);

char	**make_char_map(t_list *raw_map);

char	*check_cub_map(char **map);

#endif