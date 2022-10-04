/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/09/30 19:15:06 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char const *argv[])
{
	t_cub	cub;

	if (argc == 2)
	{
		parsing_main((char *)argv[1], &cub);
		ft_disp_matrix(cub.map);
	}
	else
		ft_putstr_fd("no more or too many argument /cub3d [filename].cub", 2);
	exit(0);
	return (argc);
}
