#include "cub3d.h"

int rotate_vector(t_player *player, int right)
{
	// right = 1 -> turn right
	// right = 0 -> turn left
	double	old_dirX;
	double	old_camX;

	old_dirX = player->dir.x;
	old_camX = player->plane.x;
	if (right == 1)
	{
		player->dir.x = old_dirX * cos(ROTATE_R) -  player->dir.y * sin(ROTATE_R);
		player->dir.y = old_dirX * sin(ROTATE_R) + player->dir.y * cos(ROTATE_R);
		player->plane.x = old_camX * cos(ROTATE_R) - player->plane.y * sin(ROTATE_R);
		player->plane.y = old_camX * sin(ROTATE_R) + player->plane.y * cos(ROTATE_R);
	}
	else
	{
		player->dir.x = old_dirX * cos(ROTATE_L) -  player->dir.y * sin(ROTATE_L);
		player->dir.y = old_dirX * sin(ROTATE_L) + player->dir.y * cos(ROTATE_L);
		player->plane.x = old_camX * cos(ROTATE_L) - player->plane.y * sin(ROTATE_L);
		player->plane.y = old_camX * sin(ROTATE_L) + player->plane.y * cos(ROTATE_L);
	}
	return (0);
}

void	verLine(int x, int drawstart, int drawend, int color, t_cub *cub)
{
	unsigned int	*temp;
	printf("%d %d\n", drawstart, drawend);
	for (int i = drawstart; i < drawend; i++)
	{
		temp = (unsigned int*)cub->mlx.buf + (i * cub->map.win_width) + x;
		*temp = color;
	}
}

int	ray_init(t_player *player, double cam_x, t_ray *ray)
{
	ft_memset(ray, 0, sizeof(t_ray));
	ray->vec.x = player->dir.x + player->plane.x * cam_x;
	ray->vec.y = player->dir.y + player->plane.y * cam_x;
	ray->mapX = (int)player->pos.x;
	ray->mapY = (int)player->pos.y;
	if (ray->vec.x == 0)
		ray->deltaDist.x = 999999999; // 0일경우 아주 큰 값 -> define 필요
	else
		ray->deltaDist.x = fabs(1 / ray->vec.x);
	if (ray->vec.y == 0)
		ray->deltaDist.y = 999999999; // 0일경우 아주 큰 값 -> define 필요
	else
		ray->deltaDist.y = fabs(1 / ray->vec.y);
	if (ray->vec.x < 0)
	{
		ray->stepX = -1;
		ray->sideDist.x = (player->pos.x - ray->mapX) * ray->deltaDist.x;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDist.x = (ray->mapX + 1.0 - player->pos.x) * ray->deltaDist.x;
	}
	if (ray->vec.y < 0)
	{
		ray->stepY = -1;
		ray->sideDist.y = (player->pos.y - ray->mapY) * ray->deltaDist.y;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDist.y = (ray->mapY + 1.0 - player->pos.y) * ray->deltaDist.y;
	}
	return (0);
}


int raycasting(t_cub *cub)
{
	int	i;
	double	cam_x;
	t_ray	ray;

	i = -1;
	while (++i < cub->map.win_width)
	{
		cam_x = 2 * i / (double)cub->map.win_width - 1;
		ray_init(&(cub->player), cam_x, &ray);
		while (!ray.hit)
		{
			if (ray.sideDist.x < ray.sideDist.y)
			{
				ray.sideDist.x += ray.deltaDist.x;
				ray.mapX += ray.stepX;
				ray.side = 0;
			}
			else
			{
				ray.sideDist.y += ray.deltaDist.y;
				ray.mapY += ray.stepY;
				ray.side = 1;
			}
			if (cub->map.map[ray.mapY][ray.mapX] > '0')
				ray.hit = 1;
		}
		if (ray.side == 0)
			ray.perpWallDist = ray.sideDist.x - ray.deltaDist.x;
		else
			ray.perpWallDist = ray.sideDist.y - ray.deltaDist.y;
		int lineHeight = (int)(cub->map.win_height / ray.perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + cub->map.win_height / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + cub->map.win_height / 2;
      if(drawEnd >= cub->map.win_height) drawEnd = cub->map.win_height - 1;
	  int color;
	  color = cub->map.wall_color;
	  if (ray.side == 1)
	  	color = color / 2;
	verLine(i, drawStart, drawEnd, color, cub);
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	return(0);
}