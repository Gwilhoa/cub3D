/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:22:16 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/04 14:07:03 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb_to_hexa(int r, int g, int b)
{
	int	ret;

	ret = (r * (256 * 256)) + (g * 256) + b;
	return (ret);
}

int parsing_color(t_cub *cub, char *actual_line, char type)
{
	char	**split;

	split = ft_split(actual_line, ',');
	if (matrix_len(split) != 3)
		ft_putstr_fd("error parsing color", 2);
	if (type == 'F')
		cub->floor_color = rgb_to_hexa(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
	else if (type == 'C')
		cub->ceiling_color = rgb_to_hexa(ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]));
}