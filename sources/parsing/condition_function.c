/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:18:35 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/15 00:20:15 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_textured(t_cub *cub)
{
	if (cub->texture.no_texture.data.addr == 0)
		return (true);
	else if (cub->texture.we_texture.data.addr == 0)
		return (true);
	else if (cub->texture.so_texture.data.addr == 0)
		return (true);
	else if (cub->texture.ea_texture.data.addr == 0)
		return (true);
	else if (cub->texture.ceiling_color == -1)
		return (true);
	else if (cub->texture.floor_color == -1)
		return (true);
	else
		return (false);
}

int	is_orientedline(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (true);
	if (ft_strncmp(line, "SO", 2) == 0)
		return (true);
	if (ft_strncmp(line, "WE", 2) == 0)
		return (true);
	if (ft_strncmp(line, "EA", 2) == 0)
		return (true);
	return (false);
}

int	is_direction(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (true);
	return (false);
}
