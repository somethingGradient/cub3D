#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"

#include "../mlx_linux/mlx.h"
#include "../mlx_mac/mlx.h"

#include <stdlib.h>
#include <sys/errno.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define ERROR -1

# define BUFFER_SIZE 42

typedef char t_bool;

typedef struct	s_game
{
	int a;
}	t_game;


typedef struct	s_map
{
	int		R_width;
	int		R_height;

	char	*nord;
	char	*south;
	char	*west;
	char	*east;

	char	*sprite;
	char	*floor;
	char	*ceil;
}	t_map;

char	*get_next_line(int fd);




int	get_map_options(t_game *game, char *filename);

#endif
