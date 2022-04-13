# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 10:59:33 by rstrub            #+#    #+#              #
#    Updated: 2022/04/13 14:12:19 by rstrub           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = SRC/so_long.c

OBJS  = ${SRCS:.c=.o}
NAME  = so_long
HEADER = so_long.h
CC = cc
MLX = mlx/libmlx_Linux.a

%.o: %.c
	$(CC) -g3 -DBUFFER_SIZE=1 -Wall -Wextra -Werror -I/usr/include -Imlx -O0 -c $< -o $@

$(NAME): $(OBJS) $(MLX)
	$(CC) $(OBJS) -g3 -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(MLX):
	make -C ./mlx

all:		${NAME}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean ${NAME}

.PHONY:		re clean fclean all
