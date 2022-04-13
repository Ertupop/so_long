# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/21 10:59:33 by rstrub            #+#    #+#              #
#    Updated: 2022/04/06 10:19:24 by ertupop          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  =

OBJS  = ${SRCS:.c=.o}
NAME  = pipex
HEADER = so_long.h
.c.o:
	gcc -Wall -Wextra -Werror -g -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJS} ${HEADER}
			ar rcs ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean ${NAME}

.PHONY:		re clean fclean all
