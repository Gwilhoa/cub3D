/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:22:16 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/11 18:51:57 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb_to_hexa(int r, int g, int b)
{
	int	ret;

	ret = (r * (256 * 256)) + (g * 256) + b;
	return (ret);
}

int	parsing_color(t_cub *cub, char *actual_line, char type)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(actual_line, ',');
	if (ft_matrix_size((const char **)split) != 3)
	{
		ft_putstr_fd("error parsing color on ", 2);
		ft_putchar_fd(type, 2);
		ft_putchar_fd('\n', 2);
		i = 1;
	}
	if (type == 'F')
		cub->texture.floor_color = rgb_to_hexa(ft_atoi(split[0]),
				ft_atoi(split[1]), ft_atoi(split[2]));
	else if (type == 'C')
		cub->texture.ceiling_color = rgb_to_hexa(ft_atoi(split[0]),
				ft_atoi(split[1]), ft_atoi(split[2]));
	return (i);
}
