/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:32:45 by guyar             #+#    #+#             */
/*   Updated: 2022/11/18 15:26:38 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_move(t_cub *cub)
{
	double	tmpdirx;
	double	tmpplnx;

	tmpdirx = cub->ray.dirx;
	tmpplnx = cub->ray.planx;
	rotate_key(tmpdirx, tmpplnx, cub);
	movement_key(cub);
	return (0);
}

void	movement_key(t_cub *cub)
{
	if (cub->key.key_w == 1)
		key_hook_w(cub);
	if (cub->key.key_s == 1)
		key_hook_s(cub);
	if (cub->key.key_d == 1)
		key_hook_d(cub);
	if (cub->key.key_a == 1)
		key_hook_a(cub);
}

void	rotate_key(double tmpdirx, double tmpplnx, t_cub *cub)
{
	if (cub->key.rotr == 1 && cub->key.rotl == 0)
	{
		cub->ray.dirx = cub->ray.dirx * cos(-cub->ray.t_speed)
			- cub->ray.diry * sin(-cub->ray.t_speed);
		cub->ray.diry = tmpdirx * sin(-cub->ray.t_speed)
			+ cub->ray.diry * cos(-cub->ray.t_speed);
		cub->ray.planx = cub->ray.planx * cos(-cub->ray.t_speed)
			- cub->ray.plany * sin(-cub->ray.t_speed);
		cub->ray.plany = tmpplnx * sin(-cub->ray.t_speed)
			+ cub->ray.plany * cos(-cub->ray.t_speed);
	}
	else if (cub->key.rotl == 1 && cub->key.rotr == 0)
	{
		cub->ray.dirx = cub->ray.dirx * cos(cub->ray.t_speed)
			- cub->ray.diry * sin(cub->ray.t_speed);
		cub->ray.diry = tmpdirx * sin(cub->ray.t_speed)
			+ cub->ray.diry * cos(cub->ray.t_speed);
		cub->ray.planx = cub->ray.planx * cos(cub->ray.t_speed)
			- cub->ray.plany * sin(cub->ray.t_speed);
		cub->ray.plany = tmpplnx * sin(cub->ray.t_speed)
			+ cub->ray.plany * cos(cub->ray.t_speed);
	}
}

int	keypad_press(int keycode, t_cub *cub)
{
	if (keycode == EVENT_ESC)
		my_close(cub);
	else if (keycode == EVENT_W)
		cub->key.key_w = 1;
	else if (keycode == EVENT_S)
		cub->key.key_s = 1;
	else if (keycode == EVENT_D)
		cub->key.key_d = 1;
	else if (keycode == EVENT_A)
		cub->key.key_a = 1;
	else if (keycode == EVENT_ROTR)
		cub->key.rotr = 1;
	else if (keycode == EVENT_ROTL)
		cub->key.rotl = 1;
	return (1);
}

int	keypad_release(int keycode, t_cub *cub)
{
	if (keycode == EVENT_W)
		cub->key.key_w = 0;
	else if (keycode == EVENT_S)
		cub->key.key_s = 0;
	else if (keycode == EVENT_ROTR)
		cub->key.rotr = 0;
	else if (keycode == EVENT_ROTL)
		cub->key.rotl = 0;
	else if (keycode == EVENT_D)
		cub->key.key_d = 0;
	else if (keycode == EVENT_A)
		cub->key.key_a = 0;
	return (0);
}
