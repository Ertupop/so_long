# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 10:59:33 by rstrub            #+#    #+#              #
#    Updated: 2024/05/17 14:02:33 by rostrub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = SRC/so_long.c SRC/ft_error.c SRC/ft_load_img.c SRC/map_checker.c \
		SRC/map_import.c gnl/get_next_line.c gnl/get_next_line_utils.c \
			SRC/ft_map_info.c SRC/move.c SRC/finish.c SRC/ft_map_is_plyable.c\
			SRC/ft_check_collectible.c SRC/ft_check_exit.c

OBJS  = ${SRCS:.c=.o}
DEPS  = ${SRCS:.c=.d}
NAME  = so_long
HEADER = so_long.h
CC = cc
MLX = mlx/libmlx_Linux.a
PRINTF = printf/libftprintf.a

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g -I/usr/include -Imlx -O0 -c $< -o $@

$(NAME): $(OBJS) $(MLX) $(PRINTF)
	$(CC) $(OBJS) -g -Lprintf -lftprintf -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	make -C ./mlx

$(PRINTF):
	make -C ./printf

all:		${NAME}

clean:
			rm -f ${OBJS}
			make -C ./printf clean
			make -C ./mlx clean

fclean:		clean
			rm -f ${NAME}
			make -C ./printf fclean
			@make -C ./mlx clean

re:			fclean ${NAME}

.PHONY:		re clean fclean all
