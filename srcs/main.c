#include "cub3d.h"

int main(int ac, char *av[])
{
	t_cub	cub;

	if (ac != 2)
	{
		// 에러 출력 
		return(1);
	}
	if (ft_parsing(&cub, av[1]))
	{
		// 에러 출력
	}
	// if (play() == ERROR)
	// {
	// 	// 에러 출력 
	// 	// play 함수내에 loop
	// }
	return (0);
}