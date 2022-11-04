/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/04 15:16:40 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_cub(t_cub *cub, int fd)
{
	char	*str;
	char	**map;

	str = get_next_line(fd);
	while (str != 0)
	{
		ft_push_back_matrix(&map, str);
		free(str);
		str = ft_strtrim2(get_next_line(fd), "\n");
	}
	cub->map.map = map;
	return (0);
}

void	setcub(t_cub *cub)
{
	cub->texture.no_texture.img = 0;
	cub->texture.so_texture.img = 0;
	cub->texture.we_texture.img = 0;
	cub->texture.ea_texture.img = 0;
	cub->texture.ceiling_color = -1;
	cub->texture.floor_color = -1;
	return ;
}
