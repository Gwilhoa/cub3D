/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rendered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:57:36 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/18 16:24:30 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_img	getside_img(t_cub *cub)
{
	if (cub->ray.side == 0 && (cub->ray.mapx < cub->ray.posx))
		return (cub->texture.no_texture);
	else if (cub->ray.side == 0 && (cub->ray.mapx > cub->ray.posx))
		return (cub->texture.so_texture);
	else if (cub->ray.side == 1 && (cub->ray.mapy < cub->ray.posy))
		return (cub->texture.ea_texture);
	else
		return (cub->texture.we_texture);
}

double	get_wallx(t_cub *cub)
{
	double	ret;

	if (cub->ray.side == 0)
		ret = cub->ray.posy + cub->ray.perpwalldist * cub->ray.raydiry;
	else
		ret = cub->ray.posx + cub->ray.perpwalldist * cub->ray.raydirx;
	ret -= floor(ret);
	return (ret);
}

void	draw_line(t_cub *cub)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	texpos;
	t_img	img;

	img = getside_img(cub);
	tex_x = (int)(get_wallx(cub) * (double)img.width);
	if (cub->ray.side == 0 && cub->ray.raydirx > 0)
		tex_x = img.width - tex_x - 1;
	if (cub->ray.side == 1 && cub->ray.raydiry < 0)
		tex_x = img.width - tex_x - 1;
	step = 1.0 * img.width / cub->ray.lineheight;
	texpos = ((cub->ray.drawstart - W_H * 0.5
				+ cub->ray.lineheight * 0.5) * step);
	while (cub->ray.drawstart < cub->ray.drawend)
	{
		tex_y = (int) texpos & (img.width - 1);
		texpos += step;
		my_mlx_pixel_put(&cub->s_img, cub->ray.x, cub->ray.drawstart,
			get_pixel(&img.data, tex_x, tex_y));
		cub->ray.drawstart++;
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
