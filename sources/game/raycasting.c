/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:50:46 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/19 17:34:32 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_manager(t_cub *cub)
{
	calcule_ray(cub);
	calcul_step_sidedist(cub);
	ft_dda(cub);
	raytodraw(cub);
	draw_vline(cub);
	draw_line(cub);
}

void	calcule_ray(t_cub *s_cub)
{
	s_cub->ray.camerax = 2 * s_cub->ray.x / (float) W_W - 1;
	s_cub->ray.raydirx = s_cub->perso.dirx + s_cub->ray.planx
		* s_cub->ray.camerax;
	s_cub->ray.raydiry = s_cub->perso.diry + s_cub->ray.plany
		* s_cub->ray.camerax;
	if (s_cub->ray.raydirx == 0)
		s_cub->ray.raydirx = 1e-30;
	if (s_cub->ray.raydiry == 0)
		s_cub->ray.raydiry = 1e-30;
	s_cub->ray.deltadistx = fabs(1 / s_cub->ray.raydirx);
	s_cub->ray.deltadisty = fabs(1 / s_cub->ray.raydiry);
	s_cub->ray.mapx = (int)s_cub->map.pos_x;
	s_cub->ray.mapy = (int)s_cub->map.pos_y;
	s_cub->ray.hit = 0;
}

void	calcul_step_sidedist(t_cub *s_cub)
{
	if (s_cub->ray.raydirx < 0)
	{
		s_cub->ray.stepx = -1;
		s_cub->ray.sidedistx = (s_cub->ray.posx
				- s_cub->ray.mapx) * s_cub->ray.deltadistx;
	}
	else
	{
		s_cub->ray.stepx = 1;
		s_cub->ray.sidedistx = (s_cub->ray.mapx + 1
				- s_cub->ray.posx) * s_cub->ray.deltadistx;
	}
	if (s_cub->ray.raydiry < 0)
	{
		s_cub->ray.stepy = -1;
		s_cub->ray.sidedisty = (s_cub->ray.posy
				- s_cub->ray.mapy) * s_cub->ray.deltadisty;
	}
	else
	{
		s_cub->ray.stepy = 1;
		s_cub->ray.sidedisty = (s_cub->ray.mapy + 1.0
				- s_cub->ray.posy) * s_cub->ray.deltadisty;
	}
}

void	ft_dda(t_cub *s_cub)
{
	while (s_cub->ray.hit == 0)
	{
		if (s_cub->ray.sidedistx < s_cub->ray.sidedisty)
		{
			s_cub->ray.sidedistx += s_cub->ray.deltadistx;
			s_cub->ray.mapx += s_cub->ray.stepx;
			s_cub->ray.side = 0;
		}
		else
		{
			s_cub->ray.sidedisty += s_cub->ray.deltadisty;
			s_cub->ray.mapy += s_cub->ray.stepy;
			s_cub->ray.side = 1;
		}
		if (s_cub->ray.mapy < 0)
			s_cub->ray.mapy = 0;
		if (s_cub->ray.mapx < 0)
			s_cub->ray.mapx = 0;
		if (s_cub->map.map[s_cub->ray.mapx][s_cub->ray.mapy] == '1'
			|| s_cub->map.map[s_cub->ray.mapx][s_cub->ray.mapy] == 0)
			s_cub->ray.hit = 1;
	}
}

void	raytodraw(t_cub *s_cub)
{
	if (s_cub->ray.side == 0)
	{
		s_cub->ray.perpwalldist
			= s_cub->ray.sidedistx - s_cub->ray.deltadistx;
	}
	else
	{
		s_cub->ray.perpwalldist
			= s_cub->ray.sidedisty - s_cub->ray.deltadisty;
	}
	s_cub->ray.lineheight = (int)W_H / s_cub->ray.perpwalldist;
	s_cub->ray.drawstart = -s_cub->ray.lineheight / 2 + W_H / 2;
	if (s_cub->ray.drawstart < 0)
		s_cub->ray.drawstart = 0;
	s_cub->ray.drawend = s_cub->ray.lineheight / 2 + W_H / 2;
	if (s_cub->ray.drawend >= W_H || s_cub->ray.drawend < 0)
		s_cub->ray.drawend = W_H - 1;
}
