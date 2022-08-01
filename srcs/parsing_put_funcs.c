/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_put_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaebae <jaebae@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:45:14 by jaebae            #+#    #+#             */
/*   Updated: 2022/08/01 14:46:08 by jaebae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_put_picture(t_cub *cub, char *type, char *value)
{
	if (!ft_strncmp(type, "NO", 3))
		cub->map.no = value;
	else if (!ft_strncmp(type, "SO", 3))
		cub->map.so = value;
	else if (!ft_strncmp(type, "WE", 3))
		cub->map.we = value;
	else if (!ft_strncmp(type, "EA", 3))
		cub->map.ea = value;
}

void	ft_put_rgb(t_cub *cub, char *type, char *value)
{
	char	**rgbs;
	int		rgb;
	int		temp;

	rgbs = ft_split(value, ',');
	ft_error(!rgbs, "ft_put_rgb() rgbs ft_split() failed\n");
	ft_error(!ft_is_valid_rgb(rgbs[0]), "invalid rgb value");
	temp = ft_atoi(rgbs[0]);
	ft_error(temp < 0 || temp > 255, "invalid rgb value");
	rgb = temp << 16;
	ft_error(!ft_is_valid_rgb(rgbs[1]), "invalid rgb value");
	temp = ft_atoi(rgbs[1]);
	ft_error(temp < 0 || temp > 255, "invalid rgb value");
	rgb += temp << 8;
	ft_error(!ft_is_valid_rgb(rgbs[2]), "invalid rgb value");
	temp = ft_atoi(rgbs[2]);
	ft_error(temp < 0 || temp > 255, "invalid rgb value");
	rgb += temp;
	if (ft_strncmp(type, "F", 2))
		cub->map.floor = rgb;
	else if (ft_strncmp(type, "C", 2))
		cub->map.ceil = rgb;
	ft_str_array_free(rgbs);
}

int	ft_put_in(t_cub *cub, char **bufs)
{
	if (!ft_strncmp(bufs[0], "NO", 3) || !ft_strncmp(bufs[0], "SO", 3) || \
			!ft_strncmp(bufs[0], "WE", 3) || !ft_strncmp(bufs[0], "EA", 3))
	{
		ft_put_picture(cub, bufs[0], bufs[1]);
		bufs[1] = NULL;
		ft_str_array_free(bufs);
		return (1);
	}
	else if (!ft_strncmp(bufs[0], "F", 2) || !ft_strncmp(bufs[0], "C", 2))
	{
		ft_put_rgb(cub, bufs[0], bufs[1]);
		ft_str_array_free(bufs);
		return (1);
	}
	return (0);
}

int	ft_type_parsing(t_cub *cub, char *buf)
{
	char	**bufs;

	bufs = ft_split(buf, ' ');
	ft_error(!bufs, "ft_type_parsing() bufs ft_split() failed\n");
	if (!ft_put_in(cub, bufs))
	{
		ft_str_array_free(bufs);
		return (0);
	}
	return (1);
}
