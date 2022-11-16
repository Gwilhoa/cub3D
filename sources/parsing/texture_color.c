/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:22:16 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/15 18:21:05 by gchatain         ###   ########.fr       */
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
	int		r;
	int		s;

	i = true;
	r = 0;
	split = ft_split(actual_line, ',');
	if (ft_matrix_size((const char **)split) != 3)
		i = color_badargument(type);
	while (i != false && split[r] != 0)
	{
		s = 0;
		while (split[r][s])
		{
			if (i != false && ft_isdigit(split[r][s]) == 0)
				i = color_numberformat(split[r][s]);
			s++;
		}
		r++;
	}
	if (type == 'F')
		cub->texture.floor_color = rgb_to_hexa(ft_atoi(split[0]),
				ft_atoi(split[1]), ft_atoi(split[2]));
	else if (type == 'C')
		cub->texture.ceiling_color = rgb_to_hexa(ft_atoi(split[0]),
				ft_atoi(split[1]), ft_atoi(split[2]));
	free(actual_line);
	ft_free_matrix(split);
	free(split);
	return (i);
}
