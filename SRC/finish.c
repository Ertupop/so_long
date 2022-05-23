/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:28:42 by rstrub            #+#    #+#             */
/*   Updated: 2022/05/23 15:31:29 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_mouse(t_vars *so)
{
	ft_leave(so);
	return (0);
}

void	ft_leave(t_vars *so)
{
	ft_free_m(so);
	mlx_destroy_window(so->mlx, so->win);
	mlx_destroy_image(so->mlx, so->ground);
	mlx_destroy_image(so->mlx, so->wall);
	mlx_destroy_image(so->mlx, so->exit);
	mlx_destroy_image(so->mlx, so->collect);
	mlx_destroy_image(so->mlx, so->player[0]);
	mlx_destroy_image(so->mlx, so->player[1]);
	mlx_destroy_image(so->mlx, so->player[2]);
	mlx_destroy_image(so->mlx, so->player[3]);
	mlx_loop_end(so->mlx);
}

void	ft_free_m(t_vars *so)
{
	int	y;

	y = 0;
	while (so->map[y])
	{
		free(so->map[y]);
		y++;
	}
	free(so->map);
	so->map = NULL;
}
