/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:54:28 by jaebae            #+#    #+#             */
/*   Updated: 2022/08/07 13:05:17 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ray
{
	t_vector	vec;
	t_vector	sideDist;
	t_vector	deltaDist;
	double		perpWallDist;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
}	t_ray;

typedef struct s_map
{
	int		width;
	int		height;
	int		win_width;
	int		win_height;
	int		floor;
	int		ceil;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**map;
	int		wall_color;
}	t_map;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;


typedef struct s_texture
{
	void	*img_texture;
	char		*img_buf;
	int		bpp;
	int		size;
	int		endian;
	int		width;
	int		height;	
}	t_texture;

typedef struct s_mlx
{
	t_texture no;
	int *no_texture;
	t_texture so;
	t_texture ea;
	t_texture we;
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		bpp;
	int		size;
	int		endian;
}	t_mlx;

typedef struct s_cub
{
	t_map		map;
	t_player	player;
	t_mlx		mlx;
}	t_cub;

#endif
