/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/11 20:28:25 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_cub(t_cub *cub, int fd)
{
	char	*str;
	char	**map;

	map = 0;
	str = get_next_line(fd);
	while (str != 0)
	{
		ft_printf("gnl = %s\n", str);
		ft_push_back_matrix(&map, str);
		ft_printf(map[0]);
		free(str);
		str = ft_strtrim2(get_next_line(fd), "\n");
	}
	cub->map.map = map;
	return (0);
}

void	setcub(t_cub *cub)
{
	cub->texture.no_texture.data.img = 0;
	cub->texture.no_text = 0;
	cub->texture.so_texture.data.img = 0;
	cub->texture.we_texture.data.img = 0;
	cub->texture.ea_texture.data.img = 0;
	cub->texture.ceiling_color = -1;
	cub->texture.floor_color = -1;
	return ;
}
