/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_import.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:15:54 by rstrub            #+#    #+#             */
/*   Updated: 2022/05/17 08:13:40 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

char	**ft_map_import(char *map_path)
{
	int		i;
	int		i2;
	int		fd;
	char	**map;

	if (ft_check_path(map_path, ".ber") == -1)
		return (NULL);
	i = ft_nb_line(map_path);
	i2 = 0;
	map = malloc(sizeof(char *) * (i + 1));
	if (!map)
		return (NULL);
	map[i] = NULL;
	fd = open(map_path, O_RDONLY);
	while (i2 < i)
	{
		map[i2] = get_next_line(fd);
		if (map[i2] == NULL)
			return (ft_free_map(i2, map));
		i2++;
	}
	close(fd);
	return (map);
}

int	ft_check_path(char *path, char *ber)
{
	int		i;
	int		i2;

	i = ft_strlen(path);
	i2 = 0;
	i = i - 4;
	while (ber[i2] && path[i])
	{
		if (path[i] != ber[i2])
			return (-1);
		i++;
		i2++;
	}
	return (0);
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

char	**ft_free_map(int i2, char **map)
{
	int	i;

	i = 0;
	while (i < i2)
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (NULL);
}
/*int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (printf("pas le bon nombre d'arg\n"));
	i = ft_check_path(av[1], ".ber");
	if (i == -1)
		printf("le fichier vise n'est pas un .ber\n");
	if (i == 0)
		printf("le fichier vise est un .ber\n");
	return (0);
}*/

/*int	main(void)
{
	char	**map;
	int		i;
	int		count;
	int		i2;
	char	c;

	i = -1;
	printf("nombre de ligne %d\n",ft_nb_line("../Maps/map.ber"));
	count = ft_nb_line("../Maps/map.ber");
	map = ft_map_import("../Maps/map.ber");

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
}*/
