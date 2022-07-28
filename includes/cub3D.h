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
#include <X11/X.h>
#include <math.h>

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define ERROR -1

# define BUFFER_SIZE 42

# define SCREEN_W 480
# define SCREEN_H 320
# define ROT 0.050
# define MOV 0.1
# define COL 2.5
# define MMP_DECA g_game.window.width / 100
# define MMP_SIZE g_game.window.width / 10
# define FOG 7

# define LEFT 97
# define RIGHT 100
# define DOWN 115
# define UP 119

# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364
# define ARROW_UP 65362

# define ESC 65307

typedef char t_bool;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_img
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct	s_xpm
{
	char		*path;
	t_img		img;
	int			height;
	int			width;
}				t_xpm;

typedef struct	s_texture
{
	t_xpm		nord;
	t_xpm		south;
	t_xpm		west;
	t_xpm		east;
	t_xpm		sprite;
	t_color		floor;
	t_color		ceil;
}				t_texture;

typedef struct	s_window
{
	int			*mlx;
	int			*win;
	int			height;
	int			width;
}				t_window;

typedef struct	s_draw
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			h;
	int			w;
	int			x;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	t_color		color;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		old_dir_x;
	double		old_plane_x;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		floor_x_wall;
	double		floor_y_wall;
	double		dist_wall;
	double		dist_player;
	double		dist_current;
	double		weight;
	double		current_floor_x;
	double		current_floor_y;
	int			floor_tex_x;
	int			floor_tex_y;
	int			checker_board_pattern;
	int			floor_texture;
	double		vertical;
	char		fog;
	t_xpm		xpm;
}				t_draw;

typedef struct	s_life
{
	int			life;
	int			health;
	int			inithealth;
	int			sub;
}				t_life;

typedef struct s_game
{
	char		*pathmap;
	int			fd;
	char		*error;
	char		**map;
	double		posx;
	double		posy;
	char		orient;
	char		save;
	char		*next;
	char		iserrno;
	char		*exec;
	t_img		img;
	t_window	window;
	t_texture	texture;
	t_draw		draw;
	t_life		life;
} t_game;

extern t_game g_game;

//UTILS
char	*get_next_line(int fd);
int		updstate(void);
int		exit_msg(char *context);
size_t	ft_tablen(void **tab);
int		game_end(void);
void	free_img(t_xpm *xpm);
void	next_map(void);
void	free_2d(void **arg);
//PARSING
int		get_map_options();
int		get_resolution(char *line, int i, char *temp);
int		get_sprites(char *line, int i);
int		get_color(char *line, int i, char chosen_char);
int		get_map(void);
int		verifying_map(void);
int		open_textures_file(t_xpm *xpm);
int		open_textures(void);
//HOOKS
int		key_hook(int key);
int		close_hook(int key);
void	hook_move(int key);
void	hook_translate(int key);
void	hook_vertical(int key);
void	hook_action(void);
void	hook_rotate(int key, double initrot);
//COLOR
t_color	create_rgbcolor(char c);
t_color	create_tcolor(int color);
//IMG
t_img	create_background(t_img img);
t_img	create_img(void);
t_img	create_hud(t_img img, t_draw draw);
t_color	img_get_px(t_img img, int x, int y);
void	img_set_px(t_color color, t_img img, int x, int y);
//HUD_CROSS
t_img	hud_cross(t_img img);
//HUD_MINIMAP
t_img		hud_minimap(t_img img, t_draw draw);
//HUD_LIFE
t_img	hud_life(t_img img);
void	sub_life(void);
//DRAW
void	draw(void);
t_draw	init_draw(t_draw draw, int state);
t_draw	get_orient(t_draw draw);
t_draw	get_dist(t_draw draw);
t_draw	get_drawpos(t_draw draw);
//DRAW_GET_DIST
int		draw_get_dist(t_draw draw);
t_draw	draw_get_perpdist(t_draw draw);
//DRAW_EXTERN
t_img	draw_extern(t_draw draw, t_img img);
//START_MLX
void	set_start_orient(void);
int		start_mlx(void);
#endif
