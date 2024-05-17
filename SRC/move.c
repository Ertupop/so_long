/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:14:13 by rstrub            #+#    #+#             */
/*   Updated: 2024/05/17 13:21:28 by rostrub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	ft_up(t_vars *so)
{
	if (so->map[so->playery - 1][so->playerx] == '1')
		return ;
	else
	{
		ft_put_good_image(so);
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
		if (so->map[so->playery][so->playerx] == 'E' && so->c == 0)
			ft_leave(so);
	}
}

void	ft_down(t_vars *so)
{
	if (so->map[so->playery + 1][so->playerx] == '1')
		return ;
	else
	{
		ft_put_good_image(so);
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
		if (so->map[so->playery][so->playerx] == 'E' && so->c == 0)
			ft_leave(so);
	}
}

void	ft_left(t_vars *so)
{
	if (so->map[so->playery][so->playerx - 1] == '1')
		return ;
	else
	{
		ft_put_good_image(so);
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
		if (so->map[so->playery][so->playerx] == 'E' && so->c == 0)
			ft_leave(so);
	}
}

void	ft_right(t_vars *so)
{
	if (so->map[so->playery][so->playerx + 1] == '1')
		return ;
	else
	{
		ft_put_good_image(so);
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
		if (so->map[so->playery][so->playerx] == 'E' && so->c == 0)
			ft_leave(so);
	}
}

void	ft_put_good_image(t_vars *so)
{
	if (so->map[so->playery][so->playerx] == 'E')
		mlx_put_image_to_window(so->mlx, so->win, so->exit, so->playerx * 32,
			so->playery * 32);
	else
		mlx_put_image_to_window(so->mlx, so->win, so->ground, so->playerx * 32,
			so->playery * 32);
}
