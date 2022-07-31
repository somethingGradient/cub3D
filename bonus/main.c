/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <jannabel@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 20:42:26 by jannabel          #+#    #+#             */
/*   Updated: 2022/07/31 20:42:27 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

static inline void	initial_arg_checks(int ac, char **av)
{
	if (ac != 2)
		error_then_exit(NULL, ARG_ERROR);
	if (!check_file_ext(av[1], ".cub"))
		error_then_exit(av[1], NAME_ERROR);
	if (!can_read_file(av[1]))
		error_then_exit(av[1], READ_ERROR);
}

static inline void	launch_parser(char *fname, t_cub_data *cub)
{
	int		fd;
	char	*error;

	fd = open(fname, O_RDONLY);
	init_cub_data(cub);
	error = parse_cub(cub, fd);
	close(fd);
	if (error)
		error_then_exit(fname, error);
}

int	main(int ac, char **av)
{
	char		*error;
	t_cub_data	cub;
	t_game		game;

	initial_arg_checks(ac, av);
	launch_parser(av[1], &cub);
	error = init_game(&cub, &game);
	free_cub_data(&cub);
	if (!error)
		mlx_loop(game.ptr);
	else
	{
		destroy_game(&game, false);
		error_then_exit(NULL, error);
	}
}
