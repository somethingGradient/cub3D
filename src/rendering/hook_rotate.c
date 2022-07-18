#include "../../includes/cub3D.h"

void	hook_rotate(int key, double initrot)
{
	t_draw	*d;
	double	rot;

	rot = ((initrot == 0) ? ROT : initrot);
	d = &g_data.draw;
	if (key == ARROW_LEFT)
	{
		d->old_dir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(rot) - d->dir_y * sin(rot);
		d->dir_y = d->old_dir_x * sin(rot) + d->dir_y * cos(rot);
		d->old_plane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(rot) - d->plane_y * sin(rot);
		d->plane_y = d->old_plane_x * sin(rot) + d->plane_y * cos(rot);
	}
	else
	{
		d->old_dir_x = d->dir_x;
		d->dir_x = d->dir_x * cos(-rot) - d->dir_y * sin(-rot);
		d->dir_y = d->old_dir_x * sin(-rot) + d->dir_y * cos(-rot);
		d->old_plane_x = d->plane_x;
		d->plane_x = d->plane_x * cos(-rot) - d->plane_y * sin(-rot);
		d->plane_y = d->old_plane_x * sin(-rot) + d->plane_y * cos(-rot);
	}
}