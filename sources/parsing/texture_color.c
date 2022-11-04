/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:22:16 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/04 13:15:01 by gchatain         ###   ########.fr       */
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

	i = 0;
	r = 0;
	split = ft_split(actual_line, ',');
	if (ft_matrix_size((const char **)split) != 3)
	{
		ft_putstr_fd("error parsing color on ", 2);
		ft_putchar_fd(type, 2);
		ft_putchar_fd('\n', 2);
		i = 1;
	}
	while (i != 1 && split[r] != 0)
	{
		s = 0;
		while (split[r][s])
		{
			if (i != 1 && ft_isdigit(split[r][s]) == 0)
			{
				ft_putstr_fd("error number format exception '", 2);
				ft_putchar_fd(split[r][s], 2);
				ft_putstr_fd("' is not a number", 2);
				ft_putchar_fd('\n', 2);
				i = 1;
			}
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
