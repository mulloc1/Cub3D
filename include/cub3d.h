#include "struct.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "mlx.h"


# define ERROR -1
# define ROTATE_R -0.785398
# define ROTATE_L 0.785398

int ft_mlx_init(t_cub *cub);
int	ft_parsing(t_cub *cub, char *file);
int raytracing(t_map *map, t_player *player, t_cub *cub);



