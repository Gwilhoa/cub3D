/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/01 19:02:00 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// init_map(t_cub *cub)
// {

// }



int	my_close(t_cub *cub)
{
	(void)cub;
	// mlx_destroy_window(cub->link, cub->fen); // segfault;
	exit(EXIT_SUCCESS);
	return (1);
}

int	keypad_press(int keycode, t_cub *cub)
{

	// (void)cub;
	if (keycode == EVENT_ESC)
		my_close(cub);
	else if (keycode == EVENT_W)
	{
		cub->key.keyW = 1;
		// dprintf(2, "keyw = %d\n", cub->key.keyW = 1);
	}
	else if (keycode == EVENT_S)
	{
		ft_printf("PRESS S\n");
		cub->key.keyS = 1;
	}
	else
		return (0);
	return (1);
	// if (keycode == EVENT_A)
	// {
	// 	ft_printf("A\n");
	// }
	// if (keycode == EVENT_D)
	// {
	// 	ft_printf("D\n");
	// }
	// loop(cub);
}

int keypad_release(int keycode, t_cub *cub)
{
	if (keycode == EVENT_W)
	{
		dprintf(2, "RELEASE W\n");
		cub->key.keyW = 0;
	}
	if (keycode == EVENT_S)
	{
		dprintf(2, "RELEASE S\n");
		cub->key.keyS = 0;
	}
	return (0);
}


void ft_initialise_mlx(t_cub *cub)
{
	cub->link = mlx_init();
	cub->fen = mlx_new_window(cub->link, W_W, W_H, "cub3d");
}

int	main(int argc, char const *argv[])
{
	char	*file;
	t_cub	cub;

	
	ft_initialize_s(&cub);
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
		//faire une fonction avec comme adresse (suite(&cub))
		// ->it direction of s_ray;
		// ->_disp_matrix(cub.map);
		// parsing_main((char *)argv[1], &cub);
		// init_map(cub);
		// print_sky_floor(&cub, &s_img);
		// loop n'est pas appele dans loop;
		//loop(10, &cub);
		cub.map.pos_x = cub.perso.x;
		cub.map.pos_y = cub.perso.y;
		// dprintf(2, "cub[][] = %c", cub.map.map[5][5]);
		// exit(EXIT_SUCCESS);
		
		// printf("entree cub_map = pos_y = %f pos_x = %f\n", cub.map.pos_y, cub.map.pos_x);
		// mlx_hook(cub.fen, 2, 1L<<0, keypad_hook, &cub);
		start_game(&cub);
		// mlx_loop_hook(cub.link, loop, &cub);
		// mlx_loop(cub.link);
		// mlx_hook(cub.fen, 2, 1L<<0, loop, &cub);
		// il y a mlx_loop_hook qui va looper toutes les fonctions; ->affichage, calcule du s_ray casting, etc.. tout dedans les touches dedans aussi;
		// mlx_hook(cub.fen, 3, 1L<<0, , &cub); // pitin;
		// mlx_key_hook(cub.fen, ft_print_movement, &struc);		// ICI
		// mlx_key_hook(cub.fen, &print_minimap, &cub);

		// t_point2D init;
		// t_point2D end;
		// init.x = 900;
		// init.y = 250;
		// end.x = 0;
		// end.y = 250;
		
		// cub.link = mlx_init();
		// cub.fen = mlx_new_window(cub.link, W_W, W_H, "cub3d");
		// cub.s_img.img = mlx_new_image(cub.link, W_W, W_H);
		// cub.s_img.addr = mlx_get_data_addr(cub.s_img.img, &cub.s_img.bits_per_pixel, &cub.s_img.line_length,
		// 					&cub.s_img.endian);
		
		// my_mlx_pixel_put(&cub.s_img, 50, 50, GREEN);
		// mlx_put_image_to_window(cub.link, cub.fen, cub.s_img.img, 0, 0);
		// mlx_loop(cub.link);

		// put_line(cub.link, cub.fen, init, end, 0x00FF00);
		//put_rectangle(cub.link, cub.fen, init, end, 0x0000FF);
	}
	
	return (argc);
}