/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:57:08 by ertupop           #+#    #+#             */
/*   Updated: 2022/05/16 07:54:42 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_error(int error)
{
	if (error > 0 && error < 5)
		return (ft_map_error(error));
	if (error == 6)
		return (write(1, "malloc error", 12));
	else
		return (0);

}

int	ft_map_error(int error)
{
	if (error == 1)
		write(1, "size error\n", 11);
	if (error == 2)
		write(1, "Wall error\n", 11);
	if (error == 3)
		write (1, "Content error\n", 14);
	if (error == 4)
		write(1, "Import error\n", 13);
	return (0);
}
