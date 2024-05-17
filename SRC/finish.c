/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:28:42 by rstrub            #+#    #+#             */
/*   Updated: 2024/05/17 14:47:22 by rostrub          ###   ########.fr       */
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
	ft_free_m(so->map);
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

void	ft_free_m(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
	map = NULL;
}
