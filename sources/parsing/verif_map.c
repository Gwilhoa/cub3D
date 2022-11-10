/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:06:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/09 14:10:00 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	isvalid(t_cub *cub)
{
	char	**map;

	map = ft_matrix_dup(cub->map.map);
	if (verif(cub->perso.y, cub->perso.x, map) > 0)
	{
		return (1);
	}
	return (0);
}

int	verif(int x, int y, char **map)
{
	if (x < 0 || y < 0 || map[x] == 0 || ft_strlen(map[x]) < y)
		return (1);
	if (map[x][y] == '1' || map[x][y] == '-')
	{
		return (0);
	}
	if (map[x][y] == '0' || map[x][y] == 'N')
	{
		map[x][y] = '-';
		return (verif(x + 1, y, map) + verif(x - 1, y, map)
			+ verif(x, y + 1, map) + verif(x, y - 1, map));
	}
	return (1);
}
