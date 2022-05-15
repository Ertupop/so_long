/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:30:58 by ertupop           #+#    #+#             */
/*   Updated: 2022/05/11 15:42:45 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	main(int ac, char **av)
{
	t_vars	so_long;

	if (ac != 2)
		return (write(1, "arg error", 9));
	so_long.map = ft_map_import(av[1]);
	if(so_long.map == NULL)
		return (ft_error(4));
	if(ft_map_checker(so_long.map) != 0)
		return(ft_error(ft_map_checker(so_long.map)));
	ft_load_img(so_long);
	so_long.mlx = mlx_init();
	if (!so_long.mlx)
		return (-1);
	so_long.win = mlx_new_window(so_long.mlx, 500, 500, "So_long");
	mlx_loop(so_long.mlx);

	return (1);
}
