/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:09:48 by jonkim            #+#    #+#             */
/*   Updated: 2022/08/09 12:09:49 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_addr_texture(t_cub *cub)
{
	cub->mlx.no.img_buf = mlx_get_data_addr(cub->mlx.no.img_texture, \
	&cub->mlx.no.bpp, &cub->mlx.no.size, &cub->mlx.no.endian);
	cub->mlx.so.img_buf = mlx_get_data_addr(cub->mlx.so.img_texture, \
	&cub->mlx.so.bpp, &cub->mlx.so.size, &cub->mlx.so.endian);
	cub->mlx.ea.img_buf = mlx_get_data_addr(cub->mlx.ea.img_texture, \
	&cub->mlx.ea.bpp, &cub->mlx.ea.size, &cub->mlx.ea.endian);
	cub->mlx.we.img_buf = mlx_get_data_addr(cub->mlx.we.img_texture, \
	&cub->mlx.we.bpp, &cub->mlx.we.size, &cub->mlx.we.endian);
}

int	ft_mlx_init(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (!cub->mlx.mlx)
		return (ERROR);
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, cub->map.win_width, \
	cub->map.win_height, "cub3D");
	if (!cub->mlx.win)
		return (ERROR);
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->map.win_width, \
	cub->map.win_height);
	cub->mlx.buf = mlx_get_data_addr(cub->mlx.img, &(cub->mlx.bpp), \
	&(cub->mlx.size), &(cub->mlx.endian));
	cub->mlx.no.img_texture = mlx_xpm_file_to_image(cub->mlx.mlx, \
	cub->map.no, &cub->mlx.no.width, &cub->mlx.no.height);
	cub->mlx.so.img_texture = mlx_xpm_file_to_image(cub->mlx.mlx, \
	cub->map.so, &cub->mlx.so.width, &cub->mlx.so.height);
	cub->mlx.ea.img_texture = mlx_xpm_file_to_image(cub->mlx.mlx, \
	cub->map.ea, &cub->mlx.ea.width, &cub->mlx.ea.height);
	cub->mlx.we.img_texture = mlx_xpm_file_to_image(cub->mlx.mlx, \
	cub->map.we, &cub->mlx.we.width, &cub->mlx.we.height);
	if (!cub->mlx.no.img_texture || !cub->mlx.so.img_texture || \
	!cub->mlx.ea.img_texture || !cub->mlx.we.img_texture)
		return (ERROR);
	get_addr_texture(cub);
	return (0);
}
