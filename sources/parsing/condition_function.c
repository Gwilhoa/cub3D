/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:18:35 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/11 17:14:48 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_textured(t_cub *cub)
{
	if (cub->texture.no_texture == 0)
		return (1);
	if (cub->texture.we_texture == 0)
		return (1);
	if (cub->texture.so_texture == 0)
		return (1);
	if (cub->texture.ea_texture == 0)
		return (1);
	if (cub->texture.ceiling_color == -1)
		return (1);
	if (cub->texture.floor_color == -1)
		return (1);
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
