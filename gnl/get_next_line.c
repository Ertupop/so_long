/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:51:32 by rstrub            #+#    #+#             */
/*   Updated: 2022/02/01 10:11:11 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_init(char *cp)
{
	char	*str;
	int		i;

	i = 0;
	while (cp[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!cp)
		return (NULL);
	i = -1;
	while (cp[++i])
		str[i] = cp[i];
	str[i] = '\0';
	return (str);
}

char	*ft_clear_buff(char *str, char *buff)
{
	int	i;
	int	i2;

	i = ft_strlen(buff);
	if (buff[i] == '\n')
		i++;
	i2 = 0;
	while (buff[i] && buff[i2])
	{
		buff[i2] = buff[i];
		i++;
		i2++;
	}
	while (buff[i2])
	{
		buff[i2] = '\0';
		i2++;
	}
	return (str);
}

char	*ft_free(char *str)
{
	if (!str)
		return (NULL);
	free(str);
	str = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	int				i;
	static char		buffer[BUFFER_SIZE + 1];
	char			*str;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (NULL);
	str = ft_init("");
	str = ft_strjoin(str, buffer);
	i = 1;
	while (i > 0 && !ft_check_buffer(buffer))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (ft_free(str));
		else if (i > 0)
		{
			buffer[i] = '\0';
			str = ft_strjoin(str, buffer);
		}
		else if (i == 0 && buffer[0] != '\0')
			return (ft_clear_buff(str, buffer));
		else
			return (ft_free(str));
	}
	return (ft_clear_buff(str, buffer));
}
