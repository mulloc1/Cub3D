#include "cub3d.h"

void	verLine(int x, int drawstart, int drawend, int lineHeight, t_cub *cub, double obj_x, t_texture *tex)
{
	unsigned int	*temp;
	unsigned int	*tex_rgb;
	int				i;
	double obj_y = 0;

	i = -1;
	x = cub->map.win_width - x - 1;
	int img_x = (int)((obj_x - (int)obj_x) * tex->width);
	while (++i < cub->map.win_height)
	{
		temp = (unsigned int*)cub->mlx.buf + (i * cub->map.win_width) + x;
		if (i < cub->map.win_height / 2)
			*temp = cub->map.ceil;
		else
			*temp = cub->map.floor;
	}
    if (drawstart == 0)
        obj_y = lineHeight / 2 - cub->map.win_height / 2;
		//draw_start == 0일 땐 [obj_y = wall_height / 2 - sceenHeight / 2]
	i = drawstart - 1;
	while (++i < drawend)
	{
		int		img_y = (int)(tex->height * (obj_y / lineHeight));
		temp = (unsigned int*)cub->mlx.buf + (i * cub->map.win_width) + x;
		tex_rgb = (unsigned int*)tex->img_buf + img_x + img_y * tex->size / (tex->bpp / 8);
		*temp = *tex_rgb;
        obj_y++;
	}
}

t_texture *find_dir(t_ray *ray, t_cub *cub)
{
	if (ray->side)
	{
		if (ray->vec.y < 0)
			return (&cub->mlx.so);
		else
			return (&cub->mlx.no);
	}
	else
	{
		if (ray->vec.x < 0)
			return (&cub->mlx.ea);
		else
			return (&cub->mlx.we);
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
	int drawStart = -lineHeight / 2 + cub->map.win_height / 2;
	if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + cub->map.win_height / 2;
	if(drawEnd >= cub->map.win_height) drawEnd = cub->map.win_height - 1;
	double obj_x = (ray.side == 0) ? cub->player.pos.y + ray.perpWallDist * ray.vec.y : cub->player.pos.x + ray.perpWallDist * ray.vec.x; 
	t_texture *tex = find_dir(&ray, cub);
	verLine(i, drawStart, drawEnd, lineHeight, cub, obj_x, tex);
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	return(0);
}
