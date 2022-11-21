/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:59:07 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/20 00:54:24 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > W_W - 1 || y > W_H - 1)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
}

void	putsquare(t_data *s_img, int x, int y, int color)
{
	int	tmpx;
	int	tmpy;

	tmpx = 0;
	tmpy = 0;
	while (tmpy <= 10)
	{
		while (tmpx <= 10)
		{
			my_mlx_pixel_put(s_img, (x * 10) + tmpx, (y * 10) + tmpy, color);
			tmpx++;
		}
		tmpx = 0;
		tmpy++;
	}
}
