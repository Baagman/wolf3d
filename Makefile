# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbaagman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 11:13:01 by tbaagman          #+#    #+#              #
#    Updated: 2018/09/07 11:11:18 by tbaagman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d
SRC = init.c wolf3d.c key_handler.c map_checker.c ray_caster.c display.c move.c
HEADER = wolf3d.h
CC = clang
LIBFTDIR = libft/
CFLAGS = -Wall -Werror -Wextra
LINKING = libft/libft.a -lmlx -framework OpenGL -framework AppKit
OBJ = init.o wolf3d.o key_handler.o map_checker.o ray_caster.o display.o move.o

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CC) -c $(CFLAGS) $(SRC)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LINKING)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	@make -C $(LIBFTDIR) fclean
	/bin/rm -rf $(NAME)

re: clean fclean all

.PHONY: clean, fclean, re, all
