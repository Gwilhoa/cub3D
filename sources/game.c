/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:06:37 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/14 15:02:50 by guyar            ###   ########.fr       */
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
	mlx_put_image_to_window(cub->link, cub->fen, cub->s_img.img, 0, 0);
	return (0);
}

void init_display(t_cub *cub)
{
	// cub->s_img.img = NULL;
	// cub->s_img.addr = NULL;
	// cub->s_img.line_length = 0;
	// cub->s_img.endian = 0;
	// cub->s_img.img = mlx_new_image(cub->link, W_W, W_H);
	// cub->s_img.addr = mlx_get_data_addr(cub->s_img.img, &cub->s_img.bits_per_pixel, &cub->s_img.line_length,
	// 						&cub->s_img.endian);
	cub->s_ray.camerax = 0;
	cub->s_ray.stepx = 0;
	cub->s_ray.stepy = 0;
	cub->s_ray.hit = 0;
	cub->s_ray.side = 0;
	cub->s_ray.perpwalldist = 0;
	cub->s_ray.lineheight = 0;
	cub->s_ray.drawstart = 0;
	cub->s_ray.drawend = 0;
	cub->s_ray.posx = (double)(cub->map.pos_x);
	cub->s_ray.posy = (double)(cub->map.pos_y);
}

void	initializ_ray(t_cub *cub)
{
	cub->s_ray.posx = 0;
	cub->s_ray.posy = 0;
	cub->s_ray.raydirx = 0;
	cub->s_ray.raydiry = 0;
	cub->s_ray.planx = 0;
	cub->s_ray.plany = 0.66;
	cub->s_ray.dirx = -1;
	cub->s_ray.diry = 0;
	cub->s_ray.camerax = 0;
	cub->s_ray.mapx = 0;
	cub->s_ray.mapy = 0;
	cub->s_ray.sidedistx = 0;
	cub->s_ray.sidedisty = 0;
	cub->s_ray.deltadistx = 0;
	cub->s_ray.deltadisty = 0;
	cub->s_ray.stepx = 0;
	cub->s_ray.stepy = 0;
	cub->s_ray.hit = 0;
	cub->s_ray.side = 0;
	cub->s_ray.perpwalldist = 0;
	cub->s_ray.lineheight = 0;
	cub->s_ray.drawstart = 0;
	cub->s_ray.drawend = 0;
	cub->s_ray.x = 0;
	cub->s_ray.speed = 0.09;
	cub->s_ray.t_speed = 0.09;
	cub->s_ray.posx = (double)cub->map.pos_x;
	cub->s_ray.posy = (double)cub->map.pos_y;
	cub->s_ray.time = 0;
	cub->s_ray.oldtime = 0;
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
	s_cub->s_ray.camerax = 2 * s_cub->s_ray.x / (double) W_W - 1;
	s_cub->s_ray.raydirx = s_cub->s_ray.dirx + s_cub->s_ray.planx * s_cub->s_ray.camerax;
	s_cub->s_ray.raydiry = s_cub->s_ray.diry + s_cub->s_ray.plany * s_cub->s_ray.camerax;
	s_cub->s_ray.mapx = s_cub->map.pos_x;
	s_cub->s_ray.mapy = s_cub->map.pos_y;
	s_cub->s_ray.deltadistx = fabs(1 / s_cub->s_ray.raydirx);	// si == 0 ? 
	s_cub->s_ray.deltadisty = fabs(1 / s_cub->s_ray.raydiry); // si == 0 ?
	s_cub->s_ray.hit = 0;
	calcul_step_sidedist(s_cub);
	ft_dda(s_cub);
	draw_vline(s_cub);
	draw_line(s_cub);
}

