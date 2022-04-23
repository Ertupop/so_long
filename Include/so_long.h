/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ertupop <ertupop@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:19:35 by ertupop           #+#    #+#             */
/*   Updated: 2022/04/22 11:25:34 by ertupop          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <stdio.h>

//les structures
typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
}				t_vars;

//gestion de la map
char	**ft_map_import(char *map_path);
int		ft_nb_line(char *map);
int		ft_check_path(char *path, char *ber);
int		ft_map_checker(char **map);
int		ft_check_len(char **map);
int		ft_check_wall(char **map);
int		ft_check_content(char **map);
#endif
