/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rostrub <rostrub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:57:08 by ertupop           #+#    #+#             */
/*   Updated: 2024/05/17 13:00:14 by rostrub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_error(int error)
{
	if ((error > 0 && error < 5) || error == 7)
		return (ft_map_error(error));
	if (error == 6)
		return (write(1, "Error\n Malloc Fail\n", 20));
	else
		return (0);
}

int	ft_map_error(int error)
{
	write(1, "Error\n", 7);
	if (error == 1)
		write(1, "Size is not regular\n", 21);
	if (error == 2)
		write(1, "Wall Missing\n", 14);
	if (error == 3)
		write (1, "Content Missing\n", 17);
	if (error == 4)
		write(1, "Import Fail\n", 13);
	if (error == 7)
		write(1, "Is not playable\n", 17);
	return (0);
}
