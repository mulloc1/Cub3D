#include "cub3d.h"

void	ft_error(int cmp, char *message)
{
	if (cmp)
	{
		perror(message);
		exit(1);
	}		
}

void	ft_str_array_free(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

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

int	ft_valid_rgb(char *rgb)
{
	int	i;

	i = -1;
	while (rgb[++i])
		if (rgb[i] < '0' || rgb[i] > '9')
			return (0);
	return (1);
}

void	ft_put_rgb(t_cub *cub, char *type, char *value)
{
	char	**rgbs;
	int		rgb;
	int		temp;

	rgbs = ft_split(value, ',');
	ft_error(!rgbs, "ft_put_rgb() rgbs ft_split() failed\n");	
	ft_error(!ft_valid_rgb(rgbs[0]), "invalid rgb value");
	temp = ft_atoi(rgbs[0]);
	ft_error(temp < 0 || temp > 255, "invalid rgb value");
	rgb = temp << 16;
	ft_error(!ft_valid_rgb(rgbs[1]), "invalid rgb value");
	temp = ft_atoi(rgbs[1]);
	ft_error(temp < 0 || temp > 255, "invalid rgb value");
	rgb += temp << 8;
	ft_error(!ft_valid_rgb(rgbs[2]), "invalid rgb value");
	temp = ft_atoi(rgbs[2]);
	ft_error(temp < 0 || temp > 255, "invalid rgb value");
	rgb += temp;
	if (ft_strncmp(type, "F", 2)) 
		cub->map.floor = rgb;
	else if (ft_strncmp(type, "C", 2))
		cub->map.ceil = rgb;
	ft_str_array_free(rgbs);
}

int	ft_put_in(t_cub *cub, char **buf)
{
	if (!ft_strncmp(buf[0], "NO", 3) || !ft_strncmp(buf[0], "SO", 3) \
				|| !ft_strncmp(buf[0], "WE", 3) || !ft_strncmp(buf[0], "EA", 3))
	{
		ft_put_picture(cub, buf[0], buf[1]);
		buf[1] = NULL;
		ft_str_array_free(buf);
		return (1);
	}
	else if (!ft_strncmp(buf[0], "F", 2) || !ft_strncmp(buf[0], "C", 2))
	{
		ft_put_rgb(cub, buf[0], buf[1]);
		ft_str_array_free(buf);
		return (1);
	}
	return (0);
}

int	ft_type_parsing(t_cub *cub, char *buf)
{
	char	**buf_split;

	buf_split = ft_split(buf, ' ');
	ft_error(!buf_split, "ft_type_parsing() buf_split ft_split() failed\n");
	if (!ft_put_in(cub, buf_split))
	{
		ft_str_array_free(buf_split);
		return (0);
	}
	return (1);
}

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
		ft_error(!temp, "rebuilding_map() temp malloc() failed");
		ft_strlcpy(temp, cub->map.map[i], cub->map.width + 1);
		free(cub->map.map[i]);
		cub->map.map[i] = temp;
	}
}

void	ft_player_direction(t_cub *cub, char dir, t_vector v)
{
	if (cub->player.pos.x > 0 && cub->player.pos.y > 0)
		ft_error(1, "invalid map multi player");
	cub->player.pos.x = v.x + 0.5;
	cub->player.pos.y = v.y + 0.5;
	if (dir == 'N')
	{
		cub->player.dir = (t_vector) {0, 1};
		cub->player.plane = (t_vector) {-0.66, 0};
	}
	else if (dir == 'S')
	{
		cub->player.dir = (t_vector) {0, -1};
		cub->player.plane = (t_vector) {0.66, 0};
	}
	else if (dir == 'E')
	{
		cub->player.dir = (t_vector) {1, 0};
		cub->player.plane = (t_vector) {0, -0.66};
	}
	else if (dir == 'W')
	{
		cub->player.dir = (t_vector) {-1, 0};
		cub->player.plane = (t_vector) {0, 0.66};
	}
}

int	ft_isdir(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	ft_valid_c(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == 'S' || c == 'N' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	valid_checking(t_cub *cub)
{
	char	**map;
	int		i;
	int		j;

	map = cub->map.map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			ft_error(!ft_valid_c(map[i][j]), "invalid map");
			if (map[i][j] == '0' || ft_isdir(map[i][j]))
			{
				if (i + 1 < cub->map.height && map[i + 1][j] == ' ')
					ft_error(1, "invalid map");
				if (i - 1 >= 0 && map[i - 1][j] == ' ')
					ft_error(1, "invalid map");
				if (j + 1 < cub->map.width && map[i][j + 1] == ' ')
					ft_error(1, "invalid map");
				if (j - 1 >= 0 && map[i][j - 1] == ' ')
					ft_error(1, "invalid map");
			}
			if (ft_isdir(map[i][j]))
				ft_player_direction(cub, map[i][j], (t_vector){j, i});
		}
	}
}

int	ft_valid_filename(char *file)
{
	unsigned int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".cub", 5))
		return (0);
	return (1);
}

int	ft_parsing(t_cub *cub, char *file)
{
	char	*buf;
	int		fd;

	ft_error(!ft_valid_filename(file), "invalid file extension");
	fd = open(file, O_RDONLY);
	ft_error(fd == -1, "parser() fd open() failed");
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
	cub->map.wall_color = 0xffffff;
	valid_checking(cub);
	rebuilding_map(cub);
	return (1);
}