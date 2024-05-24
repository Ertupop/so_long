/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:30:58 by ertupop           #+#    #+#             */
/*   Updated: 2024/05/24 08:22:58 by rostrub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	ft_init_struct(t_vars *s)
{
	s->mlx = NULL;
	s->win = NULL;
	s->map = NULL;
	s->ground = NULL;
	s->wall = NULL;
	s->exit = NULL;
	s->collect = NULL;
	s->player[0] = NULL;
	s->player[1] = NULL;
	s->player[2] = NULL;
	s->player[3] = NULL;
	s->walk = 0;
}

int	ft_hook(int key, t_vars *so)
{
	if (key == 119 || key == 65362)
		ft_up(so);
	else if (key == 115 || key == 65364)
		ft_down(so);
	else if (key == 97 || key == 65361)
		ft_left(so);
	else if (key == 100 || key == 65363)
		ft_right(so);
	else if (key == 65307)
		ft_leave(so);
	return (0);
}

int	ft_load_mlx(t_vars *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx || ft_load_img(so_long))
	{
		ft_free_m(so_long->map);
		if (so_long->mlx)
		{
			mlx_destroy_display(so_long->mlx);
			free(so_long->mlx);
		}
		write(2, "Error\n Load Images\n", 20);
		return (-1);
	}
	so_long->win = mlx_new_window(so_long->mlx, so_long->sizex * 32,
			so_long->sizey * 32, "So_long");
	put_img(so_long);
	mlx_key_hook(so_long->win, &ft_hook, so_long);
	mlx_hook(so_long->win, 17, 0, &ft_mouse, so_long);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	so_long;

	if (ac != 2)
		return (write(1, "arg error\n", 10));
	ft_init_struct(&so_long);
	so_long.map = ft_map_import(av[1]);
	if (so_long.map == NULL)
		return (ft_error(4));
	if (ft_map_checker(so_long.map) != 0)
		return (0);
	ft_map_info(&so_long);
	if (ft_is_playable(so_long, av[1]) == 0)
	{
		ft_free_m(so_long.map);
		return (ft_error(7));
	}
	if (ft_load_mlx(&so_long) == -1)
		return (-1);
	if (so_long.mlx)
		mlx_loop(so_long.mlx);
	mlx_destroy_window(so_long.mlx, so_long.win);
	mlx_destroy_display(so_long.mlx);
	free(so_long.mlx);
	return (0);
}
