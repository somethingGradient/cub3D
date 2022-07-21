#include "../../includes/cub3D.h"

void	next_map(void)
{
	char	*argv[3];

	ft_putstr_fd("-------------------------------------------\nNext level...\n", 1);
	if (g_game.next != NULL)
	{
		argv[0] = g_game.exec;
		argv[1] = g_game.next;
		argv[2] = 0;
		execv(g_game.exec, argv);
	}
	game_end();
}