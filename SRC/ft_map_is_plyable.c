/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_is_plyable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:14:41 by rostrub           #+#    #+#             */
/*   Updated: 2024/05/17 13:49:00 by rostrub          ###   ########.fr       */
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
	if (ft_all_collect(so, so.playerx, so.playery, &check) == 0)
	{
		ft_free_m(check.map);
		return (0);
	}
	ft_reset_map(&check);
	if (ft_exit_playable(so, so.playerx, so.playery, &check) == 0)
	{
		ft_free_m(check.map);
		return (0);
	}
	ft_free_m(check.map);
	return (1);
}

void	ft_reset_map(t_check *check)
{
	int	i;
	int	i2;

	i = 0;
	if (check->map)
	{
		while (check->map[i])
		{
			i2 = 0;
			while (check->map[i][i2])
			{
				if (check->map[i][i2] == '2')
					check->map[i][i2] = '0';
				i2++;
			}
			i++;
		}
	}
}
