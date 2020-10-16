#/* ************************************************************************** */
#/*                                                                            */
#/*                                                        :::      ::::::::   */
#/*   Makefile                                           :+:      :+:    :+:   */
#/*                                                    +:+ +:+         +:+     */
#/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
#/*                                                +#+#+#+#+#+   +#+           */
#/*   Created: 2020/09/18 12:32:45 by kbatwoma          #+#    #+#             */
#/*   Updated: 2020/10/14 17:53:22 by kbatwoma         ###   ########.fr       */
#/*                                                                            */
#/* ************************************************************************** */

CC = clang
FLAGS = -Wall -Wextra -Werror

LIBFT = libft.a
LIBFT_DIR = libft/

MINILIBX = libmlx.dylib
MINILIBX_DIR = minilibx_mms_20200219/

NAME = cub3D

SRC = cub3d.c \
		srcs/map_parser_utils.c \
		srcs/map_parser.c \
		srcs/map_checker.c \
		srcs/events.c \
		srcs/rays.c \
		srcs/view.c \
		srcs/texture.c \
		srcs/structs.c \
		srcs/sprite.c \
		srcs/screenshot.c \
		srcs/utils.c \
		srcs/free.c \
		srcs/read_configuration_file.c \
		srcs/game.c \
		srcs/utils_2.c \
		srcs/structs_2.c
HEADER = cub3d.h

all:$(NAME)

$(NAME): $(SRC)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MINILIBX_DIR)
	cp $(MINILIBX_DIR)$(MINILIBX) ./
	$(CC) -I $(HEADER) $(SRC) -L. $(LIBFT_DIR)$(LIBFT) $(MINILIBX) -framework OpenGL -framework AppKit -g -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)$(LIBFT)
	rm -f $(MINILIBX)

re: fclean all

.PHONY: all clean fclean re