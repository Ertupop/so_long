/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_plyable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:14:41 by rostrub           #+#    #+#             */
/*   Updated: 2024/05/16 14:41:45 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_is_playable(t_vars so, char *path)
{
	char	**map;
	int		counter;
	// int		i;

	// i= 0;

	counter = 0;
	map = ft_map_import(path);
	if (map == NULL)
		return (0);
	if (ft_all_collect(so, map, so.playerx, so.playery, &counter) != 1)
		return (0);
	return (1);
}

void ft_print_map(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_all_collect(t_vars so, char **map, int x, int y, int *counter)
{
	printf("counter : %d\n", *counter);
	if (*counter == so.c)
		return (1);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'P'
		&& map[y - 1][x] != '2')
	{
		if (map[y - 1][x] == 'C')
			counter ++;
		if (map[y - 1][x] == 'C' || map[y - 1][x] == '0')
			map[y - 1][x] = '2';
		ft_all_collect(so, map, x, y - 1, counter);
	}
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'P'
			&& map[y + 1][x] != '2')
	{
		if (map[y + 1][x] == 'C')
			counter ++;
		if (map[y + 1][x] == 'C' || map[y + 1][x] == '0')
			map[y + 1][x] = '2';
		ft_all_collect(so, map, x, y + 1, counter);
	}
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'P'
		&& map[y][x + 1] != '2')
	{
		if (map[y][x + 1] == 'C')
			counter ++;
		if (map[y][x + 1] == 'C' || map[y][x + 1] == '0')
			map[y][x + 1] = '2';
		ft_all_collect(so, map, x + 1, y, counter);
	}
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'P'
		&& map[y][x - 1] != '2')
	{
		if (map[y][x - 1] == 'C')
			counter ++;
		if (map[y][x - 1] == 'C' || map[y][x - 1] == '0')
			map[y][x - 1] = '2';
		ft_all_collect(so, map, x - 1, y, counter);
	}
	return (0);
}