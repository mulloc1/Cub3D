#include "cub3d.h"

void	verLine(int x, int drawstart, int drawend, int color, t_cub *cub, double obj_x)
{
	unsigned int	*temp;
	unsigned int	*tex_rgb;
	int				i;

	color++;
	i = -1;
	x = cub->map.win_width - x - 1;
	int img_x = (int)((obj_x - (int)obj_x) * cub->mlx.no.width);
	while (++i < cub->map.win_height)
	{
		temp = (unsigned int*)cub->mlx.buf + (i * cub->map.win_width) + x;
		if (i < cub->map.win_height / 2)
			*temp = cub->map.ceil;
		else
			*temp = cub->map.floor;
	}
	i = drawstart - 1;
	while (++i < drawend)
	{
		double obj_y = (double)(i - drawstart)/(double)(drawend - drawstart);
		int		img_y = (int)(obj_y * cub->mlx.no.height);
		temp = (unsigned int*)cub->mlx.buf + (i * cub->map.win_width) + x;
		tex_rgb = (unsigned int*)cub->mlx.no.img_buf + img_x + img_y * cub->mlx.no.width;
		*temp = *tex_rgb;
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
	  // side == 0 -> x면 충돌 side == 1 ->y면 충돌
	//   double obj_x;
	//   if (ray.side == 0)
	// 	obj_x = ray.sideDist.x + ray.deltaDist.x;
	// else
	// 	obj_x = ray.sideDist.y + ray.deltaDist.y;
	double obj_x = (ray.side == 0) ? cub->player.pos.y + ray.perpWallDist * ray.vec.y : cub->player.pos.x + ray.perpWallDist * ray.vec.x; 
	  int color;
	  color = cub->map.wall_color;
	  if (ray.side == 1)
	  	color = color / 2;
	verLine(i, drawStart, drawEnd, color, cub, obj_x);
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);

	unsigned int *temp;
	unsigned int *tex_rgb;
	for (int i = 0; i < 160; i++)
	{
		for (int j = 0; j < 160; j++)
		{
			temp = (unsigned int*)cub->mlx.buf + (i * cub->map.win_width) + j;
			tex_rgb = (unsigned int*)cub->mlx.no.img_buf + (j / 10) + (i /10) * cub->mlx.no.width;
			*temp = *tex_rgb;
		}
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);

	return(0);
}