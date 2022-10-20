/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:06:37 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/20 11:48:06 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	loop(int keycode, t_cub *s_cub)
{
	initializ_ray(s_cub);
	s_cub->s_ray.x = 0;
	while (s_cub->s_ray.x < W_W)
	{
		calcule_ray(s_cub);
		s_cub->s_ray.x += 1;
	}

	mlx_put_image_to_window(s_cub, s_cub->fen, s_cub->s_img.img, 0, 0);
	return (keycode);
}

void initializ_ray(t_cub *s_cub)
{
	s_cub->s_img.img = NULL;
	s_cub->s_img.addr = NULL;
	s_cub->s_img.bits_per_pixel = 0;
	s_cub->s_img.line_length = 0;
	s_cub->s_img.endian = 0;
	s_cub->s_img.img = mlx_new_image(s_cub->link, W_W, W_H);
	s_cub->s_img.addr = mlx_get_data_addr(s_cub->s_img.img, &s_cub->s_img.bits_per_pixel, &s_cub->s_img.line_length,
							&s_cub->s_img.endian);
	exit(EXIT_SUCCESS);
	printf("pos_x = %f, pos_y = %f\n", s_cub->map.pos_x, s_cub->map.pos_y);
	s_cub->s_ray.posx = s_cub->map.pos_x;
	s_cub->s_ray.posy = s_cub->map.pos_y;
	//game->ray.posx = (double)game->map.pos_x;
	//game->ray.posy = (double)game->map.pos_y;

	s_cub->s_ray.camerax = 0;
	s_cub->s_ray.stepx = 0;
	s_cub->s_ray.stepy = 0;
	s_cub->s_ray.hit = 0;
	s_cub->s_ray.side = 0;
	s_cub->s_ray.perpwalldist = 0;
	s_cub->s_ray.lineheight = 0;
	s_cub->s_ray.drawstart = 0;
	s_cub->s_ray.drawend = 0;
	s_cub->s_ray.speed = 0.09;
	s_cub->s_ray.t_speed = 0.09;
}

// ------- debut du rail casting ---- //
void calcule_ray(t_cub *s_cub)
{
	s_cub->s_ray.camerax = (2 * s_cub->s_ray.x) / (W_W - 1);
	s_cub->s_ray.raydirx = s_cub->s_ray.dirx + s_cub->s_ray.planx * s_cub->s_ray.camerax;
	s_cub->s_ray.raydiry = s_cub->s_ray.diry + s_cub->s_ray.plany * s_cub->s_ray.camerax;
	s_cub->s_ray.mapx = s_cub->map.pos_x;
	s_cub->s_ray.mapy = s_cub->map.pos_y;
	s_cub->s_ray.deltadistx = fabs(1 / s_cub->s_ray.raydirx);
	s_cub->s_ray.deltadisty = fabs(1 / s_cub->s_ray.raydiry);
	s_cub->s_ray.hit = 0;
	calcul_step_sidedist(s_cub);
	ft_dda(s_cub);
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

void ft_dda(t_cub *s_cub)
{
	while (s_cub->s_ray.hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
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
		//Check if ray has hit a wall
		if (s_cub->map.map[s_cub->s_ray.mapx][s_cub->s_ray.mapy] == '1')
			s_cub->s_ray.hit = 1;
	}
	raytodraw(s_cub);
}

void raytodraw(t_cub *s_cub)
{
	if (s_cub->s_ray.side == 0)
		s_cub->s_ray.perpwalldist
			= s_cub->s_ray.sidedistx - s_cub->s_ray.deltadistx;
	else
		s_cub->s_ray.perpwalldist
			= s_cub->s_ray.sidedisty - s_cub->s_ray.deltadisty;
	s_cub->s_ray.lineheight = (int)W_H / s_cub->s_ray.perpwalldist;
	s_cub->s_ray.drawstart = -s_cub->s_ray.lineheight / 2 + W_H / 2;
	if (s_cub->s_ray.drawstart < 0)
		s_cub->s_ray.drawstart = 0;
	s_cub->s_ray.drawend = s_cub->s_ray.lineheight / 2 + W_H / 2;
	if (s_cub->s_ray.drawend >= W_H)
		s_cub->s_ray.drawend = W_H - 1;
}

void draw_line(t_cub *s_cub)
{
	int	i;

	i = 0;
	(void)s_cub;

	while (i <= s_cub->s_ray.drawstart)
	{
		my_mlx_pixel_put(s_cub->s_img.img, s_cub->s_ray.x, i, BLUE);
		i++;
	}
	while (s_cub->s_ray.drawstart >= s_cub->s_ray.drawend)
	{
		my_mlx_pixel_put(s_cub->s_img.img, s_cub->s_ray.x, s_cub->s_ray.drawstart, RED);
		s_cub->s_ray.drawstart++;
	}
	i = s_cub->s_ray.drawend;
	while (i <= W_H)
	{
		my_mlx_pixel_put(s_cub->s_img.img, s_cub->s_ray.x, i, GREY);
		i++;
	}
}
// ------- fin du rail casting ---- //