/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:52:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/17 20:27:25 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_mlx(t_cub *cub)
{
	cub->link = mlx_init();
	init_screen(cub);
	cub->fen = mlx_new_window(cub->link, W_W, W_H, "cub3d");
	cub->s_img.img = mlx_new_image(cub->link, W_W, W_H);
	cub->s_img.addr = mlx_get_data_addr(cub->s_img.img, \
	&cub->s_img.bits_per_pixel, &cub->s_img.line_length, &cub->s_img.endian);
}

void	init_screen(t_cub *cub)
{
	cub->s_img.img = NULL;
	cub->s_img.addr = NULL;
	cub->s_img.bits_per_pixel = 0;
	cub->s_img.line_length = 0;
	cub->s_img.endian = 0;
	cub->height = W_H;
	cub->width = W_W;
}

void	init_key(t_cub *cub)
{
	cub->perso.direction = 0;
	cub->time = 0;
	cub->oldtime = 0;
	cub->key.key_w = 0;
	cub->key.key_s = 0;
	cub->key.key_a = 0;
	cub->key.key_d = 0;
	cub->key.rotr = 0;
	cub->key.rotl = 0;
}

void	init_minimap(t_cub *cub)
{
	cub->map.no = NULL;
	cub->map.so = NULL;
	cub->map.we = NULL;
	cub->map.ea = NULL;
	cub->map.f = 0;
	cub->map.c = 0;
	cub->map.height = 0;
	cub->map.width = 0;
	cub->map.pos_x = cub->perso.pos.y + 0.2;
	cub->map.pos_y = cub->perso.pos.x + 0.2;
}

int	search_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.map[i] != 0)
	{
		j = 0;
		while (cub->map.map[i][j] != 0)
		{
			if (is_direction(cub->map.map[i][j]) && cub->perso.pos.x == -1)
			{
				cub->perso.direction = cub->map.map[i][j];
				cub->perso.pos.y = i;
				cub->perso.pos.x = j;
			}
			else if (is_direction(cub->map.map[i][j]) || (cub->map.map[i][j]
			!= '0' && cub->map.map[i][j] != '1' && cub->map.map[i][j] != ' '))
				return (map_badargument(cub->map.map[i][j]));
			j++;
		}
		i++;
	}
	if (map_validation(cub) == false)
		return (map_isopen());
	return (true);
}
