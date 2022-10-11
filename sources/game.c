#include "cub.h"

void game(t_cub *cub)
{
	int x;
	double camerax;
	double	raydirx;
	double	raydiry; 
	x = 0;

	while ( x < W_W)
	{
		camerax = (2 * x) / (W_W * 2) - 1;
		raydirx = cub->perso.dirx + cub->perso.planx * camerax;
		raydiry = cub->perso.diry + cub->perso.plany * camerax;
		x++;
	}
}