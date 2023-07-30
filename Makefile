# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 23:05:46 by rugoncal          #+#    #+#              #
#    Updated: 2023/04/25 23:05:48 by rugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -L ./minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

DEPS = ./minilibx-linux/mlx.h ./so_long.h ./get_next_line/get_next_line.h

SRC = ./check.c game.c main.c moves.c render.c helpers.c helpers2.c
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: deps $(NAME)

deps:
	$(MAKE) -C ./minilibx-linux

$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(GNL) $(OBJ) $(MLXFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
