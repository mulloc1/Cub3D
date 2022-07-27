#include "mlx.h"
#include "cub3d.h"

int main(int ac, char *av[])
{
	int	fd;

	if (ac != 2)
	{
		// 에러 출력 
	}
	fd = open(av[1], O_RDONLY);
	if (init() == ERROR)
	{
		// 에러 출력
	}
	if (play() == ERROR)
	{
		// 에러 출력 
		// play 함수내에 loop
	}
	return (0);
}