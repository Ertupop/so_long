/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:09:49 by ertupop           #+#    #+#             */
/*   Updated: 2024/05/20 10:23:24 by rostrub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_load_img(t_vars *so_long)
{
	int	x;

	x = 32;
	so_long->collect = mlx_xpm_file_to_image(so_long->mlx, "./img/collect.xpm",
			&x, &x);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx, "./img/exit.xpm",
			&x, &x);
	so_long->ground = mlx_xpm_file_to_image(so_long->mlx, "./img/ground.xpm",
			&x, &x);
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx, "./img/wall.xpm",
			&x, &x);
	so_long->player[0] = mlx_xpm_file_to_image(so_long->mlx,
			"./img/Playerf.xpm", &x, &x);
	so_long->player[1] = mlx_xpm_file_to_image(so_long->mlx,
			"./img/Playerl.xpm", &x, &x);
	so_long->player[2] = mlx_xpm_file_to_image(so_long->mlx,
			"./img/Playerr.xpm", &x, &x);
	so_long->player[3] = mlx_xpm_file_to_image(so_long->mlx,
			"./img/Playerb.xpm", &x, &x);
	return (ft_check_load(so_long));
}

int	ft_check_load(t_vars *s)
{
	if (s->collect == NULL || s->exit == NULL || s->ground == NULL
		|| s->wall == NULL || s->player[0] == NULL || s->player[1] == NULL
		|| s->player[2] == NULL || s->player[3] == NULL)
	{
		if (s->collect)
			mlx_destroy_image(s->mlx, s->collect);
		if (s->exit)
			mlx_destroy_image(s->mlx, s->exit);
		if (s->ground)
			mlx_destroy_image(s->mlx, s->ground);
		if (s->wall)
			mlx_destroy_image(s->mlx, s->wall);
		if (s->player[0])
			mlx_destroy_image(s->mlx, s->player[0]);
		if (s->player[1])
			mlx_destroy_image(s->mlx, s->player[1]);
		if (s->player[2])
			mlx_destroy_image(s->mlx, s->player[2]);
		if (s->player[3])
			mlx_destroy_image(s->mlx, s->player[3]);
		return (1);
	}
	return (0);
}

void	*put_img(t_vars *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (so_long->map[++y])
	{
		x = -1;
		while (so_long->map[y][++x] && so_long->map[y][x] != '\n')
			ft_load(so_long, x, y);
	}
	return (0);
}

void	ft_load(t_vars *so_long, int x, int y)
{
	if (so_long->map[y][x] == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->wall, x * 32, y * 32);
	else if (so_long->map[y][x] == '0')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->ground, x * 32, y * 32);
	else if (so_long->map[y][x] == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->collect, x * 32, y * 32);
	else if (so_long->map[y][x] == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->exit, x * 32, y * 32);
	else if (so_long->map[y][x] == 'P')
		mlx_put_image_to_window(so_long->mlx, so_long->win,
			so_long->player[0], x * 32, y * 32);
}
