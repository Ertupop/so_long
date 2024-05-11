/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:14:13 by rstrub            #+#    #+#             */
/*   Updated: 2024/04/24 11:19:29 by rostrub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	ft_up(t_vars *so)
{
	if (so->map[so->playery - 1][so->playerx] == '1')
		return ;
	else if (so->map[so->playery - 1][so->playerx] == 'E' && so->c != 0)
		return ;
	else
	{
		mlx_put_image_to_window(so->mlx, so->win, so->ground, so->playerx * 32,
			so->playery * 32);
		so->playery--;
		if (so->map[so->playery][so->playerx] == 'C')
		{
			so->map[so->playery][so->playerx] = '0';
			so->c--;
		}
		mlx_put_image_to_window(so->mlx, so->win, so->player[3],
			so->playerx * 32, so->playery * 32);
		so->walk++;
		ft_printf("\rSteps : %d", so->walk);
		if (so->map[so->playery][so->playerx] == 'E')
			ft_leave(so);
	}
}

void	ft_down(t_vars *so)
{
	if (so->map[so->playery + 1][so->playerx] == '1')
		return ;
	else if (so->map[so->playery][so->playerx] == 'E' && so->c != 0)
		return ;
	else
	{
		mlx_put_image_to_window(so->mlx, so->win, so->ground, so->playerx * 32,
			so->playery * 32);
		so->playery++;
		if (so->map[so->playery][so->playerx] == 'C')
		{
			so->map[so->playery][so->playerx] = '0';
			so->c--;
		}
		mlx_put_image_to_window(so->mlx, so->win, so->player[0],
			so->playerx * 32, so->playery * 32);
		so->walk++;
		ft_printf("\rSteps : %d", so->walk);
		if (so->map[so->playery][so->playerx] == 'E')
			ft_leave(so);
	}
}

void	ft_left(t_vars *so)
{
	if (so->map[so->playery][so->playerx - 1] == '1')
		return ;
	else if (so->map[so->playery][so->playerx - 1] == 'E' && so->c != 0)
		return ;
	else
	{
		mlx_put_image_to_window(so->mlx, so->win, so->ground, so->playerx * 32,
			so->playery * 32);
		so->playerx--;
		if (so->map[so->playery][so->playerx] == 'C')
		{
			so->map[so->playery][so->playerx] = '0';
			so->c--;
		}
		mlx_put_image_to_window(so->mlx, so->win, so->player[1],
			so->playerx * 32, so->playery * 32);
		so->walk++;
		ft_printf("\rSteps : %d", so->walk);
		if (so->map[so->playery][so->playerx] == 'E')
			ft_leave(so);
	}
}

void	ft_right(t_vars *so)
{
	if (so->map[so->playery][so->playerx + 1] == '1')
		return ;
	else if (so->map[so->playery][so->playerx + 1] == 'E' && so->c != 0)
		return ;
	else
	{
		mlx_put_image_to_window(so->mlx, so->win, so->ground, so->playerx * 32,
			so->playery * 32);
		so->playerx++;
		if (so->map[so->playery][so->playerx] == 'C')
		{
			so->map[so->playery][so->playerx] = '0';
			so->c--;
		}
		mlx_put_image_to_window(so->mlx, so->win, so->player[2],
			so->playerx * 32, so->playery * 32);
		so->walk++;
		ft_printf("\rSteps : %d", so->walk);
		if (so->map[so->playery][so->playerx] == 'E')
			ft_leave(so);
	}
}
