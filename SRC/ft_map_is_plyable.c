/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_plyable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:14:41 by rostrub           #+#    #+#             */
/*   Updated: 2024/05/16 15:05:28 by rostrub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_is_playable(t_vars so, char *path)
{
	t_check	check;

	check.counter = 0;
	check.map = ft_map_import(path);
	if (check.map == NULL)
		return (0);
	if (ft_all_collect(so, so.playerx, so.playery, &check) != 1)
		return (0);
	return (1);
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_all_collect(t_vars so, int x, int y, t_check *check)
{
	printf("counter : %d\n", check->counter);
	if (check->counter == so.c)
		return (1);
	if (check->map[y - 1][x] != '1' && check->map[y - 1][x] != 'P'
		&& check->map[y - 1][x] != '2')
	{
		if (check->map[y - 1][x] == 'C')
			check->counter ++;
		if (check->map[y - 1][x] == 'C' || check->map[y - 1][x] == '0')
			check->map[y - 1][x] = '2';
		ft_all_collect(so, x, y - 1, check);
	}
	if (check->map[y + 1][x] != '1' && check->map[y + 1][x] != 'P'
			&& check->map[y + 1][x] != '2')
	{
		if (check->map[y + 1][x] == 'C')
			check->counter ++;
		if (check->map[y + 1][x] == 'C' || check->map[y + 1][x] == '0')
			check->map[y + 1][x] = '2';
		ft_all_collect(so, x, y + 1, check);
	}
	if (check->map[y][x + 1] != '1' && check->map[y][x + 1] != 'P'
		&& check->map[y][x + 1] != '2')
	{
		if (check->map[y][x + 1] == 'C')
			check->counter ++;
		if (check->map[y][x + 1] == 'C' || check->map[y][x + 1] == '0')
			check->map[y][x + 1] = '2';
		ft_all_collect(so, x + 1, y, check);
	}
	if (check->map[y][x - 1] != '1' && check->map[y][x - 1] != 'P'
		&& check->map[y][x - 1] != '2')
	{
		if (check->map[y][x - 1] == 'C')
			check->counter ++;
		if (check->map[y][x - 1] == 'C' || check->map[y][x - 1] == '0')
			check->map[y][x - 1] = '2';
		ft_all_collect(so, x - 1, y, check);
	}
	return (0);
}
