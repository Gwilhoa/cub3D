#include "cub.h"

void ft_initialize_s(t_cub *cub)
{
	cub->height = W_H;
	cub->width = W_W;


	cub->map.map = NULL;
	cub->map.no = NULL;
	cub->map.so = NULL; 
	cub->map.we = NULL;
	cub->map.ea = NULL;
	cub->map.f = 0;
	cub->map.c = 0;
	cub->map.height = 0;
	cub->map.width = 0;
	cub->map.pos_x = cub->perso.y + 0.2;
	cub->map.pos_y = cub->perso.x + 0.2;
	
	cub->perso.x = 0;
	cub->perso.y = 0;
	cub->perso.direction = 0;
	
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

	cub->time = 0;
	cub->oldtime = 0;

	cub->texture.no_texture = NULL; 
	cub->texture.so_texture = NULL; 
	cub->texture.we_texture = NULL; 
	cub->texture.ea_texture = NULL; 
	cub->texture.floor_color = 0; 
	cub->texture.ceiling_color = 0;
}