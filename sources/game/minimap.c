/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:47:44 by guyar             #+#    #+#             */
/*   Updated: 2022/11/18 01:32:06 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

void	putminimap(t_cub *cub)
{
	printminimap(cub);
	putperso(cub);
}

void	putperso(t_cub *cub)
{
	putsquare(&cub->s_img, cub->map.pos_y, cub->map.pos_x, 0x000C200);
}

void	printminimap(t_cub *cub)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cub->map.map[i])
	{
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == '1')
				putsquare(&cub->s_img, j, i, 0x00000000);
			if (cub->map.map[i][j] == '0')
				putsquare(&cub->s_img, j, i, cub->texture.floor_color);
			j++;
		}
		j = 0;
		i++;
	}
}
