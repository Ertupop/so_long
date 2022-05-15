/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:09:49 by ertupop           #+#    #+#             */
/*   Updated: 2022/05/11 16:17:33 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	*ft_load_img(t_vars *so_long)
{
	int	x;

	x = 32;
	so_long->collect = mlx_xpm_file_to_image(so_long->mlx, "../img/collect.xpm", &x, &x);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, "../img/exit.xpm", &x, &x);
	so_long->ground = mlx_xpm_file_to_image(so_long->mlx, "../img/ground.xpm", &x, &x);
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "../img/wall.xpm", &x, &x);
}

void	*put_img(t_vars *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (so_long->map[y])
	{
		x = 0;
		while (so_long->map[y][x] && so_long->map[y][x] != '\n')
		{
			if (so_long->map[y][x] == '1')

			else if (so_long->map[y][x] == '0')

			else if (so_long->map[y][x] == 'C')

			else if (so_long->map[y][x] == 'E')

			else if (so_long->map[y][x] == 'P')
				mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->player)
			x++;
		}
		y++;
	}
}
