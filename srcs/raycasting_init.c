/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonkim <jonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:10:12 by jonkim            #+#    #+#             */
/*   Updated: 2022/08/09 12:10:13 by jonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ray->stepx = -1;
		ray->sidedist.x = (player->pos.x - ray->mapx) * ray->deltadist.x;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedist.x = (ray->mapx + 1.0 - player->pos.x) * ray->deltadist.x;
	}
	if (ray->vec.y < 0)
	{
		ray->stepy = -1;
		ray->sidedist.y = (player->pos.y - ray->mapy) * ray->deltadist.y;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedist.y = (ray->mapy + 1.0 - player->pos.y) * ray->deltadist.y;
	}
}

void	ray_init(t_player *player, double cam_x, t_ray *ray)
{
	ft_memset(ray, 0, sizeof(t_ray));
	ray->vec.x = player->dir.x + player->plane.x * cam_x;
	ray->vec.y = player->dir.y + player->plane.y * cam_x;
	ray->mapx = (int)player->pos.x;
	ray->mapy = (int)player->pos.y;
	if (ray->vec.x == 0)
		ray->deltadist.x = VEC_MAX;
	else
		ray->deltadist.x = fabs(1 / ray->vec.x);
	if (ray->vec.y == 0)
		ray->deltadist.y = VEC_MAX;
	else
		ray->deltadist.y = fabs(1 / ray->vec.y);
	ray_init2(ray, player);
}

void	draw_init(t_draw *draw, t_cub *cub, t_ray *ray, int i)
{
	ft_memset(draw, 0, sizeof(t_draw));
	draw->draw_height = (int)(cub->map.win_height / ray->perpwalldist);
	draw->start = -draw->draw_height / 2 + cub->map.win_height / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->draw_height / 2 + cub->map.win_height / 2;
	if (draw->end >= cub->map.win_height)
		draw->end = cub->map.win_height - 1;
	if (ray->side == 0)
		draw->pos_x = cub->player.pos.y + ray->perpwalldist * ray->vec.y;
	else
		draw->pos_x = cub->player.pos.x + ray->perpwalldist * ray->vec.x;
	draw->texture = find_dir(ray, cub);
	draw->x = i;
}
