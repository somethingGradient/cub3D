#include "../includes/cub3D.h"

t_color	create_tgrb(t_color t, t_color r, t_color g, t_color b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_px(int x, int y, t_color color, t_img *img)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp >> 3));
	*(t_color *)dst = color;
}

t_color	get_px(int x, int y, t_img *img)
{
	char	*dst;

	dst = img->addr + (y * img->line + x * (img->bpp >> 3));
	return (*((t_color *)dst));
}
