/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:52:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/24 10:24:27 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_cub *cub)
{
	cub->link = mlx_init();
	init_screen(cub);
	cub->fen = mlx_new_window(cub->link, W_W, W_H, "cub3d");
	cub->s_img.img = mlx_new_image(cub->link, W_W, W_H);
	cub->s_img.addr = mlx_get_data_addr(cub->s_img.img, \
	&cub->s_img.bits_per_pixel, &cub->s_img.line_length, &cub->s_img.endian);
}

void	init_screen(t_cub *cub)
{
	cub->s_img.img = NULL;
	cub->s_img.addr = NULL;
	cub->s_img.bits_per_pixel = 0;
	cub->s_img.line_length = 0;
	cub->s_img.endian = 0;
	cub->height = W_H;
	cub->width = W_W;
}

void	init_key(t_cub *cub)
{
	cub->perso.direction = 0;
	cub->time = 0;
	cub->oldtime = 0;
	cub->key.key_m = 0;
	cub->key.key_w = 0;
	cub->key.key_s = 0;
	cub->key.key_a = 0;
	cub->key.key_d = 0;
	cub->key.rotr = 0;
	cub->key.rotl = 0;
}

void	init_minimap(t_cub *cub)
{
	cub->map.no = NULL;
	cub->map.so = NULL;
	cub->map.we = NULL;
	cub->map.ea = NULL;
	cub->map.f = 0;
	cub->map.c = 0;
	cub->map.height = 0;
	cub->map.width = 0;
	cub->map.pos_x = cub->perso.pos.y + 0.2;
	cub->map.pos_y = cub->perso.pos.x + 0.2;
}

void	init_display(t_cub *cub)
{
	cub->ray.camerax = 0;
	cub->ray.stepx = 0;
	cub->ray.stepy = 0;
	cub->ray.hit = 0;
	cub->ray.side = 0;
	cub->ray.perpwalldist = 0;
	cub->ray.lineheight = 0;
	cub->ray.drawstart = 0;
	cub->ray.drawend = 0;
	cub->ray.posx = (double)(cub->map.pos_x);
	cub->ray.posy = (double)(cub->map.pos_y);
}
