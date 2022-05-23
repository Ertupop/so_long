/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:26:35 by ertupop           #+#    #+#             */
/*   Updated: 2022/05/23 14:56:05 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	ft_map_checker(char **map)
{
	int	i;

	i = ft_check_len(map);
	if (i != 0)
		return (1);
	i = ft_check_wall(map);
	if (i != 0)
		return (2);
	i = ft_check_content(map);
	if (i != 0)
		return (3);
	return (0);
}

int	ft_check_len(char **map)
{
	int	i;
	int	len1;
	int	len2;

	i = 1;
	len1 = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		len2 = ft_strlen(map[i]);
		if (len1 != len2)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_wall(char **map)
{
	int	i;
	int	i2;

	i = 0;
	while (map[i] != NULL)
	{
		i2 = 0;
		while (map[i][i2] && map[i][i2] != '\n')
		{
			if ((i == 0 || map[i + 1] == NULL) && map[i][i2] != '1')
				return (1);
			else if ((i2 == 0 || map[i][i2 + 1] == '\0'
				|| map[i][i2 + 1] == '\n') && map[i][i2] != '1')
				return (1);
			i2++;
		}
		i++;
	}
	return (0);
}

int	ft_check_content(char **map)
{
	int	tab[3];
	int	i2;
	int	i;

	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	i = -1;
	while (map[++i] != NULL)
	{
		i2 = 0;
		while (map[i][i2])
		{
			if (map[i][i2] == 'C')
				tab[0] = tab[0] + 1;
			if (map[i][i2] == 'E')
				tab[1] = tab[1] + 1;
			if (map[i][i2] == 'P')
				tab[2] = tab[2] + 1;
			i2++;
		}
	}
	if (tab[0] < 1 || tab[1] < 1 || tab[2] < 1)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	**map;
	int		i;

	map = ft_map_import("../Maps/map.ber");
	if (map == NULL)
		return (printf("erreur map\n"));
	i = -1;
	while (map[++i] != NULL)
		printf("%s",map[i]);
	i = ft_check_len(map);
	printf("si i = 0 c'est ok\n\n");
	printf("valeur de i pour check len :%d\n", i);
	i = ft_check_wall(map);
	printf("valeur de i pour check wall :%d\n", i);
	i = ft_check_content(map);
	printf("la valeur de i pour check content : %d\n", i);
	return (0);
}*/
