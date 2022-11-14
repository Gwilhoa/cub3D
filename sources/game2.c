/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:04:13 by guyar             #+#    #+#             */
/*   Updated: 2022/11/12 20:38:49 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void start_game(t_cub *cub)
{
	init_mlx(cub);
	initializ_ray(cub);
	mlx_hook(cub->fen, 2, 1L<<0, keypad_press, cub);
	mlx_hook(cub->fen, 3, 1L<<1, keypad_release, cub);
	// dprintf(2, "entree loop key = %d\n", cub->key.keyW);
	mlx_loop_hook(cub->link, loop, cub);
	mlx_loop(cub->link);
}

void init_mlx(t_cub *cub)
{
	// cub->link = mlx_init();
	cub->fen = mlx_new_window(cub->link, W_W, W_H, "cub3d");
	cub->s_img.img = mlx_new_image(cub->link, W_W, W_H);
	cub->s_img.addr = mlx_get_data_addr(cub->s_img.img, &cub->s_img.bits_per_pixel, &cub->s_img.line_length,
							&cub->s_img.endian);
}
