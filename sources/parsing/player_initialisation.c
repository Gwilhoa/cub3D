/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:52:47 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/07 17:45:06 by gchatain         ###   ########.fr       */
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
			ft_printf("%c | ", cub->map[i][j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i++;
	}
	return (0);
}
