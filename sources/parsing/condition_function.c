/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:18:35 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/04 15:54:21 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_textured(t_cub *cub)
{
	if (cub->texture.no_texture.img == 0)
		return (1);
	else if (cub->texture.we_texture.img == 0)
		return (1);
	else if (cub->texture.so_texture.img == 0)
		return (1);
	else if (cub->texture.ea_texture.img == 0)
		return (1);
	else if (cub->texture.ceiling_color == -1)
		return (1);
	else if (cub->texture.floor_color == -1)
		return (1);
	else
		return (0);
}

int	is_orientedline(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (1);
	if (ft_strncmp(line, "SO", 2) == 0)
		return (1);
	if (ft_strncmp(line, "WE", 2) == 0)
		return (1);
	if (ft_strncmp(line, "EA", 2) == 0)
		return (1);
	return (0);
}
