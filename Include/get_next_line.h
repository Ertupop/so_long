/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:53:06 by rstrub            #+#    #+#             */
/*   Updated: 2022/01/27 13:46:06 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "unistd.h"
# include "stdlib.h"
# include <fcntl.h>
// principal
char	*ft_init(char *cp);
char	*ft_clear_buff(char *str, char *buff);
char	*ft_free(char *str);
char	*get_next_line(int fd);

// secondaire
int		ft_check_buffer(char *buffer);
char	*ft_strjoin(char *str, char *buff);
int		ft_strlen(char *s);

#endif
