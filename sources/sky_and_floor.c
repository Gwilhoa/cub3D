/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_and_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:30:52 by guyar             #+#    #+#             */
/*   Updated: 2022/10/17 11:06:14 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void print_sky_floor(t_cub *cub, t_data *s_img)
{
	int x;
	int y;
	
	s_img->img = mlx_new_image(cub->link, W_W, W_H);
	s_img->addr = mlx_get_data_addr(s_img->img, &s_img->bits_per_pixel, &s_img->line_length,
							&s_img->endian);

	x = 0;
	y = 0;
	while (y < (cub->height / 2))
	{	
		my_mlx_pixel_put(s_img, x, y, 0x00006FFF);
		x++;
		if (x == cub->width)
		{
			x = 0;
			y = y + 1;
		}
	}
	while (y < (cub->height))
	{	
		my_mlx_pixel_put(s_img, x, y, 0x00435369);
		x++;
		if (x == cub->width)
		{
			x = 0;
			y = y + 1;
		}
	}
	mlx_put_image_to_window(cub, cub->fen, s_img->img, 0, 0);
}
