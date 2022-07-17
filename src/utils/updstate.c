#include "../../includes/cub3D.h"

int		updstate(void)
{
	static int		state = 0;

	state++;
	return (state);
}