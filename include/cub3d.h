/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:10:33 by jonkim            #+#    #+#             */
/*   Updated: 2022/08/09 12:10:34 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define ERROR -1
# define ROT_R 0.523599
# define ROT_L -0.523599
# define MOVE_SPEED 0.222
# define RIGHT 1
# define LEFT 0
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define VEC_MAX 999999999

int		ft_mlx_init(t_cub *cub);
void	ray_init(t_player *player, double cam_x, t_ray *ray);
void	draw_init(t_draw *draw, t_cub *cub, t_ray *ray, int i);
int		raycasting(t_cub *cub);
void	ft_error(int cmp, char *message);
void	ft_str_array_free(char **arr);
int		ft_valid_filename(char *file);
int		ft_isdir(char c);
int		ft_is_valid_c(char c);
int		ft_is_not_around_space(int x, int y, char **map, t_cub *cub);
int		ft_is_valid_rgb(char *rgb);
void	map_valid_checking(t_cub *cub);
void	ft_put_picture(t_cub *cub, char *type, char *value);
void	ft_put_rgb(t_cub *cub, char *type, char *value);
int		ft_put_in(t_cub *cub, char **bufs);
int		ft_type_parsing(t_cub *cub, char *buf);
void	ft_player_direction(t_cub *cub, char dir, t_vector v);
void	rebuilding_map(t_cub *cub);
void	creating_map(t_cub *cub, char *buf);
int		ft_parsing(t_cub *cub, char *file);
int		key_hook(int key_code, t_cub *cub);
int		rotate_vector(t_player *player, int right);

#endif
