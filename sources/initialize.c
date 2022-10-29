#include "cub.h"

void ft_initialize_s(t_cub *cub)
{
	cub->s_img.img = NULL;
	cub->s_img.addr = NULL;
	cub->s_img.bits_per_pixel = 0;
	cub->s_img.line_length = 0;
	cub->s_img.endian = 0;

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

	cub->time = 0;
	cub->oldtime = 0;

	cub->texture.no_texture = NULL; 
	cub->texture.so_texture = NULL; 
	cub->texture.we_texture = NULL; 
	cub->texture.ea_texture = NULL; 
	cub->texture.floor_color = 0; 
	cub->texture.ceiling_color = 0;

	cub->key.keyw = 0;		
	cub->key.keys = 0;
	cub->key.rotr = 0;
	cub->key.rotl = 0;

}