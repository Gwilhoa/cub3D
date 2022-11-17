/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/17 19:42:54 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	my_close(t_cub *cub)
{
	(void) cub;
	exit(EXIT_SUCCESS);
	return (1);
}

int	keypad_press(int keycode, t_cub *cub)
{
	if (keycode == EVENT_ESC)
		my_close(cub);
	else if (keycode == EVENT_W)
	{
		cub->key.key_w = 1;
	}
	else if (keycode == EVENT_S)
	{
		cub->key.key_s = 1;
	}
	else if (keycode == EVENT_D)
	{
		cub->key.key_d = 1;
	}
	else if (keycode == EVENT_A)
	{
		cub->key.key_a = 1;
	}
	else if (keycode == EVENT_ROTR)
	{
		cub->key.rotr = 1;
	}
	else if (keycode == EVENT_ROTL)
	{
		cub->key.rotl = 1;
	}
	return (1);
}

int	keypad_release(int keycode, t_cub *cub)
{
	if (keycode == EVENT_W)
	{
		cub->key.key_w = 0;
	}
	else if (keycode == EVENT_S)
	{
		cub->key.key_s = 0;
	}
	else if (keycode == EVENT_ROTR)
	{
		cub->key.rotr = 0;
	}
	else if (keycode == EVENT_ROTL)
	{
		cub->key.rotl = 0;
	}
	else if (keycode == EVENT_D)
	{
		cub->key.key_d = 0;
	}
	else if (keycode == EVENT_A)
	{
		cub->key.key_a = 0;
	}
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
