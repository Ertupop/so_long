# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 10:59:33 by rstrub            #+#    #+#              #
#    Updated: 2022/05/20 12:03:15 by rstrub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = SRC/so_long.c SRC/ft_error.c SRC/ft_load_img.c SRC/map_checker.c \
	    SRC/map_import.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		    SRC/ft_map_info.c SRC/move.c SRC/finish.c

OBJS  = ${SRCS:.c=.o}
NAME  = so_long
HEADER = so_long.h
CC = cc
MLX = mlx/libmlx_Linux.a
PRINTF = printf/libftprintf.a

%.o: %.c
	$(CC) -g3 -DBUFFER_SIZE=1 -Wall -Wextra -Werror -I/usr/include -Imlx -O0 -c $< -o $@

$(NAME): $(OBJS) $(MLX) $(PRINTF)
	$(CC) $(OBJS) -g3 -Lprintf -lftprintf -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	make -C ./mlx

$(PRINTF):
	make -C ./printf

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean ${NAME}

.PHONY:		re clean fclean all
