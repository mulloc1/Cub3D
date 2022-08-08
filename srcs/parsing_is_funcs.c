/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_is_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:42:37 by jaebae            #+#    #+#             */
/*   Updated: 2022/08/01 14:52:04 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	ft_is_valid_c(char c)
{
	if (c == '1' || c == '0' || c == ' ' || \
			c == 'S' || c == 'N' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	ft_is_not_around_space(int x, int y, char **map, t_cub *cub)
{
	if (y == cub->map.height - 1 || x == cub->map.width - 1 || y == 0 || x == 0)
		return (0);
	if (map[y + 1][x] == ' ' || map[y + 1][x] == '\0')
		return (0);
	if (map[y - 1][x] == ' ')
		return (0);
	if ((map[y][x + 1] == ' ' || map[y][x + 1] == '\0'))
		return (0);
	if (map[y][x - 1] == ' ')
		return (0);
	return (1);
}

int	ft_is_valid_rgb(char *rgb)
{
	int	i;

	i = -1;
	while (rgb[++i])
		if (rgb[i] < '0' || rgb[i] > '9')
			return (0);
	return (1);
}

void	map_valid_checking(t_cub *cub)
{
	char	**map;
	int		y;
	int		x;

	map = cub->map.map;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			ft_error(!ft_is_valid_c(map[y][x]), "invalid map\n");
			if (map[y][x] == '0' || ft_isdir(map[y][x]))
			{
				ft_error(!ft_is_not_around_space(x, y, map, cub), \
					"invalid map\n");
				if (ft_isdir(map[y][x]))
					ft_player_direction(cub, map[y][x], (t_vector){x, y});
			}
		}
	}
}
