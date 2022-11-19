/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/19 22:15:40 by gchatain         ###   ########.fr       */
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
	cub->ray.posx = 0;
	cub->ray.posy = 0;
	cub->ray.raydirx = 0;
	cub->ray.raydiry = 0;
	cub->ray.camerax = 0;
	cub->ray.mapx = 0;
	cub->ray.mapy = 0;
	cub->ray.sidedistx = 0;
	cub->ray.sidedisty = 0;
	cub->ray.deltadistx = 0;
	cub->ray.deltadisty = 0;
	init_ray2(cub);
	init_posplayer(cub);
}

void	init_ray2(t_cub *cub)
{
	cub->ray.stepx = 0;
	cub->ray.stepy = 0;
	cub->ray.hit = 0;
	cub->ray.side = 0;
	cub->ray.perpwalldist = 0;
	cub->ray.lineheight = 0;
	cub->ray.drawstart = 0;
	cub->ray.drawend = 0;
	cub->ray.x = 0;
	cub->ray.speed = 0.08;
	cub->ray.t_speed = 0.08;
	cub->ray.posx = (double)cub->map.pos_x;
	cub->ray.posy = (double)cub->map.pos_y;
	cub->ray.time = 0;
	cub->ray.oldtime = 0;
}

void	init_posplayer(t_cub *cub)
{
	if (cub->perso.direction == 'N')
	{
		cub->perso.dirx = -1;
		cub->ray.plany = 0.66;
	}
	else if (cub->perso.direction == 'S')
	{
		cub->perso.dirx = 1;
		cub->ray.plany = -0.66;
	}
	else if (cub->perso.direction == 'W')
	{
		cub->perso.diry = -1;
		cub->ray.planx = -0.66;
	}
	else if (cub->perso.direction == 'E')
	{
		cub->perso.diry = 1;
		cub->ray.planx = 0.66;
	}
}
