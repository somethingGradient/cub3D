#include "../../includes/cub3D.h"

int		error_msg(char *context)
{
	if (ft_strcmp(context, "parsemap") == 0)
		g_game.error = "Couldn't parse map file";
	else if (ft_strcmp(context, "openmap") == 0)
		g_game.error = "Couldn't open map file";
	else if (ft_strcmp(context, "entrymap") == 0)
		g_game.error = "No entry for map";
	else if (ft_strcmp(context, "saveopt") == 0)
		g_game.error = "Save flag are incorrect";
	else if (ft_strcmp(context, "missinfo") == 0)
		g_game.error = "Some informations are missing into map file";
	else if (ft_strcmp(context, "opentext") == 0)
		g_game.error = "Couldn't open texture file";
	else
		g_game.error = "Unknown error";
	return (0);
}