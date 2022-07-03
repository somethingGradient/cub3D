
NAME		= cub3D

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

HEADER		= includes/cub3D.h

SRC_LIST	= main.c

SRC			= $(addprefix src/, $(SRC_LIST))

OBJ			= $(SRC:.c=.o)

INC			= -I ./includes -I ./minilibx

LIBFT	=	./libft/libft.a

MLX			=	libmlx.a
MAC_FLAGS	= -framework OpenGL -framework AppKit
LINUX_FLAGS	= -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

UNAME		:=	$(shell uname)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(MAKE) all -C $(dir $(LIBFT))
ifeq ($(UNAME), Darwin) 
	@$(MAKE) all -C ./mlx_mac/
	@$(CC) $(INC) $(LIBFT) $(OBJ) ./mlx_mac/$(MLX) $(MAC_FLAGS) -o $(NAME)
else ifeq ($(UNAME), Linux)
	@$(MAKE) all -C ./mlx_linux/
	@$(CC) $(INC) $(LIBFT) $(OBJ) ./mlx_linux/$(MLX) $(LINUX_FLAGS) -o $(NAME)
else
	@echo "The platform is not supported."
endif
	@echo Compiled!

$(OBJ): $(SRC)
	@$(CC) -c -o $@ $<


clean:
	@$(MAKE) clean -C $(dir $(LIBFT))
	@rm -rf $(OBJ)
	@echo Cleaned!

		
fclean: clean
ifeq ($(UNAME), Darwin) 
	@$(MAKE) clean -C ./mlx_mac/
else
	@$(MAKE) clean -C ./mlx_linux/
endif
	@rm -rf $(NAME)
	@echo Full cleaned!

re: fclean all

.PHONY: all clean fclean re
