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

int move_vector(t_player *player, int key_code)
{
	t_vector old_pos; //ㅊㅓ음 서있던 위치
	t_vector mov_dir; // 움직일 방향 
	 
	old_pos = player->pos;
	if (key_code == 13)// move foward
	{
		mov_dir = player->dir;
		player->pos.x = player->pos.x + (player->dir.x * 0.222);
		player->pos.y = player->pos.y + (player->dir.y * 0.222);	
	}
	else if (key_code == 0) // move left
	{
		mov_dir = player->dir;
		player->pos.x = player->pos.x + ((player->dir.y * -1) * 0.222);
		player->pos.y = player->pos.y + (player->dir.x * 0.222);	
	}
	else if (key_code == 1)// move backward
	{
		mov_dir = player->dir;
		player->pos.x = player->pos.x + ((player->dir.x * -1) * 0.222);
		player->pos.y = player->pos.y + ((player->dir.y * -1) * 0.222);	
	}
	else if (key_code == 2) // move right
	{
		mov_dir = player->dir;
		player->pos.x = player->pos.x + (player->dir.y * 0.222);
		player->pos.y = player->pos.y + ((player->dir.x * -1) * 0.222);	
	}
	return (0);
}



int key_hook(int key_code, t_cub *cub)
{
	if (key_code == 53) // esc
		exit(0);
	else if (key_code == 123) // left
		rotate_vector(&cub->player, 0);
	else if (key_code == 124) // right
		rotate_vector(&cub->player, 1);
	else if (key_code == 13) // w
		move_vector(&cub->player, key_code);
	else if (key_code == 0) // a
		move_vector(&cub->player, key_code);
	else if (key_code == 1) // s
		move_vector(&cub->player, key_code);
	else if (key_code == 2) // d
		move_vector(&cub->player, key_code);
	raycasting(cub);
	return (0);
}