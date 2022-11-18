/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rendered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:57:36 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/18 01:36:14 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_line(t_cub *s_cub)
{
	double	wall_x;
	int		tex_x;
	int		color;
	int		tex_y;
	double	step;
	double	texpos;
	int		y;
	t_img	img;

	if (s_cub->ray.side == 0 && (s_cub->ray.mapx < s_cub->ray.posx))
		img = s_cub->texture.no_texture;
	else if (s_cub->ray.side == 0 && (s_cub->ray.mapx > s_cub->ray.posx))
		img = s_cub->texture.so_texture;
	else if (s_cub->ray.side == 1 && (s_cub->ray.mapy < s_cub->ray.posy))
		img = s_cub->texture.ea_texture;
	else if (s_cub->ray.side == 1 && (s_cub->ray.mapy > s_cub->ray.posy))
		img = s_cub->texture.we_texture;
	if (s_cub->ray.side == 0)
		wall_x = s_cub->ray.posy + s_cub->ray.perpwalldist * s_cub->ray.raydiry;
	else
		 wall_x = s_cub->ray.posx + s_cub->ray.perpwalldist * s_cub->ray.raydirx;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)img.width);
	if (s_cub->ray.side == 0 && s_cub->ray.raydirx > 0)
		tex_x = img.width - tex_x - 1;
	if (s_cub->ray.side == 1 && s_cub->ray.raydiry < 0)
		tex_x = img.width - tex_x - 1;
	step = 1.0 * img.width / s_cub->ray.lineheight;
	texpos = ((s_cub->ray.drawstart - W_H * 0.5 + s_cub->ray.lineheight * 0.5) * step);
	y = s_cub->ray.drawstart;
	while (y < s_cub->ray.drawend)
	{
		tex_y = (int) texpos & (img.width - 1);
		texpos += step;
		color = get_pixel(&img.data, tex_x, tex_y);
		my_mlx_pixel_put(&s_cub->s_img, s_cub->ray.x, y, color);
		y++;
	}
}

void	draw_vline(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->ray.drawstart)
		my_mlx_pixel_put
			(&cub->s_img, cub->ray.x, i, cub->texture.ceiling_color);
	while (i < cub->ray.drawend)
		i++;
	while (i < W_H)
	{
		my_mlx_pixel_put
			(&cub->s_img, cub->ray.x, i, cub->texture.floor_color);
		i++;
	}
}