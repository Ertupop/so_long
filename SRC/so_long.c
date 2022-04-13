/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:30:58 by ertupop           #+#    #+#             */
/*   Updated: 2022/04/13 14:17:19 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	main(void)
{
	t_vars	so_long;

	so_long.mlx = mlx_init();
	if (!so_long.mlx)
		return (-1);
	so_long.win = mlx_new_window(so_long.mlx, 500, 500, "So_long");
	mlx_loop(so_long.mlx);
	return (1);
}
