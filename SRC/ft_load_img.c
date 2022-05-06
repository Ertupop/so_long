/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:09:49 by ertupop           #+#    #+#             */
/*   Updated: 2022/04/27 15:39:00 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	*ft_load_img(t_vars *so_long)
{
	int	x;
	int	y;

	so_long->collect = mlx_xpm_file_to_image(so_long->mlx, "../img/collect.xpm", &x, &y);
	so_long->exit = "../img/exit.xpm";
	so_long->ground = "../img/ground.xpm";
	so_long->wall = "../img/wall.xpm";
}
