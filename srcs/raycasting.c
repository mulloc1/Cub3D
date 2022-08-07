#include "cub3d.h"

static void	draw_ceil_floor(t_cub *cub, t_draw *draw)
{
	unsigned int	*temp;
	int				i;

	i = -1;
	draw->x = cub->map.win_width - draw->x - 1;
	while (++i < cub->map.win_height)
	{
		temp = (unsigned int *)cub->mlx.buf + (i * cub->map.win_width) \
		+ draw->x;
		if (i < cub->map.win_height / 2)
			*temp = cub->map.ceil;
		else
			*temp = cub->map.floor;
	}
}

static void	draw_wall(t_cub *cub, t_draw *draw)
{
	unsigned int	*temp;
	unsigned int	*tex_rgb;
	int				i;

	i = draw->start - 1;
	draw->tex_x = (int)((draw->pos_x - (int)draw->pos_x) \
	* draw->texture->width);
	if (draw->start == 0)
		draw->pos_y = draw->draw_height / 2 - cub->map.win_height / 2;
	while (++i < draw->end)
	{
		draw->tex_y = (int)(draw->texture->height * \
		(draw->pos_y / draw->draw_height));
		temp = (unsigned int *)cub->mlx.buf + \
		(i * cub->map.win_width) + draw->x;
		tex_rgb = (unsigned int *)draw->texture->img_buf \
		+ draw->tex_x + draw->tex_y * draw->texture->size / \
		(draw->texture->bpp / 8);
		*temp = *tex_rgb;
		draw->pos_y++;
	}
}

static void	ray_hit(t_ray *ray, t_cub *cub)
{
	while (!ray->hit)
	{
		if (ray->sideDist.x < ray->sideDist.y)
		{
			ray->sideDist.x += ray->deltaDist.x;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDist.y += ray->deltaDist.y;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (cub->map.map[ray->mapY][ray->mapX] > '0')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perpWallDist = ray->sideDist.x - ray->deltaDist.x;
	else
		ray->perpWallDist = ray->sideDist.y - ray->deltaDist.y;
}

int	raycasting(t_cub *cub)
{
	int		i;
	double	cam_x;
	t_ray	ray;
	t_draw	draw;

	i = -1;
	while (++i < cub->map.win_width)
	{
		cam_x = 2 * i / (double)cub->map.win_width - 1;
		ray_init(&(cub->player), cam_x, &ray);
		ray_hit(&ray, cub);
		draw_init(&draw, cub, &ray, i);
		draw_ceil_floor(cub, &draw);
		draw_wall(cub, &draw);
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	return (0);
}