void	calcul_step_sidedist(t_cub *s_cub) //raystep
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
		s_cub->s_ray.sidedistx = (s_cub->s_ray.mapx + 1.0
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
		// dprintf(2, "mapx == %d\nmapy == %d\n)", s_cub->s_ray.mapx, s_cub->s_ray.mapy);
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

// void draw_line(t_cub *s_cub)
// {
// 	int		i;
// 	double	step;
// 	double	texpos;
// 	i = 0;
// 	step = 1 * 32 / s_cub->s_ray.lineheight;
// 	texpos = (s_cub->s_ray.drawstart - W_H * 0.5 + s_cub->s_ray.lineheight * 0.5) * step;
// 	while (i <= s_cub->s_ray.drawstart)
// 	{
// 		my_mlx_pixel_put(&s_cub->s_img, s_cub->s_ray.x, i, s_cub->texture.ceiling_color);
// 		i++;
// 	}
// 	while (s_cub->s_ray.drawstart <= s_cub->s_ray.drawend)
// 	{
// 		texpos += step;
// 		s_cub->s_ray.drawstart++;
// 		my_mlx_pixel_put(&s_cub->s_img, s_cub->s_ray.x, s_cub->s_ray.drawstart, get_pixel(s_cub->texture.no_texture.data, get_textural_x(find_wall_pos(s_cub), s_cub->texture.no_texture, s_cub), (int)texpos & (32 - 1)));										
// 	}
// 	i = s_cub->s_ray.drawend;
// 	while (i < W_H)
// 	{
// 		my_mlx_pixel_put(&s_cub->s_img, s_cub->s_ray.x, i, s_cub->texture.floor_color);
// 		i++;
// 	}
// }

void draw_line(t_cub *s_cub)
{
    //int    texNum = s_cub->map.map[s_cub->s_ray.mapx][s_cub->s_ray.mapy] - 1;
    double wall_x;
    int tex_x;

    if (s_cub->s_ray.side == 0)
        wall_x = s_cub->s_ray.posy + s_cub->s_ray.perpwalldist + s_cub->s_ray.raydiry;
    else
        wall_x = s_cub->s_ray.posx + s_cub->s_ray.perpwalldist + s_cub->s_ray.raydirx;
    wall_x -= floor(wall_x);
    tex_x = (int)(wall_x * (double)s_cub->texture.no_texture.width);
    if (s_cub->s_ray.side == 0 && s_cub->s_ray.raydirx > 0)
        tex_x = s_cub->texture.no_texture.width - tex_x - 1;
    if (s_cub->s_ray.side == 1 && s_cub->s_ray.raydiry < 0)
        tex_x = s_cub->texture.no_texture.width - tex_x - 1;
    double step;
    step = 1 * s_cub->texture.no_texture.width / s_cub->s_ray.lineheight;
    double texpos = ((s_cub->s_ray.drawstart - W_H * 0.5 + s_cub->s_ray.lineheight * 0.5) * step);
    int y = s_cub->s_ray.drawstart;
	int tex_y;
	tex_y = (int) texpos & (s_cub->texture.no_texture.width - 1);
    texpos += step;
	my_mlx_pixel_put(&s_cub->s_img, s_cub->s_ray.x, y, get_pixel(&s_cub->texture.no_texture.data, tex_x, tex_y));
    // while (y < s_cub->s_ray.drawstart)
    // {
    //     my_mlx_pixel_put(&s_cub->s_img, s_cub->s_ray.x, y, s_cub->texture.ceiling_color);
    //     y++;
    // }
    while (y < s_cub->s_ray.drawend)
    {
        int tex_y;
        tex_y = (int) texpos & (s_cub->texture.no_texture.width - 1);
        texpos += step;
        my_mlx_pixel_put(&s_cub->s_img, s_cub->s_ray.x, y, get_pixel(&s_cub->texture.no_texture.data, tex_x, tex_y));
        y++;
    }
	    int i = 0;
    int j = 0;
    while (i <= 32)
    {
        j = 0;
        while (j <= 32)
        {
            my_mlx_pixel_put(&s_cub->s_img, i+64, j+64, get_pixel(&s_cub->texture.no_texture.data, i, j));
            j++;
        }
        i++;
    }
    // while (y < W_H)
    // {
    //     my_mlx_pixel_put(&s_cub->s_img, s_cub->s_ray.x, y, s_cub->texture.floor_color);
    //     y++;
    // }
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

int	get_textural_x(int wallx, t_texture_img img, t_cub *cub)
{
	// x coordinate of the texture;
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
