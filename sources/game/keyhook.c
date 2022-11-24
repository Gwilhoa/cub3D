/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:20:42 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/24 10:23:52 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_hook_w(t_cub *cub)
{
	if (cub->map.map[(int)(cub->map.pos_x + (cub->perso.dirx
				* cub->ray.speed * 2))][(int)cub->map.pos_y] == '0')
		cub->map.pos_x += cub->perso.dirx * cub->ray.speed;
	if (cub->map.map[(int)(cub->map.pos_x)][(int)(cub->map.pos_y
			+ (cub->perso.diry * cub->ray.speed * 2))] == '0')
		cub->map.pos_y += cub->perso.diry * cub->ray.speed;
}

void	key_hook_s(t_cub *cub)
{
	if (cub->map.map[(int)(cub->map.pos_x - cub->perso.dirx
			* cub->ray.speed * 2)][(int)cub->map.pos_y] == '0')
		cub->map.pos_x -= cub->perso.dirx * cub->ray.speed;
	if (cub->map.map[(int)(cub->map.pos_x)][(int)(cub->map.pos_y
				- (cub->perso.diry * cub->ray.speed * 2))] == '0')
		cub->map.pos_y -= cub->perso.diry * cub->ray.speed;
}

void	key_hook_a(t_cub *cub)
{
	if (cub->map.map[(int)(cub->map.pos_x - cub->perso.diry
			* cub->ray.speed * 2)][(int)cub->map.pos_y] == '0')
		cub->map.pos_x -= cub->perso.diry * cub->ray.speed;
	if (cub->map.map[(int)cub->map.pos_x][(int)(cub->map.pos_y
		+ cub->perso.dirx * cub->ray.speed * 2)] == '0')
		cub->map.pos_y += cub->perso.dirx * cub->ray.speed;
}

void	key_hook_d(t_cub *cub)
{
	if (cub->map.map[(int)(cub->map.pos_x + cub->perso.diry
			* cub->ray.speed * 2)][(int)cub->map.pos_y] == '0')
		cub->map.pos_x += cub->perso.diry * cub->ray.speed;
	if (cub->map.map[(int)cub->ray.posx][(int)(cub->ray.posy
		- cub->perso.dirx * cub->ray.speed * 2)] == '0')
		cub->map.pos_y -= cub->perso.dirx * cub->ray.speed;
}
