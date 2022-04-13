/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:30:58 by ertupop           #+#    #+#             */
/*   Updated: 2022/04/13 12:20:23 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int main(void)
{
	t_vars so_long;

	so_long.mlx = mlx_init();
	if (!so_long.mlx)
	so_long.win = mlx_new_window(so_long.mlx, 500, 500, "So_long");
	mlx_loop(so_long.mlx);
	return(1);
}
