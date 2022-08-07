#include "cub3d.h"

int ft_mlx_init(t_cub *cub)
{
	cub->mlx.mlx = mlx_init(); // error handling
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, cub->map.win_width, cub->map.win_height, "cub3D");
	mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->map.win_width, cub->map.win_height);
	cub->mlx.buf = mlx_get_data_addr(cub->mlx.img, &(cub->mlx.bpp), &(cub->mlx.size), &(cub->mlx.endian));
	cub->mlx.no.img_texture = mlx_xpm_file_to_image(cub->mlx.mlx, cub->map.no, &cub->mlx.no.width , &cub->mlx.no.height);
	cub->mlx.so.img_texture = mlx_xpm_file_to_image(cub->mlx.mlx, cub->map.so, &cub->mlx.so.width , &cub->mlx.so.height);
	cub->mlx.ea.img_texture = mlx_xpm_file_to_image(cub->mlx.mlx, cub->map.ea, &cub->mlx.ea.width , &cub->mlx.ea.height);
	cub->mlx.we.img_texture = mlx_xpm_file_to_image(cub->mlx.mlx, cub->map.we, &cub->mlx.we.width , &cub->mlx.we.height);

	return (0);
}