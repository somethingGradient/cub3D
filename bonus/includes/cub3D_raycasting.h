#ifndef CUB3D_RAYCASTING_H
# define CUB3D_RAYCASTING_H

# include "cub3D_structs.h"

void	ray_casting(t_game *game, t_ray *rays);

void	calculate_ray(t_game *game, t_ray *ray);

void	get_line_equation(t_vector *pt, double angle, t_line *line);

double	get_intercept(t_line *line, double val, bool y_line);

double	distance_points(t_vector *p1, t_vector *p2);

#endif