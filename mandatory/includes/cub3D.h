#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

# include "libft.h"

# include "cub3D_errors.h"
# include "cub3D_defines.h"
# include "cub3D_game.h"
# include "cub3D_file_handlers.h"
# include "cub3D_graphics.h"
# include "cub3D_raycasting.h"

# ifdef __linux__
#  include "mlx_linux.h"
#  define USING_LINUX	1

# else
#  include "mlx_mac.h"
#  define USING_LINUX	0

int		mlx_destroy_display(void *mlx_ptr);

# endif

/*	==== MISC FUNCTIONS ==== */

size_t	array_size(void **arr);

int		max_list_str_len(t_list *lst);

void	free_tab(char **tab);

void	error_then_exit(char *fname, char *msg);

#endif
