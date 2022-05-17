# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 10:59:33 by rstrub            #+#    #+#              #
#    Updated: 2022/05/17 07:44:33 by rstrub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = SRC/so_long.c SRC/ft_error.c SRC/ft_load_img.c SRC/map_checker.c \
	    SRC/map_import.c gnl/get_next_line.c gnl/get_next_line_utils.c \
		    SRC/ft_map_info.c

OBJS  = ${SRCS:.c=.o}
NAME  = so_long
HEADER = so_long.h
CC = cc
MLX = mlx/libmlx_Linux.a

%.o: %.c
	$(CC) -g3 -DBUFFER_SIZE=1 -Wall -Wextra -Werror -I/usr/include -Imlx -O0 -c $< -o $@

$(NAME): $(OBJS) $(MLX)
	$(CC) $(OBJS) -g3 -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME) -g3 -fsanitize=address

$(MLX):
	make -C ./mlx

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean ${NAME}

.PHONY:		re clean fclean all
