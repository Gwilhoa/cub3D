/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:52:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/06 21:21:14 by gchatain         ###   ########.fr       */
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
			if (cub->map[i][j] == 'N' && cub->perso.x == -1)
			{
				cub->perso.x = i;
				cub->perso.y = j;
			}
			else if (cub->map[i][j] == 'N')
			{
				ft_printf("pos %d;%d",i,j);
				ft_putstr_fd("Error\ntoo many players or unpexted token : ", 2);
				return (ft_putchar_fd(cub->map[i][j], 2));
			}
			j++;
		}
		i++;
	}
	return (0);
}
