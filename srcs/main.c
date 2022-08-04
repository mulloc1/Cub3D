#include "cub3d.h"

int main(int ac, char *av[])
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(t_cub));
	if (ac != 2)
	{
		// 에러 출력 
		return(1);
	}
	if (ft_parsing(&cub, av[1]))
	{
		// 에러 출력
	}
	ft_mlx_init(&cub);
	raycasting(&cub);
	mlx_hook(cub.mlx.win, 3, 0, key_hook, &cub);
	mlx_loop(cub.mlx.mlx);
	// if (play() == ERROR)
	// {
	// 	// 에러 출력 
	// 	// play 함수내에 loop
	// }
	return (0);
}