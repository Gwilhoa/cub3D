/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:06:37 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/17 22:53:22 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	loop(t_cub *cub)
{
	ft_move(cub);
	init_display(cub);
	cub->s_ray.x = 0;
	while (cub->s_ray.x < W_W)
	{
		calcule_ray(cub);
		cub->s_ray.x += 1;
	}
	putminimap(cub);
	mlx_put_image_to_window(cub->link, cub->fen, cub->s_img.img, 0, 0);
	return (0);
}


void draw_vline(t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < cub->s_ray.drawstart)
		my_mlx_pixel_put(&cub->s_img, cub->s_ray.x, i, cub->texture.ceiling_color);
	while (i < cub->s_ray.drawend)
		i++;
	while (i < W_H)
	{
		my_mlx_pixel_put(&cub->s_img, cub->s_ray.x, i, cub->texture.floor_color);
		i++;
	}
}

// ------- debut du rail casting ---- //
void	calcule_ray(t_cub *s_cub)
{
	s_cub->s_ray.camerax = 2 * s_cub->s_ray.x / (float) W_W - 1;
	s_cub->s_ray.raydirx = s_cub->s_ray.dirx + s_cub->s_ray.planx * s_cub->s_ray.camerax;
	s_cub->s_ray.raydiry = s_cub->s_ray.diry + s_cub->s_ray.plany * s_cub->s_ray.camerax;
	if (s_cub->s_ray.raydirx == 0)
		s_cub->s_ray.raydirx = 1e-30;
	if (s_cub->s_ray.raydiry == 0)
		s_cub->s_ray.raydiry = 1e-30;
	s_cub->s_ray.deltadistx = fabs(1 / s_cub->s_ray.raydirx);	// si == 0 ? 
	s_cub->s_ray.deltadisty = fabs(1 / s_cub->s_ray.raydiry); // si == 0 ?
	s_cub->s_ray.mapx = (int)s_cub->map.pos_x;
	s_cub->s_ray.mapy = (int)s_cub->map.pos_y;
	s_cub->s_ray.hit = 0;
	calcul_step_sidedist(s_cub);
	ft_dda(s_cub);
	draw_vline(s_cub);
	draw_line(s_cub);
}

void	calcul_step_sidedist(t_cub *s_cub)
{
	if (s_cub->s_ray.raydirx < 0)
	{
		s_cub->s_ray.stepx = -1;
		s_cub->s_ray.sidedistx = (s_cub->s_ray.posx
				- s_cub->s_ray.mapx) * s_cub->s_ray.deltadistx;
	}
	else
	{
		s_cub->s_ray.stepx = 1;
		s_cub->s_ray.sidedistx = (s_cub->s_ray.mapx + 1
				- s_cub->s_ray.posx) * s_cub->s_ray.deltadistx;
	}
	if (s_cub->s_ray.raydiry < 0)
	{
		s_cub->s_ray.stepy = -1;
		s_cub->s_ray.sidedisty = (s_cub->s_ray.posy
				- s_cub->s_ray.mapy) * s_cub->s_ray.deltadisty;
	}
	else
	{
		s_cub->s_ray.stepy = 1;
		s_cub->s_ray.sidedisty = (s_cub->s_ray.mapy + 1.0
				- s_cub->s_ray.posy) * s_cub->s_ray.deltadisty;
	}
}

void	ft_dda(t_cub *s_cub)
{
	while (s_cub->s_ray.hit == 0)
	{
		if (s_cub->s_ray.sidedistx < s_cub->s_ray.sidedisty)
		{
			s_cub->s_ray.sidedistx += s_cub->s_ray.deltadistx;
			s_cub->s_ray.mapx += s_cub->s_ray.stepx;
			s_cub->s_ray.side = 0;
		}
		else
		{
			s_cub->s_ray.sidedisty += s_cub->s_ray.deltadisty;
			s_cub->s_ray.mapy += s_cub->s_ray.stepy;
			s_cub->s_ray.side = 1;
		}
		if (s_cub->s_ray.mapy < 0)
			s_cub->s_ray.mapy = 0;
		if (s_cub->s_ray.mapx < 0)
			s_cub->s_ray.mapx = 0;
		if (s_cub->map.map[s_cub->s_ray.mapx][s_cub->s_ray.mapy] == '1')
			s_cub->s_ray.hit = 1;
	}
	raytodraw(s_cub);
}

