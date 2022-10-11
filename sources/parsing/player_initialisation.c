/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:52:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/11 18:51:45 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_search_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cub->map[i] != 0)
	{
		while (cub->map[i][j] != 0)
		{
			if (cub->map[i][j] == 'N' && cub->perso.pos.x == -1)
			{
				cub->perso.pos.x = i;
				cub->perso.pos.y = j;
			}
			else if (cub->map[i][j] == 'N' || (cub->map[i][j] != '0'
				&& cub->map[i][j] != '1' && cub->map[i][j] != ' '))
			{
				ft_putstr_fd("Error\nbad argument at : ", 2);
				return (ft_putchar_fd(cub->map[i][j], 2));
			}
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
	return (0);
}
