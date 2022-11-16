/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:04:13 by guyar             #+#    #+#             */
/*   Updated: 2022/11/16 13:28:40 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void start_game(t_cub *cub)
{
	// ici, init la direction NSEW;
	mlx_hook(cub->fen, 2, 1L<<0, keypad_press, cub);
	mlx_hook(cub->fen, 3, 1L<<1, keypad_release, cub);
	// dprintf(2, "entree loop key = %d\n", cub->key.keyW);
	mlx_loop_hook(cub->link, loop, cub);
	mlx_loop(cub->link);
}