void	raytodraw(t_cub *s_cub)
{
	if (s_cub->s_ray.side == 0)
	{
			s_cub->s_ray.perpwalldist
			= s_cub->s_ray.sidedistx - s_cub->s_ray.deltadistx;
	}
	else
	{
		s_cub->s_ray.perpwalldist
			= s_cub->s_ray.sidedisty - s_cub->s_ray.deltadisty;
	}
	s_cub->s_ray.lineheight = (int)W_H / s_cub->s_ray.perpwalldist;
	s_cub->s_ray.drawstart = -s_cub->s_ray.lineheight / 2 + W_H / 2;
	if (s_cub->s_ray.drawstart < 0)
		s_cub->s_ray.drawstart = 0;
	s_cub->s_ray.drawend = s_cub->s_ray.lineheight / 2 + W_H / 2;
	if (s_cub->s_ray.drawend >= W_H || s_cub->s_ray.drawend < 0)
		s_cub->s_ray.drawend = W_H - 1;
}

void draw_line(t_cub *s_cub)		// draw wall / put text on wall;
{
	double wall_x;
	int tex_x;
	int color;
	int tex_y;
	double step;
	double texpos;
	int y;
	t_img img;

	if (s_cub->s_ray.side == 0 && (s_cub->s_ray.mapx < s_cub->s_ray.posx))
	{
		img = s_cub->texture.no_texture;
	}
	else if (s_cub->s_ray.side == 0 && (s_cub->s_ray.mapx > s_cub->s_ray.posx))
	{
		img = s_cub->texture.so_texture;
	}
	else if (s_cub->s_ray.side == 1 && (s_cub->s_ray.mapy < s_cub->s_ray.posy))
	{
		img = s_cub->texture.ea_texture;
	}
	else if (s_cub->s_ray.side == 1 && (s_cub->s_ray.mapy > s_cub->s_ray.posy))
	{
		img = s_cub->texture.we_texture;
	}
    if (s_cub->s_ray.side == 0)
        wall_x = s_cub->s_ray.posy + s_cub->s_ray.perpwalldist * s_cub->s_ray.raydiry; // pb ici;
    else
        wall_x = s_cub->s_ray.posx + s_cub->s_ray.perpwalldist * s_cub->s_ray.raydirx;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)img.width);
    if (s_cub->s_ray.side == 0 && s_cub->s_ray.raydirx > 0)
		tex_x = img.width - tex_x - 1;
	if (s_cub->s_ray.side == 1 && s_cub->s_ray.raydiry < 0)
		tex_x = img.width - tex_x - 1;
	step = 1.0 * img.width / s_cub->s_ray.lineheight;
	texpos = ((s_cub->s_ray.drawstart - W_H * 0.5 + s_cub->s_ray.lineheight * 0.5) * step);
	y = s_cub->s_ray.drawstart;
    while (y < s_cub->s_ray.drawend)
	{
		tex_y = (int) texpos & (img.width - 1);
		texpos += step;
		color = get_pixel(&img.data, tex_x, tex_y);
		my_mlx_pixel_put(&s_cub->s_img, s_cub->s_ray.x, y, color);
		y++;
	}
}

// ------- fin du rail casting ---- //

// calcule de wallX;
int find_wall_pos(t_cub *cub)
{
	double wallx;
	if (cub->s_ray.side == 0)
	{
		wallx = cub->s_ray.posy + cub->s_ray.perpwalldist * cub->s_ray.raydiry;
	}
	else
	{
		wallx = cub->s_ray.posx + cub->s_ray.perpwalldist * cub->s_ray.raydirx;
	}
	wallx = wallx - floor(wallx);
	return (wallx);
}

int	get_textural_x(int wallx, t_img img, t_cub *cub)
{
	int	tex_x;

	tex_x = (int)(wallx * (img.width * 2));
	if (cub->s_ray.side == 0 && cub->s_ray.raydirx > 0)
	{
		tex_x = img.width - tex_x - 1;
	}
	if (cub->s_ray.side == 1 && cub->s_ray.raydiry < 0)
	{
		tex_x = img.width - tex_x - 1;
	}
	return (tex_x);
}
