/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:10:06 by jonkim            #+#    #+#             */
/*   Updated: 2022/08/09 12:18:47 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	exit_game(int keycode, t_cub *cub)
{
	(void)cub;
	keycode++;
	exit(0);
}

int	main(int ac, char *av[])
{
	t_cub	cub;

	ft_memset(&cub, 0, sizeof(t_cub));
	if (ac != 2)
	{
		printf("Error\n");
		return (1);
	}
	ft_parsing(&cub, av[1]);
	if (ft_mlx_init(&cub) == ERROR)
	{
		printf("Error\n");
		return (1);
	}
	raycasting(&cub);
	mlx_hook(cub.mlx.win, 3, 0, key_hook, &cub);
	mlx_hook(cub.mlx.win, 17, 0, exit_game, &cub);
	mlx_loop(cub.mlx.mlx);
	return (0);
}
