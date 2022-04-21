/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_import.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:15:54 by rstrub            #+#    #+#             */
/*   Updated: 2022/04/21 16:34:46 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

char	**ft_map_import(char *map_path)
{
	int		i;
	int		i2;
	int		fd;
	char	*line;
	char	**map;

	i = ft_nb_line(map_path);
	i2 = 0;
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	map[i] = NULL;
	while (i2 < i)
	{
		map[i2] = get_next_line(fd);
		i2++;
	}
	return (map);
}

int	ft_nb_line(char *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (i);
}

int	main(void)
{
	char	**map;
	int		i;
	int		i2;
	char	c;

	i = -1;
	printf("nombre de ligne %d\n",ft_nb_line("../Maps/test.ber"));
	map = ft_map_import("../Maps/test.ber");
	while (map[++i] != NULL)
	{
		i2 = 0;
		while (map[i][i2])
		{
			c = map[i][i2];
			write(1, &c, 1);
			i2++;
		}
	}
	return (0);
}
