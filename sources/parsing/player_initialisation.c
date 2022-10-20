/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:52:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/20 12:58:49 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_search_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cub->perso.x = -1;
	cub->perso.y = -1;
	while (cub->map.map[i] != 0)
	{
		while (cub->map.map[i][j] != 0)
		{
			if (cub->map.map[i][j] == 'N' && cub->perso.x == -1)
			{
				cub->perso.y = i;
				cub->perso.x = j;
			}
			else if (cub->map.map[i][j] == 'N' || (cub->map.map[i][j] != '0'
				&& cub->map.map[i][j] != '1' && cub->map.map[i][j] != ' '))
			{
				ft_putstr_fd("Error\nbad argument at : ", 2);
				return (ft_putchar_fd(cub->map.map[i][j], 2));
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
