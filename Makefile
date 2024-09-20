# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmenard <jmenard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 16:56:33 by jmenard           #+#    #+#              #
#    Updated: 2024/09/18 12:52:46 by jmenard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
INCLUDES = so_long.h

SRC = so_long.c error.c checking.c parsing.c utils.c put_window.c mouvements.c \
parsing2.c ennemi.c animation.c

OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft
MINI_LIBX_DIR = ./minilibx-linux
MINILIBX = ./libmlx.a

all: $(MINILIBX) $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(MINILIBX):
	$(MAKE) -C ./minilibx-linux

libft_clean:
	$(MAKE) clean -C ./libft

minilibx_clean:
	$(MAKE) clean -C ./minilibx-linux

libft_fclean:
	$(MAKE) fclean -C ./libft

$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) -o $@ -L./libft -lft -lm -L$(MINI_LIBX_DIR) -lmlx -lX11 -lXext

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -Imlx_linux -O3 -c $^ -o $@

clean: libft_clean minilibx_clean
	rm -f $(OBJ)

fclean: libft_fclean clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re LIBFT libft_clean libft_fclean