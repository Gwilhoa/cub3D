/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:47:44 by guyar             #+#    #+#             */
/*   Updated: 2022/11/15 13:25:02 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

// int print_minimap(int keycode, t_cub *cub)
// {
// 	s_mini minimap;
// 	int i; 
// 	int	j;
	
// 	mlx_clear_window(cub->link, cub->fen);
// 	minimap.img = mlx_new_image(cub->link, W_W, W_H);
// 	minimap.addr = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel, &minimap.line_length,
// 							&minimap.endian);
// 	while (y < 100)
// 	{
// 		while (x < W_W)
// 		{
// 			my_mlx_pixel_put(&cub->s_img, x, y, 0x00FFFFFF);
// 			x++;
// 		}
// 		x = MM_START_X;
// 		y++;
// 	}
// 	y = 0;
// 	x = MM_START_X + 20;
	
// 	i = 0;
// 	j = 0;

// 	x = MM_START_X + 20;
// 	y = 0;

// 	i = 0;
// 	i = 0;
// 	mm_putmap(cub, cub->s_img);
// 	printf("key == %d\n", keycode);
// 	if (keycode == 2)
// 	{
// 		printf("key == %d\n", keycode);
// 		next_mvmt(cub, 'x', keycode);
// 	}
// 	if (keycode == 0)
// 	{
// 		printf(" key == %d\n", keycode);
// 		next_mvmt(cub, 'x', keycode);
// 	}
// 	if (keycode == 13)
// 	{
// 		printf(" key == %d\n", keycode);
// 		next_mvmt(cub, 'y', keycode);
// 	}
// 	if (keycode == 1)
// 	{
// 		printf(" key == %d\n", keycode);
// 		next_mvmt(cub, 'y', keycode);
// 	}
// 	// printf("j = %f\n i = %f\n", cub->s_pos->j, cub->s_pos->i);
// 	mm_putperso(cub->s_img, cub->perso.pos.x, cub->perso.pos.y, 0x00009500);
// 	mlx_put_image_to_window(cub, cub->fen, cub->s_img->img, 0, 0);
// 	// printf("j = %f\n, i = %f\n", cub->s_pos->j, cub->s_pos->i);
// 	return (0);
// }

// void	mm_findperso(t_cub *cub)
// {
// 	// int	ii;
// 	// int	jj;

// 	// ii = 0;
// 	// jj = 0;
// 	// while (cub->map.map[ii])
// 	// {
// 	// 	while (cub->map.map[ii][jj])
// 	// 	{
// 	// 		if (cub->map.map[ii][jj] == 'P')
// 	// 		{
// 	// 			cub->perso.y = ii;
// 	// 			cub->perso.x = jj;
// 	// 			cub->map.map[ii][jj] = '0';
// 	// 		}
// 	// 		jj++;
// 	// 	}
// 	// 	jj = 0;
// 	// 	ii += 1; 
// 	// }
// 	(void)cub;
// 	return;
// }

// //  void mm_putmap(t_cub *cub, t_data *s_img)
// // {
// // 	int	i;
// // 	int	j;

// // 	j = 0;	
// // 	i = 0;
// // 	while (cub->map[i])
// // 	{
// // 		while (cub->map[i][j])
// // 		{
// // 			if (cub->map[i][j] == '1')
// // 				mm_putsquare(s_img, j, i, 0x00000000);
// // 			if (cub->map[i][j] == '0')
// // 				mm_putsquare(s_img, j, i, 0x00FFFFFF);	
// // 			j++;
// // 		}
// // 		j = 0;						// si x depasse la minimap, on arrete de print bruh;
// // 		i++;
// // 	}
// // }

// void	mm_putsquare(t_data *s_img, int x, int y, int color)
// {	
// 	int	tmpx;
// 	int	tmpy; 

// 	tmpx = 0;
// 	tmpy = 0;
// 	while (tmpy <= 10)
// 	{
// 		while (tmpx <= 10)
// 		{
// 			my_mlx_pixel_put(s_img, (x * 10) + tmpx, (y * 10) + tmpy, color);
// 			tmpx++;
// 		}
// 		tmpx = 0;
// 		tmpy++;
// 	}
// }



// void mm_putperso(t_data *s_img, float j, float i, int color)
// {	
// 	int tmpx;
// 	int tmpy; 

// 	tmpx = 0;
// 	tmpy = 0;

// 	while (tmpy <= 5)
// 	{
// 		 while (tmpx <= 5)
// 		{
// 			my_mlx_pixel_put(s_img, (j * 10) + tmpx, (i * 10) + tmpy, color);
// 			tmpx++;
// 		}
// 		tmpx = 0;
// 		tmpy++;
// 	}
// 	//mm_putsquare(s_img, j, i, color);
// 	// mm_putsquare(s_img, cub->s_pos->x, cub->s_pos->y, 0x00009500);
// }

// int	next_mvmt(t_cub *cub, char c, int keycode)
// {
// 	(void)c;
// 	int tmpi;
// 	int tmpj;
// 	// mlx_clear_window(cub->link, cub->fen);
// 	tmpi = floor(cub->perso.pos.y);
// 	tmpj = floor(cub->perso.pos.x);
// 		printf("keycode == %d\n", keycode);
// 	if (keycode == 2)
// 	{		
// 			tmpj = floor(cub->perso.pos.x + 0.5);
// 			tmpi = floor(cub->perso.pos.y);
// 		//	printf("char == %c\n", cub->map[tmpi][tmpj]);
// 			if (cub->map[tmpi][tmpj] != '1')
// 				cub->perso.pos.x += 0.5;
// 		//	{
// 				// cub->s_pos->j += cub->s_pos->pdx;
// 				// cub->s_pos->i += cub->s_pos->pdy;
// 		//	}
// 	}
// 	else if ( keycode == 0)
// 	{
// 		//tmpj = floor(cub->s_pos->j - 0.50);
// 		//tmpi = floor(cub->s_pos->i);
// 		//printf("char == %c\n", cub->map[tmpi][tmpj]);
// 		if (cub->map[tmpi][tmpj] != '1')
// 		{
// 			cub->perso.pos.x -= 0.50;
// 			// cub->s_pos->j += cub->s_pos->pdx;
// 			// cub->s_pos->i += cub->s_pos->pdy;
// 		}
// 	}
// 	else if (keycode == 13)
// 	{
// 		tmpj = floor(cub->perso.pos.x);
// 		tmpi = floor(cub->perso.pos.y - 0.50);
// 	// //	printf("char == %c\n", cub->map[tmpi][tmpj]);
// 		if (cub->map[tmpi][tmpj] != '1')
// 		cub->perso.pos.x -= 0.50;
		
// 		// cub->s_pos->j += cub->s_pos->pdx;
// 		// cub->s_pos->i += cub->s_pos->pdy;
 
// 	}
// 	else if (keycode == 1)
// 	{
// 		tmpj = floor(cub->perso.pos.x);
// 		tmpi = floor(cub->perso.pos.y + 0.50);
// 	//	printf("char == %c\n", cub->map[tmpi][tmpj]);
// 		if (cub->map[tmpi][tmpj] != '1')
// 			cub->perso.pos.y += 0.5;
// 		// cub->s_pos->j += cub->s_pos->pdx;
// 		// cub->s_pos->i += cub->s_pos->pdy;
// 	}
// 	// else if (keycode == 123)
// 	// {
// 	// 	cub->s_pos->pa -= 0.1; if(cub->s_pos->pa < 0) {cub->s_pos->pa += 2 * PI;} cub->s_pos->pdx= cos(cub->s_pos->pa)* 5; cub->s_pos->pdy= sin(cub->s_pos->pa)*5; 
// 	// }
// 	// else if (keycode == 124)
// 	// {
// 	// 	cub->s_pos->pa += 0.1; if (cub->s_pos->pa > 2 *PI) { cub->s_pos->pa -= 2 * PI;} cub->s_pos->pdx= cos(cub->s_pos->pa)* 5; cub->s_pos->pdy= sin(cub->s_pos->pa)*5;
// 	// }
// 	return(0);
// }

// int next_ij(t_cub *cub, char c, int i)
// {
// 	int tmp;
// 	int i;
// 	// tmp = (i + 2) -10 - 
// }