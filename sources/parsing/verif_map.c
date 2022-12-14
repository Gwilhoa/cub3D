/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:06:41 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/30 14:22:28 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	map_validation(t_cub *cub)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (cub->perso.pos.x == -1)
		map_isopen();
	map = cub->map.map;
	while (i < ft_matrix_size((const char **)map))
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (map[i][j] == '0' || is_direction(map[i][j]))
			{
				square_verify(i + 1, j, map);
				square_verify(i - 1, j, map);
				square_verify(i, j + 1, map);
				square_verify(i, j - 1, map);
			}
			j++;
		}
		i++;
	}
	cub->map.map[(int)cub->perso.pos.y][(int)cub->perso.pos.x] = '0';
}

void	square_verify(int x, int y, char **map)
{
	if (x < 0 || y < 0 || map[x] == 0 || ft_strlen(map[x]) < y
		|| map[x][y] == ' ' || map[x][y] == 0)
		map_isopen();
}
