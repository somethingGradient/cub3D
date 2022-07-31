#ifndef CUB3D_GAME_H
# define CUB3D_GAME_H

# include "cub3D_structs.h"

char	*init_game(t_cub_data *cub, t_game *game);

void	launch_game(t_game *game);

void	player_rotate(t_game *game, double d_angle);

void	player_move(t_game *game, double speed, double angle);

void	destroy_game(t_game *game, bool quit);

#endif
