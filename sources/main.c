/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/18 14:50:16 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	my_close(t_cub *cub)
{
	(void) cub;
	exit(EXIT_SUCCESS);
	return (1);
}

int	loop(t_cub *cub)
{
	ft_move(cub);
	init_display(cub);
	cub->ray.x = 0;
	while (cub->ray.x < W_W)
	{
		ray_manager(cub);
		cub->ray.x += 1;
	}
	putminimap(cub);
	mlx_put_image_to_window(cub->link, cub->fen, cub->s_img.img, 0, 0);
	return (0);
}

int	main(int argc, char const *argv[])
{
	char	*file;
	t_cub	cub;

	if (argc != 2)
	{
		ft_putstr_fd("Error\ntoo few or not enough argument", 2);
		exit(1);
	}
	file = ft_strdup(argv[1]);
	if (!file || parsing_main(file, &cub) == false)
	{
		exit(1);
	}
	else
	{
		cub.map.pos_x = cub.perso.pos.y;
		cub.map.pos_y = cub.perso.pos.x;
		start_game(&cub);
	}
	return (argc);
}

void	start_game(t_cub *cub)
{
	mlx_hook(cub->fen, 2, 1L << 0, keypad_press, cub);
	mlx_hook(cub->fen, 3, 1L << 1, keypad_release, cub);
	mlx_loop_hook(cub->link, loop, cub);
	mlx_loop(cub->link);
}
