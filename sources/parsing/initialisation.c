/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:39:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/06 21:13:50 by gchatain         ###   ########.fr       */
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
	cub->no_texture = NULL;
	cub->so_texture = 0;
	cub->we_texture = 0;
	cub->ea_texture = 0;
	cub->ceiling_color = -1;
	cub->floor_color = -1;
	cub->perso.x = -1;
	cub->perso.y = -1;
	return ;
}
