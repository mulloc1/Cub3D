typedef struct s_vector
{
	double x;
	double y;
}	t_vector;

typedef struct	s_ray
{
	t_vector vec;
	t_vector sideDist;
	t_vector deltaDist;
	double perpWallDist;
	int mapX;
	int mapY;
	int stepX;
	int stepY;
	int hit;
	int side;
}	t_ray;

typedef struct s_map
{
	int width;
	int height;
	int	win_width;
	int	win_height;
	int floor;
	int ceil;
	char *no;
	char *so;
	char *we;
	char *ea;
	char **map;
	int	wall_color;
}	t_map;

typedef struct s_player
{
	t_vector pos;
	t_vector dir;
	t_vector cam;
} t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		bpp;
	int		size;
	int		endian;
}	t_mlx;

typedef struct	s_cub
{
	t_map		map;
	t_player	player;
	t_mlx		mlx;
}	t_cub;
