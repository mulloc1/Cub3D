/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:42:31 by jaebae            #+#    #+#             */
/*   Updated: 2022/08/04 14:04:46 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	creating_map(t_cub *cub, char *buf)
{
	char	**map;
	int		i;
	int		len;

	map = ft_calloc(++cub->map.height + 1, sizeof(char *));
	i = -1;
	while (++i < cub->map.height - 1 && cub->map.map)
		map[i] = cub->map.map[i];
	len = ft_strlen(buf);
	if (cub->map.width < len)
		cub->map.width = len;
	map[i] = ft_strdup(buf);
	free(cub->map.map);
	cub->map.map = map;
}

void	rebuilding_map(t_cub *cub)
{
	char	*temp;
	int		i;

	i = -1;
	while (++i < cub->map.height)
	{
		temp = malloc(cub->map.width * sizeof(char));
		ft_error(!temp, "rebuilding_map() temp malloc() failed\n");
		ft_strlcpy(temp, cub->map.map[i], cub->map.width + 1);
		free(cub->map.map[i]);
		cub->map.map[i] = temp;
	}
}

void	ft_player_direction(t_cub *cub, char dir, t_vector v)
{
	if (cub->player.pos.x > 0 && cub->player.pos.y > 0)
		ft_error(1, "invalid map multi player\n");
	cub->map.map[(int)v.y][(int)v.x] = '0';
	cub->player.pos.x = v.x + 0.5;
	cub->player.pos.y = v.y + 0.5;
	if (dir == 'S')
	{
		cub->player.dir = (t_vector){1, 0};
		cub->player.plane = (t_vector){0, -0.66};
	}
	else if (dir == 'N')
	{
		cub->player.dir = (t_vector){0, -1};
		cub->player.plane = (t_vector){-0.66, 0};
	}
	else if (dir == 'E')
	{
		cub->player.dir = (t_vector){0, 1};
		cub->player.plane = (t_vector){0.66, 0};
	}
	else if (dir == 'W')
	{
		cub->player.dir = (t_vector){-1, 0};
		cub->player.plane = (t_vector){0, 0.66};
	}
}

int	ft_parsing(t_cub *cub, char *file)
{
	char	*buf;
	int		fd;

	ft_error(!ft_valid_filename(file), "invalid file extension\n");
	fd = open(file, O_RDONLY);
	ft_error(fd == -1, "parser() fd open() failed\n");
	while (1)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		buf[ft_strlen(buf) - 1] = '\0';
		if (ft_strncmp(buf, "\0", 1))
			if (!ft_type_parsing(cub, buf))
				creating_map(cub, buf);
		free(buf);
	}
	cub->map.win_height = 480;
	cub->map.win_width = 640;
	cub->map.wall_color = 0x00FF00;
	map_valid_checking(cub);
	ft_error(cub->player.dir.x == 0 && cub->player.dir.y == 0, \
	"invalid map dose not exist player\n");
	rebuilding_map(cub);
	return (1);
}
