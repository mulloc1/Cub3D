#include "cub3d.h"

int ft_mlx_init(t_cub *cub)
{
	cub->mlx.mlx = mlx_init(); // error handling
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, cub->map.win_width, cub->map.win_height, "cub3D");
	mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->map.win_width, cub->map.win_height);
	cub->mlx.buf = mlx_get_data_addr(cub->mlx.img, &(cub->mlx.bpp), &(cub->mlx.size), &(cub->mlx.endian));
	return (0);
}