/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_import.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:15:54 by rstrub            #+#    #+#             */
/*   Updated: 2022/04/21 15:59:37 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

char	**ft_map_import(char *map_path)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	i = ft_nb_line(map_path);
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map[i] = NULL;
	i = 0;
	line = get_next_line(fd);
	map[i] = ft_map_add(line);
	while (line != NULL)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		map[i] = ft_map_add(line);
	}
	close(fd);
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

char	*ft_map_add(char *line)
{
	int		count;
	int		i;
	char	*map;

	count = 0;
	i = 0;
	count = ft_strlen(line);
	map = malloc(sizeof(char) * (count + 1));
	if (!map)
		return (NULL);
	while (line[i] && map[i])
	{
		map[i] = line[i];
		i++;
	}
	//map[i] = '\0';
	return (map);
}

int	main(void)
{
	char	**map;
	int		i;
	int		returnv;

	i = -1;
	printf("nombre de ligne %d\n",ft_nb_line("../Maps/test.ber"));
	map = ft_map_import("../Maps/test.ber");
	while (map[++i] != NULL)
	{
		printf("%s\n", map[i]);
	}
	return (0);
}
