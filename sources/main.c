/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/17 16:49:46 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// init_map(t_cub *cub)
// {

// }

int	my_close(int keycode, t_cub *cub)
{
	(void)keycode;
	mlx_destroy_window(cub->link, cub->fen);
	return (0);
}

// int keypad_hook(int keycode, t_cub *cub);
// {

// }

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
	if (!file || parsing_main(file, &cub) == 1)
	{
		exit(1);
	}
	else
	{
		cub.link = mlx_init();
		cub.height = W_H;
		cub.width = W_W;
		cub.s_img = malloc(sizeof(t_data));
		cub.s_ray = malloc(sizeof(t_ray));
		mm_findperso(&cub);

		// init direction of ray;
		cub.s_ray->dirx = -1; 
		cub.s_ray->diry = 0;
		cub.s_ray->planx = 0;
		cub.s_ray->plany = 0.66;
		cub.time = 0;
		cub.oldtime = 0;



		// ._disp_matrix(cub.map);
		cub.fen = mlx_new_window(cub.link, W_W, W_H, "cub3d");
		// parsing_main((char *)argv[1], &cub);
		// init_map(cub);
		// print_sky_floor(&cub, &s_img);
		printf("%f\n", cub.perso.pos.x);
		mlx_loop_hook(cub.link, loop, &cub);
		// mlx_hook(cub.fen, 2, 1L<<0, loop, &cub);
		// il y a mlx_loop_hook qui va looper toutes les fonctions; ->affichage, calcule du ray casting, etc.. tout dedans les touches dedans aussi;
		// mlx_hook(cub.fen, 3, 1L<<0, , &cub); // pitin;
		// mlx_hook(cub.fen, 2, 1L<<0, print_minimap, &cub);
		// mlx_key_hook(cub.fen, ft_print_movement, &struc);		// ICI
		// mlx_key_hook(cub.fen, &print_minimap, &cub);
		mlx_loop(cub.link);

		// t_point2D init;
		// t_point2D end;
		// init.x = 900;
		// init.y = 250;
		// end.x = 0;
		// end.y = 250;
				

		// put_line(cub.link, cub.fen, init, end, 0x00FF00);
		//put_rectangle(cub.link, cub.fen, init, end, 0x0000FF);
	}
	
	return (argc);
}
