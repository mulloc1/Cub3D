#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define ERROR -1
# define ROTATE_R -0.785398
# define ROTATE_L 0.785398

int		ft_mlx_init(t_cub *cub);
int		raytracing(t_map *map, t_player *player, t_cub *cub);

// parsing functions
void	ft_error(int cmp, char *message);
void	ft_str_array_free(char **arr);
int		ft_valid_filename(char *file);
int		ft_isdir(char c);
int		ft_is_valid_c(char c);
int		ft_is_not_around_space(int x, int y, char **map, t_cub *cub);
int		ft_is_valid_rgb(char *rgb);
void	map_valid_checking(t_cub *cub);
void	ft_put_picture(t_cub *cub, char *type, char *value);
void	ft_put_rgb(t_cub *cub, char *type, char *value);
int		ft_put_in(t_cub *cub, char **bufs);
int		ft_type_parsing(t_cub *cub, char *buf);
void	ft_player_direction(t_cub *cub, char dir, t_vector v);
void	rebuilding_map(t_cub *cub);
void	creating_map(t_cub *cub, char *buf);
int		ft_parsing(t_cub *cub, char *file);

#endif
