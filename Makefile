NAME		= cub3D

CC			= clang

FLAGS		= -Wall -Wextra -Werror

HEADER		= ./includes/cub3D.h

SRC_LIST	=	main.c \
				utils/get_next_line_bonus.c \
				utils/updstate.c \
				utils/exit_msg.c \
				utils/utils.c \
				utils/game_end.c \
				utils/next_map.c \
				\
				map_option/get_colors.c \
				map_option/get_map.c \
				map_option/get_resolution.c \
				map_option/get_sprite_files.c \
				map_option/map_option.c \
				map_option/open_textures.c \
				map_option/verifying_map.c \
				\
				rendering/color.c \
				rendering/draw_get_dist.c \
				rendering/draw.c \
				rendering/hook_move.c \
				rendering/hook_vision.c \
				rendering/hooks.c \
				rendering/hud_cross.c \
				rendering/hud_life.c \
				rendering/hud_minimap.c \
				rendering/img.c \
				rendering/start_mlx.c \
				

SRC			= $(addprefix src/, $(SRC_LIST))

OBJ			= $(SRC:%.c=%.o)

LIBFT		= ./libft/libft.a

MLX			= libmlx.a
MAC_FLAGS	= -framework OpenGL -framework AppKit
LINUX_FLAGS	= -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

UNAME		:= $(shell uname)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@#@$(MAKE) all -C $(dir $(LIBFT))
ifeq ($(UNAME), Darwin) 
	@#@$(MAKE) all -C ./mlx_mac/
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) ./mlx_mac/$(MLX) $(MAC_FLAGS) -o $(NAME)
else ifeq ($(UNAME), Linux)
	@#@$(MAKE) all -C ./mlx_linux/
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) ./mlx_linux/$(MLX) $(LINUX_FLAGS) -o $(NAME)
else
	@echo "\033[1;31m"The platform is not supported."\033[0m"
endif
	@echo "\033[36;1m"Compiled!"\033[0m"

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@#@$(MAKE) clean -C $(dir $(LIBFT))
	@rm -rf $(OBJ)
	@echo "\033[1;35m"Cleaned!"\033[0m"
		
fclean: clean
	@#@$(MAKE) fclean -C $(dir $(LIBFT))
ifeq ($(UNAME), Darwin) 
	@#@$(MAKE) clean -C ./mlx_mac/
else
	@#@$(MAKE) clean -C ./mlx_linux/
endif
	@rm -rf $(NAME)
	@echo "\033[1;34m"Full cleaned!"\033[0m"

re: fclean all

.PHONY: all clean fclean re
