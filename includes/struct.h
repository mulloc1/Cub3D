typedef struct s_vector
{
	double x;
	double y;
}	t_vector;

typedef struct s_map
{
	int width;
	int height;
	int	win_width;
	int	win_height;
	int floor;
	int ceil;
	char **map;
}	t_map;

typedef struct s_player
{
	t_vector pos;
	t_vector dir;
	t_vector cam;
} t_player;

typedef struct s_mlx
{
	void *mlx;
	void *win;
	void *img;
}	t_mlx;

typedef struct	s_cub
{
	t_map		map;
	t_player	player;
	t_mlx		mlx;
}	t_cub;
