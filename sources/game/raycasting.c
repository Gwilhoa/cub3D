/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:50:46 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/24 12:49:16 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_manager(t_cub *cub)
{
	calcule_ray(cub);
	calcul_step_sidedist(cub);
	ft_dda(cub);
	raytodraw(cub);
	draw_wall(cub);
	draw_line(cub);
}

void	calcule_ray(t_cub *cub)
{
	cub->ray.camerax = 2 * cub->ray.x / (float) W_W - 1;
	cub->ray.dirx = cub->perso.dirx + cub->ray.planx
		* cub->ray.camerax;
	cub->ray.diry = cub->perso.diry + cub->ray.plany
		* cub->ray.camerax;
	if (cub->ray.dirx == 0)
		cub->ray.dirx = 1e-30;
	if (cub->ray.diry == 0)
		cub->ray.diry = 1e-30;
	cub->ray.deltadistx = fabs(1 / cub->ray.dirx);
	cub->ray.deltadisty = fabs(1 / cub->ray.diry);
	cub->ray.mapx = (int)cub->map.pos_x;
	cub->ray.mapy = (int)cub->map.pos_y;
	cub->ray.hit = 0;
}

void	calcul_step_sidedist(t_cub *cub)
{
	if (cub->ray.dirx < 0)
	{
		cub->ray.stepx = -1;
		cub->ray.dirx_dist = (cub->ray.posx
				- cub->ray.mapx) * cub->ray.deltadistx;
	}
	else
	{
		cub->ray.stepx = 1;
		cub->ray.dirx_dist = (cub->ray.mapx + 1
				- cub->ray.posx) * cub->ray.deltadistx;
	}
	if (cub->ray.diry < 0)
	{
		cub->ray.stepy = -1;
		cub->ray.diry_dist = (cub->ray.posy
				- cub->ray.mapy) * cub->ray.deltadisty;
	}
	else
	{
		cub->ray.stepy = 1;
		cub->ray.diry_dist = (cub->ray.mapy + 1.0
				- cub->ray.posy) * cub->ray.deltadisty;
	}
}

void	ft_dda(t_cub *cub)
{
	while (cub->ray.hit == 0)
	{
		if (cub->ray.dirx_dist < cub->ray.diry_dist)
		{
			cub->ray.dirx_dist += cub->ray.deltadistx;
			cub->ray.mapx += cub->ray.stepx;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.diry_dist += cub->ray.deltadisty;
			cub->ray.mapy += cub->ray.stepy;
			cub->ray.side = 1;
		}
		if (cub->ray.mapy < 0)
			cub->ray.mapy = 0;
		if (cub->ray.mapx < 0)
			cub->ray.mapx = 0;
		if (cub->map.map[cub->ray.mapx][cub->ray.mapy] == '1'
			|| cub->map.map[cub->ray.mapx][cub->ray.mapy] == 0)
			cub->ray.hit = 1;
	}
}

void	raytodraw(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		cub->ray.perpwalldist
			= cub->ray.dirx_dist - cub->ray.deltadistx;
	}
	else
	{
		cub->ray.perpwalldist
			= cub->ray.diry_dist - cub->ray.deltadisty;
	}
	cub->ray.lineheight = (int)W_H / cub->ray.perpwalldist;
	cub->ray.drawstart = -cub->ray.lineheight / 2 + W_H / 2;
	if (cub->ray.drawstart < 0)
		cub->ray.drawstart = 0;
	cub->ray.drawend = cub->ray.lineheight / 2 + W_H / 2;
	if (cub->ray.drawend >= W_H || cub->ray.drawend < 0)
		cub->ray.drawend = W_H - 1;
}
