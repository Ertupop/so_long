/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:52:48 by rstrub            #+#    #+#             */
/*   Updated: 2022/04/21 13:47:42 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/get_next_line.h"

int	ft_check_buffer(char *buffer)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (buffer[index] && i != 1)
	{
		if (buffer[index] == '\n')
			i = 1;
		index++;
	}
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *buff)
{
	char		*cp;
	int			len;
	int			i;
	int			i2;

	if (!str | !buff)
		return (NULL);
	len = ft_strlen(str) + ft_strlen(buff);
	cp = malloc(sizeof(char) * (len + 2));
	if (!cp)
		return (NULL);
	i = -1;
	i2 = -1;
	while (str[++i])
		cp[i] = str[i];
	while (buff[++i2] && buff[i2 - 1] != '\n')
		cp[i + i2] = buff[i2];
	cp[i + i2] = '\0';
	free(str);
	return (cp);
}
