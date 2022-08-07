#include "cub3d.h"

static int	rot_vector(t_player *player, int direction)
{
	double	old_dirx;
	double	old_camx;

	old_dirx = player->dir.x;
	old_camx = player->plane.x;
	if (direction == RIGHT)
	{
		player->dir.x = old_dirx * cos(ROT_R) - player->dir.y * sin(ROT_R);
		player->dir.y = old_dirx * sin(ROT_R) + player->dir.y * cos(ROT_R);
		player->plane.x = old_camx * cos(ROT_R) - player->plane.y * sin(ROT_R);
		player->plane.y = old_camx * sin(ROT_R) + player->plane.y * cos(ROT_R);
	}
	else
	{
		player->dir.x = old_dirx * cos(ROT_L) - player->dir.y * sin(ROT_L);
		player->dir.y = old_dirx * sin(ROT_L) + player->dir.y * cos(ROT_L);
		player->plane.x = old_camx * cos(ROT_L) - player->plane.y * sin(ROT_L);
		player->plane.y = old_camx * sin(ROT_L) + player->plane.y * cos(ROT_L);
	}
	return (0);
}

static int	move_vector(t_player *player, int key_code, t_cub *cub)
{
	t_vector	new_pos;

	if (key_code == KEY_W)
	{
		new_pos.x = player->pos.x + (player->dir.x * MOVE_SPEED);
		new_pos.y = player->pos.y + (player->dir.y * MOVE_SPEED);
	}
	else if (key_code == KEY_A)
	{
		new_pos.x = player->pos.x + (player->dir.y * MOVE_SPEED);
		new_pos.y = player->pos.y + ((player->dir.x * -1) * MOVE_SPEED);
	}
	else if (key_code == KEY_S)
	{
		new_pos.x = player->pos.x + ((player->dir.x * -1) * MOVE_SPEED);
		new_pos.y = player->pos.y + ((player->dir.y * -1) * MOVE_SPEED);
	}
	else if (key_code == KEY_D)
	{
		new_pos.x = player->pos.x + ((player->dir.y * -1) * MOVE_SPEED);
		new_pos.y = player->pos.y + (player->dir.x * MOVE_SPEED);
	}
	if (cub->map.map[(int)new_pos.y][(int)new_pos.x] == '0')
		player->pos = new_pos;
	return (0);
}

int	key_hook(int key_code, t_cub *cub)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (key_code == KEY_LEFT)
		rot_vector(&cub->player, LEFT);
	else if (key_code == KEY_RIGHT)
		rot_vector(&cub->player, RIGHT);
	else if (key_code == KEY_W)
		move_vector(&cub->player, key_code, cub);
	else if (key_code == KEY_A)
		move_vector(&cub->player, key_code, cub);
	else if (key_code == KEY_S)
		move_vector(&cub->player, key_code, cub);
	else if (key_code == KEY_D)
		move_vector(&cub->player, key_code, cub);
	raycasting(cub);
	return (0);
}
