#include <stdio.h>
#include "mlx.h"

int	main(int argc, char *argv[])
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*buf;
	int		bpp;
	int		size;
	int		endian;

	argc++;
	argv++;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Cub3D");
	img_ptr = mlx_new_image(mlx_ptr, 500, 500);
	buf = mlx_get_data_addr(img_ptr, &bpp, &size, &endian);
	for (int i = 0; i < 100; i++)
		((unsigned *)buf)[i] = 0xFFFFFF;
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
