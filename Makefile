


NAME		= cub3D

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

HEADER		= cub3D.h

LIBFT_PATH	= libft/

LIBFT		= libft/libft.a

SRC			= main.c

OBJ			= $(SRC:.c=.o)

INC_LINUX	= -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz

UNAME := $(shell uname)


ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif


all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
#@$(MAKE) all -C $(LIBFT_PATH)
		@echo $(detected_OS)
		@$(CC) $(OBJ) $(INC_LINUX) -o $(NAME)
		@echo Compiled!

%.o: %.c $(HEADER)
		@$(CC) -c -o $@ $<
#@$(CC) -Imlx_linux -O3 -c $< -o $@


clean:
#@$(MAKE) clean -C $(dir $(LIBFT))
		@rm -rf $(OBJ)
		@echo Cleaned!
		
fclean: clean
#@$(MAKE) fclean -C $(dir $(LIBFT))
		@rm -rf $(NAME)
		@echo Full cleaned!

re: fclean all

.PHONY: all clean fclean re
