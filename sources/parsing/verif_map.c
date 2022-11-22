/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:06:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/22 20:17:01 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_validation(t_cub *cub)
{
	char	**map;
	int		ret;

	if (cub->perso.pos.x == -1)
		return (false);
	ret = true;
	map = ft_matrix_dup(cub->map.map);
	if (map == NULL
		|| square_verify(cub->perso.pos.y, cub->perso.pos.x, map) > 0)
		ret = false;
	cub->map.map[(int)cub->perso.pos.y][(int)cub->perso.pos.x] = '0';
	ft_free_matrix(map);
	free(map);
	return (ret);
}

int	square_verify(int x, int y, char **map)
{
	if (x < 0 || y < 0 || map[x] == 0 || ft_strlen(map[x]) < y)
	{
		ft_free_matrix(map);
		free(map);
		map_isopen();
		exit(1);
		return (1);
	}
	if (map[x][y] == '1' || map[x][y] == '-')
		return (0);
	if (map[x][y] == '0' || is_direction(map[x][y]) == true)
	{
		map[x][y] = '-';
		return (square_verify(x + 1, y, map) + square_verify(x - 1, y, map)
			+ square_verify(x, y + 1, map) + square_verify(x, y - 1, map));
	}
	return (1);
}
