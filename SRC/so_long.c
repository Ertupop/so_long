/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:30:58 by ertupop           #+#    #+#             */
/*   Updated: 2022/04/21 10:35:35 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	main(int	ac, char **av)
{
	t_vars	so_long;
	if (ac != 2)
		return (write(1, "arg error", 9));
	if (map_checker(av[1]) = 1)
		return (write(1, "map erorr", 9));
	so_long.mlx = mlx_init();
	if (!so_long.mlx)
		return (-1);
	so_long.win = mlx_new_window(so_long.mlx, 500, 500, "So_long");
	mlx_loop(so_long.mlx);
	return (1);
}
