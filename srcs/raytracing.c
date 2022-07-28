#include "../includes/cub3d.h"

int rotate_vector(t_player *player, int right)
{
	// right = 1 -> turn right
	// right = 0 -> turn left
	double	old_dirX;
	double	old_camX;

	old_dirX = player->dir.x;
	old_camX = player->cam.x;
	if (right == 1)
	{
		player->dir.x = old_dirX * cos(ROTATE_R) -  player->dir.y * sin(ROTATE_R);
		player->dir.y = old_dirX * sin(ROTATE_R) + player->dir.y * cos(ROTATE_R);
		player->cam.x = old_camX * cos(ROTATE_R) - player->cam.y * sin(ROTATE_R);
		player->cam.y = old_camX * sin(ROTATE_R) + player->cam.y * cos(ROTATE_R);
	}
	else
	{
		player->dir.x = old_dirX * cos(ROTATE_L) -  player->dir.y * sin(ROTATE_L);
		player->dir.y = old_dirX * sin(ROTATE_L) + player->dir.y * cos(ROTATE_L);
		player->cam.x = old_camX * cos(ROTATE_L) - player->cam.y * sin(ROTATE_L);
		player->cam.y = old_camX * sin(ROTATE_L) + player->cam.y * cos(ROTATE_L);
	}
}

int	ray_init(t_player *player, double cam_x, t_ray *tmp_ray)
{
	tmp_ray->vec.x = player->dir.x + player->cam.x * cam_x;
	tmp_ray->vec.y = player->dir.y + player->cam.y * cam_x;
	tmp_ray->deltaDist.x = fabs(1.0 / tmp_ray->vec.x);
	tmp_ray->deltaDist.y = fabs(1.0 / tmp_ray->vec.y);
	tmp_ray->mapX = (int)player->pos.x;
	tmp_ray->mapY = (int)player->pos.y;
	// memset함수로 수정 가능
	if (tmp_ray->vec.x < 0)
	{
		tmp_ray->stepX = -1;
		tmp_ray->sideDist.x = (player->pos.x - tmp_ray->mapX) * tmp_ray->deltaDist.x;
	}
	else
	{
		tmp_ray->stepX = 1;
		tmp_ray->sideDist.x = (tmp_ray->mapX + 1.0 - player->pos.x) * tmp_ray->deltaDist.x;
	}
	if (tmp_ray->vec.y < 0)
	{
		tmp_ray->stepY = -1;
		tmp_ray->sideDist.y = (player->pos.y - tmp_ray->mapY) * tmp_ray->deltaDist.y;
	}
	else
	{
		tmp_ray->stepY = 1;
		tmp_ray->sideDist.y = (tmp_ray->mapY + 1.0 - player->pos.y) * tmp_ray->deltaDist.y;
	}
	tmp_ray->hit = 0;
	tmp_ray->side = 0;
}

int raytracing(t_map *map, t_player *player)
{
	int	i;
	double	cam_x;
	t_ray	tmp_ray;

	i = -1;
	while (++i < map->win_width)
	{
		cam_x = (2 * i / (double)map->win_width) - 1;
		ray_init(player, cam_x, &tmp_ray);
		while (!tmp_ray.hit) // DDA 알고리즘 실행 
		{
			if (tmp_ray.sideDist.x < tmp_ray.sideDist.y)
			{
				tmp_ray.sideDist.x += tmp_ray.deltaDist.x;
				tmp_ray.mapX += tmp_ray.stepX;
				tmp_ray.side = 0;
			}
			else
			{
				tmp_ray.sideDist.y += tmp_ray.deltaDist.y;
				tmp_ray.mapY += tmp_ray.stepY;
				tmp_ray.side = 1;
			}
			if (map->map[tmp_ray.mapX][tmp_ray.mapY] > 0)// x, y swap?
				tmp_ray.hit = 1;
		}
		if (tmp_ray.side == 0)
			tmp_ray.perpWallDist = (tmp_ray.mapX - player->pos.x + (1 - tmp_ray.stepX) / 2) / tmp_ray.vec.x;
		else
			tmp_ray.perpWallDist = (tmp_ray.mapY - player->pos.y + (1 - tmp_ray.stepY) / 2) / tmp_ray.vec.y;
		
	}
}