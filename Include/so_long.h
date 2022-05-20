/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrub <rstrub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:19:35 by ertupop           #+#    #+#             */
/*   Updated: 2022/05/20 11:05:10 by rstrub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
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
	void	*player;
	int		playerx;
	int		playery;
	int		sizex;
	int		sizey;
	int		c;
	int		walk;
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
int		ft_collect(char **map);

//gestion erreur
int		ft_error(int error);
int		ft_map_error(int error);
void	ft_map_info(t_vars *so);
char	**ft_free_map(int i2, char **map);

//hook
int		ft_hook(int key, t_vars *so);
void	ft_up(t_vars *so);
void	ft_down(t_vars *so);
void	ft_left(t_vars *so);
void	ft_right(t_vars *so);

//
void	*ft_load_img(t_vars *so_long);
void	*put_img(t_vars *so_long);
void	ft_leave(t_vars *so);
void	ft_free_m(t_vars *so);
#endif
