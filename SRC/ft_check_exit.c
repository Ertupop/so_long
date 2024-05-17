/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:48:45 by rostrub           #+#    #+#             */
/*   Updated: 2024/05/17 14:01:34 by rostrub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_exit_playable(t_vars so, int x, int y, t_check *check)
{
	int	ok;

	ok = 0;
	if (check->map[y][x] == 'E')
		return (1);
	if (check->map[y - 1][x] != '1' && check->map[y - 1][x] != 'P'
		&& check->map[y - 1][x] != '2' && ok == 0)
		ok = ft_exit_move(check, x, y - 1, so);
	if (check->map[y + 1][x] != '1' && check->map[y + 1][x] != 'P'
			&& check->map[y + 1][x] != '2' && ok == 0)
		ok = ft_exit_move(check, x, y + 1, so);
	if (check->map[y][x + 1] != '1' && check->map[y][x + 1] != 'P'
		&& check->map[y][x + 1] != '2' && ok == 0)
		ok = ft_exit_move(check, x + 1, y, so);
	if (check->map[y][x - 1] != '1' && check->map[y][x - 1] != 'P'
		&& check->map[y][x - 1] != '2' && ok == 0)
		ok = ft_exit_move(check, x - 1, y, so);
	if (ok == 1)
		return (1);
	return (0);
}

int	ft_exit_move(t_check *check, int x, int y, t_vars so)
{
	if (check->map[y][x] == 'C' || check->map[y][x] == '0')
			check->map[y][x] = '2';
	return (ft_exit_playable(so, x, y, check));
}
