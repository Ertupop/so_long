/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 07:02:45 by rstrub            #+#    #+#             */
/*   Updated: 2022/05/17 08:00:06 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	ft_map_info(t_vars *so)
{
	so->playery = 0;
	so->sizex = 0;
	so->sizey = 0;
	while (so->map[so->sizey][so->sizex])
		so->sizex++;
	if (so->map[so->sizey][so->sizex - 1] == '\n')
		so->sizex--;
	while (so->map[so->sizey])
		so->sizey++;
	while (so->map[so->playery] && so->map[so->playery][so->playerx] != 'P')
	{
		so->playerx = 0;
		while (so->map[so->playery][so->playerx]
			&& so->map[so->playery][so->playerx] != 'P')
				so->playerx++;
		if (so->map[so->playery][so->playerx] != 'P')
		so->playery++;
	}
}
