/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/06 20:32:47 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char const *argv[])
{
	t_cub	cub;

	if (argc == 2)
	{
		if (parsing_main((char *)argv[1], &cub) != 1)
		{
			ft_printf("%s", cub.no_texture);
			ft_disp_matrix(cub.map);
			exit(0);
		}
		else
		{
			exit(1);
		}
	}
	else
		ft_putstr_fd
		("Error\nno more or too many argument /cub3d [filename].cub", 2);
	exit(0);
	return (argc);
}
