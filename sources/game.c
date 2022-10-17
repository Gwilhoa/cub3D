#include "cub.h"

int loop(int keycode, t_cub *s_cub)
{
	initializ_ray(s_cub, s_cub->s_ray);
	s_cub->s_ray->x = 0;
	while (s_cub->s_ray->x < W_W)
	{
		calcule_ray(s_cub, s_cub->s_ray);
		s_cub->s_ray->x += 1;
	}
	mlx_put_image_to_window(s_cub, s_cub->fen, s_cub->s_img->img, 0, 0);
	return (keycode);
}

void initializ_ray(t_cub *s_cub, t_ray *s_ray)
{
	s_cub->s_img->img = NULL;
	s_cub->s_img->addr = NULL;
	s_cub->s_img->bits_per_pixel = 0;
	s_cub->s_img->line_length = 0;
	s_cub->s_img->endian = 0;
	s_cub->s_img->img = mlx_new_image(s_cub->link, W_W, W_H);
	s_cub->s_img->addr = mlx_get_data_addr(s_cub->s_img->img, &s_cub->s_img->bits_per_pixel, &s_cub->s_img->line_length,
							&s_cub->s_img->endian);
	s_ray->camerax = 0;
	s_ray->stepx = 0;
	s_ray->stepy = 0;
	s_ray->hit = 0;
	s_ray->side = 0;
	s_ray->perpwalldist = 0;
	s_ray->lineheight = 0;
	s_ray->drawstart = 0;
}

// ------- debut du rail casting ---- //
void calcule_ray(t_cub *s_cub, t_ray *s_ray)
{

	s_ray->camerax = (2 * s_ray->x) / (W_W * 2) - 1;
	s_ray->raydirx = s_ray->dirx + s_ray->planx *s_ray->camerax;
	s_ray->raydiry = s_ray->diry + s_ray->plany * s_ray->camerax;
	printf("j == %f\n", s_cub->perso.pos.x);
	s_ray->mapx = s_cub->perso.pos.x;
	s_ray->mapy = s_cub->perso.pos.y;
	s_ray->deltadistx = fabs(1 / s_ray->raydirx);
	s_ray->deltadisty = fabs(1 / s_ray->raydiry);
	s_ray->hit = 0;
	calcul_step_sidedist(s_cub, s_ray);
	do_dda(s_cub, s_ray);
	draw_line(s_cub, s_ray);
}

void	calcul_step_sidedist(t_cub *s_cub, t_ray *s_ray)
{
	if (s_ray->raydirx < 0)
	{
		s_ray->stepx = -1;
		s_ray->sidedistx = (s_cub->perso.pos.x - s_ray->mapx) * s_ray->deltadistx;
	}
    else
    {
    	s_ray->stepx = 1;
    	s_ray->sidedistx = (s_ray->mapx + 1.0 - s_cub->perso.pos.x) * s_ray->deltadistx;
    }
    if (s_ray->raydiry < 0)
    {
    	s_ray->stepy = -1;
    	s_ray->sidedisty = (s_cub->perso.pos.y - s_ray->mapy) * s_ray->deltadisty;
    }
    else
    {
    	s_ray->stepy = 1;
    	s_ray->sidedisty = (s_ray->mapy + 1.0 -s_cub->perso.pos.y) * s_ray->deltadisty;
    }
}

void do_dda(t_cub *s_cub, t_ray *s_ray)
{
	if (s_ray->raydirx < 0)
    {
    	s_ray->stepx = -1;
    	s_ray->sidedistx = (s_cub->perso.pos.x - s_ray->mapx) * s_ray->deltadistx;
    }
    else
    {
    	s_ray->stepx = 1;
    	s_ray->sidedistx = (s_ray->mapx + 1.0 - s_cub->perso.pos.x) * s_ray->deltadistx;
    }
    if (s_ray->raydiry < 0)
    {
    	s_ray->stepy = -1;
    	s_ray->sidedisty = (s_cub->perso.pos.y - s_ray->mapy) * s_ray->deltadisty;
    }
    else
    {
    	s_ray->stepy = 1;
    	s_ray->sidedisty = (s_ray->mapy + 1.0 -s_cub->perso.pos.y) * s_ray->deltadisty;
    }
}
void ft_dda(t_cub *s_cub, t_ray *s_ray)
{
	while (s_ray->hit == 0)
    {
    	//jump to next map square, either in x-direction, or in y-direction
    	if (s_ray->sidedistx < s_ray->sidedisty)
    	{
        	s_ray->sidedistx += s_ray->deltadistx;
        	s_ray->mapx += s_ray->stepx;
        	s_ray->side = 0;
        }
        else
        {
        	s_ray->sidedisty += s_ray->deltadisty;
        	s_ray->mapy += s_ray->stepy;
        	s_ray->side = 1;
        }
        //Check if ray has hit a wall
        if (s_cub->map[s_ray->mapx][s_ray->mapy] > '1') 
			s_ray->hit = 1;
	  }
	  raytodraw(s_cub, s_ray);
}

void raytodraw(t_cub *s_cub, t_ray *s_ray)
{
	(void)s_cub;
	if (s_ray->side == 0)
		s_ray->perpwalldist = s_ray->sidedistx - s_ray->deltadistx;
	else
		s_ray->perpwalldist = s_ray->sidedistx - s_ray->deltadistx;

	s_ray->lineheight = (int)W_H / s_ray->perpwalldist;
	s_ray->drawstart = (-s_ray->lineheight / 2)+ (W_H / 2);
    if (s_ray->drawstart < 0)
	{	
		s_ray->drawstart = 0;
	}
    s_ray->drawend = (s_ray->lineheight / 2) + (W_H / 2);
	if (s_ray->drawend >= W_H)
		s_ray->drawend = W_H - 1;
}

void draw_line(t_cub *s_cub, t_ray *s_ray)
{
	int i;

	i = 0;
	(void)s_cub;

	while (i <= s_ray->drawstart)
	{
		my_mlx_pixel_put(s_cub->s_img->img, s_ray->x, i, s_cub->texture.ceiling_color);
		i++;
	}
	while (s_ray->drawstart >= s_ray->drawend)
	{
		my_mlx_pixel_put(s_cub->s_img->img, s_ray->x, s_ray->drawstart, RED);
		s_ray->drawstart++;
	}
	i = s_ray->drawend;
	while (i <= W_H)
	{
		my_mlx_pixel_put(s_cub->s_img->img, s_ray->x, i, s_cub->texture.floor_color);
		i++;
	}
}
// ------- fin du rail casting ---- //