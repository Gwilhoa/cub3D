/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/11 18:45:35 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	init_cub(t_cub *cub, int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str != 0)
	{
		ft_push_back_matrix(&cub->map, ft_strtrim(str, "\n"));
		free(str);
		str = get_next_line(fd);
	}
	return (0);
}

void	setcub(t_cub *cub)
{
	cub->map = NULL;
	cub->texture.no_texture = NULL;
	cub->texture.so_texture = 0;
	cub->texture.we_texture = 0;
	cub->texture.ea_texture = 0;
	cub->texture.ceiling_color = -1;
	cub->texture.floor_color = -1;
	cub->perso.pos.x = -1;
	cub->perso.pos.y = -1;
	return ;
}
