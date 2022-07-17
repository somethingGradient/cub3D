#include "../../includes/cub3D.h"

t_color	create_tcolor(int color)
{
	t_color		newcolor;

	newcolor.b = color % 1000;
	color /= 1000;
	newcolor.g = color % 1000;
	color /= 1000;
	newcolor.r = color % 1000;
	return (newcolor);
}

t_color	create_rgbcolor(char c)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if (c == 'r')
		color.r = 255;
	else if (c == 'l')
		color.r = 204;
	else if (c == 'g')
		color.g = 255;
	else if (c == 'b')
		color.b = 255;
	return (color);
}