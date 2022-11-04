/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:05:06 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/04 15:05:07 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_initialize_s(t_cub *cub)
{
	cub->s_img.img = NULL;
	cub->s_img.addr = NULL;
	cub->s_img.bits_per_pixel = 0;
	cub->s_img.line_length = 0;
	cub->s_img.endian = 0;
	cub->height = W_H;
	cub->width = W_W;
	cub->map.map = NULL;
	cub->map.no = NULL;
	cub->map.so = NULL; 
	cub->map.we = NULL;
	cub->map.ea = NULL;
	cub->map.f = 0;
	cub->map.c = 0;
	cub->map.height = 0;
	cub->map.width = 0;
	cub->map.pos_x = cub->perso.y + 0.2;
	cub->map.pos_y = cub->perso.x + 0.2;
	cub->perso.direction = 0;
	cub->time = 0;
	cub->oldtime = 0;
	cub->key.key_w = 0;
	cub->key.key_s = 0;
	cub->key.rotr = 0;
	cub->key.rotl = 0;
}
