#include "../../includes/cub3D.h"

int		print_error(void)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(g_game.error, 1);
	if (g_game.iserrno == 1)
	{
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(strerror(errno), 1);
	}
	ft_putchar_fd('\n', 1);
	return (1);
}
