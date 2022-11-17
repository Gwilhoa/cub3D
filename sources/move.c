/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:32:45 by guyar             #+#    #+#             */
/*   Updated: 2022/11/17 11:46:52 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int ft_move(t_cub *cub)
{
	double tmpdirx;
	double tmpplnx;
	tmpdirx = cub->s_ray.dirx;
	tmpplnx = cub->s_ray.planx;
	if (cub->key.rotr == 1 && cub->key.rotl == 0)
	{
		// tmpdirx = cub->s_ray.dirx;
		cub->s_ray.dirx = cub->s_ray.dirx * cos(-cub->s_ray.t_speed) - cub->s_ray.diry * sin(-cub->s_ray.t_speed);
		cub->s_ray.diry = tmpdirx * sin(-cub->s_ray.t_speed) + cub->s_ray.diry * cos(-cub->s_ray.t_speed);
		// tmpplnx = cub->s_ray.planx;
		cub->s_ray.planx = cub->s_ray.planx * cos(-cub->s_ray.t_speed) - cub->s_ray.plany * sin(-cub->s_ray.t_speed);
		cub->s_ray.plany = tmpplnx * sin(-cub->s_ray.t_speed) + cub->s_ray.plany * cos(-cub->s_ray.t_speed);
	}
	else if (cub->key.rotl == 1 && cub->key.rotr == 0)
	{
		// tmpdirx = cub->s_ray.dirx;
		cub->s_ray.dirx = cub->s_ray.dirx * cos(cub->s_ray.t_speed) - cub->s_ray.diry * sin(cub->s_ray.t_speed);
		cub->s_ray.diry = tmpdirx * sin(cub->s_ray.t_speed) + cub->s_ray.diry * cos(cub->s_ray.t_speed);
		// tmpplnx = cub->s_ray.planx;
		cub->s_ray.planx = cub->s_ray.planx * cos(cub->s_ray.t_speed) - cub->s_ray.plany * sin(cub->s_ray.t_speed);
		cub->s_ray.plany = tmpplnx * sin(cub->s_ray.t_speed) + cub->s_ray.plany * cos(cub->s_ray.t_speed);
	}
	else if (cub->key.key_w == 1)
	{

		if (cub->map.map[(int)(cub->map.pos_x + (cub->s_ray.dirx * cub->s_ray.speed * 2))][(int)cub->map.pos_y] == '0')
		{
			cub->map.pos_x += cub->s_ray.dirx * cub->s_ray.speed;
			// dprintf(2, "pos x = %f", cub->map.pos_x);
		}
		if(cub->map.map[(int)(cub->map.pos_x)][(int)(cub->map.pos_y + (cub->s_ray.raydiry * cub->s_ray.speed * 2))] == '0')
		{
			cub->map.pos_y += cub->s_ray.diry * cub->s_ray.speed;
			// dprintf(2, "pos y = %f", cub->map.pos_y);
		}
	}
	else if (cub->key.key_s == 1)
	{
		if (cub->map.map[(int)(cub->map.pos_x - (cub->s_ray.dirx * cub->s_ray.speed * 2))][(int)cub->map.pos_y] == '0')
		{
			cub->map.pos_x -= cub->s_ray.dirx * cub->s_ray.speed;
			cub->map.pos_x -= cub->s_ray.dirx * cub->s_ray.speed;
		}
		if(cub->map.map[(int)(cub->map.pos_x)][(int)(cub->map.pos_y - (cub->s_ray.raydiry * cub->s_ray.speed * 2))] == '0')		
		{
			cub->map.pos_y -= cub->s_ray.diry * cub->s_ray.speed;
			cub->map.pos_y -= cub->s_ray.diry * cub->s_ray.speed;

		}
	}
	else if (cub->key.key_a == 1)
	{
		if (cub->map.map[(int)(cub->map.pos_x - (cub->s_ray.dirx * cub->s_ray.speed * 2))][(int)cub->map.pos_y] == '0')
		{
			cub->map.pos_x -= cub->s_ray.dirx * cub->s_ray.speed;
		}
		if(cub->map.map[(int)(cub->map.pos_x)][(int)(cub->map.pos_y - (cub->s_ray.raydiry * cub->s_ray.speed * 2))] == '0')		
		{
			cub->map.pos_y -= cub->s_ray.diry * cub->s_ray.speed;
		}
	}
	
	// if (cub->key.rotl == 1)
	// {
		
	// }
	return (0); 
}