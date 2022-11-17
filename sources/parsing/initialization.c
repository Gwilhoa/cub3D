/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/17 22:57:49 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_map(t_cub *cub, int fd)
{
	char	*str;
	char	**map;

	init_display(cub);
	map = 0;
	str = get_next_line(fd);
	while (str != 0)
	{
		ft_push_back_matrix(&map, str);
		free(str);
		str = ft_strtrim2(get_next_line(fd), "\n");
	}
	cub->map.map = map;
	if (map == 0)
		return (empty_map());
	return (true);
}

int	init_texture(t_cub *cub)
{
	cub->texture.no_texture.data.img = 0;
	cub->texture.so_texture.data.img = 0;
	cub->texture.we_texture.data.img = 0;
	cub->texture.ea_texture.data.img = 0;
	cub->texture.ceiling_color = -1;
	cub->texture.floor_color = -1;
	return (parsing_texture(cub));
}

void	init_ray(t_cub *cub)
{
	cub->s_ray.posx = 0;
	cub->s_ray.posy = 0;
	cub->s_ray.raydirx = 0;
	cub->s_ray.raydiry = 0;
	// cub->s_ray.planx = 0;
	// cub->s_ray.plany = 0.66;
	// cub->s_ray.dirx = -1;
	// cub->s_ray.diry = 0;
	cub->s_ray.camerax = 0;
	cub->s_ray.mapx = 0;
	cub->s_ray.mapy = 0;
	cub->s_ray.sidedistx = 0;
	cub->s_ray.sidedisty = 0;
	cub->s_ray.deltadistx = 0;
	cub->s_ray.deltadisty = 0;
	init_ray2(cub);
	init_posplayer(cub);
}

void	init_ray2(t_cub *cub)
{
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

void	init_posplayer(t_cub *cub)
{
	if (cub->perso.direction == 'N')
	{
		cub->s_ray.dirx = -1;
		cub->s_ray.plany = 0.66;
	}
	else if (cub->perso.direction == 'S')
	{
		cub->s_ray.dirx = 1;
		cub->s_ray.plany = -0.66;
	}
	else if (cub->perso.direction == 'W')
	{
		cub->s_ray.diry = -1;
		cub->s_ray.planx = -0.66;
	}
	else if (cub->perso.direction == 'E')
	{
		cub->s_ray.diry = 1;
		cub->s_ray.planx = 0.66;
	}
}

void	init_display(t_cub *cub)
{
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
