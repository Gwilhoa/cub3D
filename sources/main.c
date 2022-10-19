/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/19 15:21:37 by guyar            ###   ########.fr       */
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
	t_cub	*cub;
	t_map	*map;
	t_player *perso;
	
	cub = malloc(sizeof(cub));
	cub->perso = &perso;
	cub->map = &map;
	if (argc != 2)
	{
		ft_putstr_fd("Error\ntoo few or not enough argument", 2);
		exit(1);
	}
	file = ft_strdup(argv[1]);
	if (!file || parsing_main(file, cub) == 1)
	{
		exit(1);
	}
	else
	{
		exit()
		cub->link = mlx_init();
		cub->height = W_H;
		cub->width = W_W;
		cub->s_img = malloc(sizeof(t_data));
		cub->s_ray = malloc(sizeof(t_ray));
		// init direction of ray;
		cub->s_ray->dirx = -1; 
		cub->s_ray->diry = 0;
		cub->s_ray->planx = 0;
		cub->s_ray->plany = 0.66;
		cub->time = 0;
		cub->oldtime = 0;
		printf("map pos_y = %d\n map pos_x = %d\n", cub->perso->y, cub->perso->x);
		cub->map->pos_x = cub->perso->y + 0.2;
		cub->map->pos_y = cub->perso->x + 0.2;
		// printf("pos_y = %d\npos_x = %d\n", cub.perso->y, cub.perso->x);
			

		// ._disp_matrix(cub.map);
		cub->fen = mlx_new_window(cub->link, W_W, W_H, "cub3d");
		// parsing_main((char *)argv[1], &cub);
		// init_map(cub);
		// print_sky_floor(&cub, &s_img);
		mlx_loop_hook(cub->link, loop, cub);
		// mlx_hook(cub.fen, 2, 1L<<0, loop, &cub);
		// il y a mlx_loop_hook qui va looper toutes les fonctions; ->affichage, calcule du ray casting, etc.. tout dedans les touches dedans aussi;
		// mlx_hook(cub.fen, 3, 1L<<0, , &cub); // pitin;
		// mlx_hook(cub.fen, 2, 1L<<0, print_minimap, &cub);
		// mlx_key_hook(cub.fen, ft_print_movement, &struc);		// ICI
		// mlx_key_hook(cub.fen, &print_minimap, &cub);
		mlx_loop(cub->link);
		exit(EXIT_SUCCESS);

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
