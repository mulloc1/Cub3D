#include "../includes/cub3d.h"

int mlx_init(t_cub *cub)
{
	mlx_init(cub->mlx.mlx); // error handling
	mlx_new_window(cub->mlx.mlx, cub->map.win_width, cub->map.win_height, "cub3D");
	mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, cub->map.win_width, cub->map.win_height);
	
}