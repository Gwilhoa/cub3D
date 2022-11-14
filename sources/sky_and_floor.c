/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_and_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:30:52 by guyar             #+#    #+#             */
/*   Updated: 2022/11/12 21:22:14 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > W_W - 1 || y > W_H - 1)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_pixel(t_data *data, int x, int y)
{
	int		color;
	char	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	color = *(unsigned int *)dst;
	return (color);
	// return (*(unsigned int*) data.addr + (y * data.line_length + x * (data.bits_per_pixel / 8)));
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
