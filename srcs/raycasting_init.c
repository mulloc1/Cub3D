#include "cub3d.h"

static t_texture	*find_dir(t_ray *ray, t_cub *cub)
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

static void	ray_init2(t_ray *ray, t_player *player)
{
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
}

void	ray_init(t_player *player, double cam_x, t_ray *ray)
{
	ft_memset(ray, 0, sizeof(t_ray));
	ray->vec.x = player->dir.x + player->plane.x * cam_x;
	ray->vec.y = player->dir.y + player->plane.y * cam_x;
	ray->mapX = (int)player->pos.x;
	ray->mapY = (int)player->pos.y;
	if (ray->vec.x == 0)
		ray->deltaDist.x = VEC_MAX;
	else
		ray->deltaDist.x = fabs(1 / ray->vec.x);
	if (ray->vec.y == 0)
		ray->deltaDist.y = VEC_MAX;
	else
		ray->deltaDist.y = fabs(1 / ray->vec.y);
	ray_init2(ray, player);
}

void	draw_init(t_draw *draw, t_cub *cub, t_ray *ray, int i)
{
	ft_memset(draw, 0, sizeof(t_draw));
	draw->draw_height = (int)(cub->map.win_height / ray->perpWallDist);
	draw->start = -draw->draw_height / 2 + cub->map.win_height / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->draw_height / 2 + cub->map.win_height / 2;
	if (draw->end >= cub->map.win_height)
		draw->end = cub->map.win_height - 1;
	if (ray->side == 0)
		draw->pos_x = cub->player.pos.y + ray->perpWallDist * ray->vec.y;
	else
		draw->pos_x = cub->player.pos.x + ray->perpWallDist * ray->vec.x;
	draw->texture = find_dir(ray, cub);
	draw->x = i;
}
