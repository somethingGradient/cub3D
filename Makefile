
NAME		= cub3D

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

HEADER		= includes/cub3D.h

SRC_LIST	= main.c

SRC			= $(addprefix src/, $(SRC_LIST))

OBJ			= $(SRC:.c=.o)

INC			= -I ./includes -I ./minilibx

OPENGL		= -framework OpenGL -framework AppKit
MLX_LINUX	= -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

MLX 	=	./minilibx/libmlx.a

LIBFT	=	./libft/libft.a


# LIBFT_PATH	= libft/
# LIBFT		= libft/libft.a
# MLX_MAC		= -lmlx -framework OpenGL -framework AppKit

UNAME		:=	$(shell uname)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@# @$(MAKE) all -C $(dir $(MLX))
	@# @$(MAKE) all -C $(dir $(LIBFT))

ifeq ($(UNAME), Darwin) 
	@$(CC) $(INC) $(LIBFT) $(MLX) $(OBJ) -framework OpenGL -framework AppKit -o $(NAME)
else
	@$(CC) $(INC) $(LIBFT) $(MLX) $(OBJ) $(MLX_LINUX) -o $(NAME)
endif
	@echo Compiled!

$(OBJ): $(SRC)
	@$(CC) -c -o $@ $<
# @$(CC) -Imlx_linux -O3 -c $< -o $@



clean:
#@$(MAKE) clean -C $(dir $(LIBFT))
		@# @$(MAKE) clean -C $(dir $(MLX))
		@# @$(MAKE) clean -C $(dir $(LIBFT))
		@rm -rf $(OBJ)
		@echo Cleaned!
		
fclean: clean
#@$(MAKE) fclean -C $(dir $(LIBFT))
		@# @$(MAKE) fclean -C $(dir $(LIBFT))
		@rm -rf $(NAME)
		@echo Full cleaned!

re: fclean all

.PHONY: all clean fclean re
