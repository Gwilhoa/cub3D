/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:06:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/08/17 10:51:03 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void put_line(void *link, void *fen, t_point2D init, t_point2D end, int color)
{
	int	dx;
	int	dy;
	int e;

	dx = end.x - init.x;
	dy = end.y - init.y;
	
	if (dx != 0)
	{
		if (dx > 0)
		{
			if (dy != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dy = dy * 2;
						dx = e*2;
						while (init.x < end.x) {
							mlx_pixel_put(link, fen, init.x, init.y, color);
							init.x++;
							e -= dy;
							if (e < 0)
							{
								init.y += 1;
								e += dx;
							}
						}
					}
					else 
					{
						e = dy;
						dy = e*2;
						dx = dx * 2;
						while (init.y < end.y)
						{
							mlx_pixel_put(link, fen, init.x, init.y, color);
							init.y++;
							e = e - dx;
							if (e < 0)
							{
								init.x += 1;
								e += dy;
							}
						}
					}
				}
				else 
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = e*2;
						dy = dy*2;
						while (init.x < end.x)
						{
							mlx_pixel_put(link, fen, init.x, init.y, color);
							e = e + dy;
							if (e < 0) {
								init.y += 1;
								e += dx;
							}
						}
					}
					else 
					{
						e = dy;
						dy = e*2;
						dx = dx*2;
						while (init.y < end.y)
						{
							mlx_pixel_put(link, fen, init.x, init.y, color);
							e = e + dx;
							if (e < 0) {
								init.x += 1;
								e += dy;
							}
						}
					}
				}
			}
			else
			{
				while (init.x < end.x)
				{
					mlx_pixel_put(link, fen, init.x, init.y, color);
					init.x++;
				}
			}
		} 
		else 
		{
			dy = end.y - init.y;
			if (dy != 0) {
				if (dy > 0) 
				{
					if (-dx >= dy)
					{
						e = dx;
						dx = e*2;
						e = dy*2;
						while (init.x < end.x)
						{
							mlx_pixel_put(link, fen, init.x, init.y, color);
							e = e + dy;
							if (e <= 0) {
								init.y += 1;
								e += dx;
							}
						}
					}
					else 
					{
						e = dy;
						dy = e*2;
						dx = dx*2;
						while (init.y < end.y)
						{
							mlx_pixel_put(link, fen, init.x, init.y, color);
							e = e + dx;
							if (e <= 0) {
								init.x += 1;
								e += dy;
							}
						}
					}
				}
				else {
					if (dx <= dy) {
						e = dx;
						dx = e*2;
						dy = dy*2;
						while (init.x < end.x)
						{
							mlx_pixel_put(link, fen, init.x, init.y, color);
							e = e - dy;
							if (e >= 0) {
								init.y -= 1;
								e += dx;
							}
						}
					}
					else 
					{
						e = dy;
						dy = e*2;
						dx = dx*2;
						while (init.y < end.y)
						{
							mlx_pixel_put(link, fen, init.x, init.y, color);
							e = e - dx;
							if (e >= 0) {
								init.x -= 1;
								e += dy;
							}
						}
					}
				}
			} 
			else 
			{
				while (init.x > end.x)
				{
					mlx_pixel_put(link, fen, init.x, init.y, color);
					init.x--;
				}
			}
		}
	}
	else 
	{
		dy = end.y - init.y;
		if (dy != 0)
		{
			if (dy > 0)
			{
				while (init.y < end.y)
				{
					mlx_pixel_put(link, fen, init.x, init.y, color);
					init.y++;
				}
			}
			else
			{
				while (init.y > end.y)
				{
					mlx_pixel_put(link, fen, init.x, init.y, color);
					init.y--;
				}
			}
		}
	}
	mlx_pixel_put(link, fen, end.x, end.y, color);
}
