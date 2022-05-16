/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:19:35 by ertupop           #+#    #+#             */
/*   Updated: 2022/05/16 06:59:54 by rstrub           ###   ########.fr       */
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
	void	*ground;
	void	*wall;
	void	*exit;
	void	*collect;
//	void	player[4];
}				t_vars;

//gestion de la map
char	**ft_map_import(char *map_path);
int		ft_nb_line(char *map);
int		ft_check_path(char *path, char *ber);
int		ft_map_checker(char **map);
int		ft_check_len(char **map);
int		ft_check_wall(char **map);
int		ft_check_content(char **map);
int		ft_error(int error);
int		ft_map_error(int error);

//gestion erreur
int		ft_error(int error);
int		ft_map_error(int error);

//
void	*ft_load_img(t_vars *so_long);
void	*put_img(t_vars *so_long);
#endif
