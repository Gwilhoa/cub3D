/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:32:45 by guyar             #+#    #+#             */
/*   Updated: 2022/11/01 19:26:25 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int ft_move(t_cub *cub)
{
	if (cub->key.keyW == 1)
	{
		if(cub->map.map[(int)(cub->map.pos_x + (cub->s_ray.dirx * cub->s_ray.speed * 2))][(int)cub->map.pos_y] == '0')
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
	// if (cub->key.keyW == 0)
		// dprintf(2, "PAS DEDAN\n");
	return (0); 
}