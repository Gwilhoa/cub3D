/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:47:44 by guyar             #+#    #+#             */
/*   Updated: 2022/11/17 22:02:11 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

void putminimap(t_cub *cub)
{
    // initminimap(cub);
    printminimap(cub);
    putperso(cub);
    //put img to window;
    // mlx_put_image_to_window(cub->link, cub->fen, cub->mini.img, 0, 0);
}

void putperso(t_cub *cub)
{
    printf("pos x = %d\npos y = %d", (int)cub->map.pos_x, (int)cub->map.pos_y);
    putsquare(&cub->s_img, cub->map.pos_y, cub->map.pos_x, 0x000C200);
}

void printminimap(t_cub *cub)
{
    int    i;
    int    j;

    j = 0;    
    i = 0;
    while (cub->map.map[i])
    {
        while (cub->map.map[i][j])
        {
            if (cub->map.map[i][j] == '1')
                putsquare(&cub->s_img, j, i, 0x00000000);
            if (cub->map.map[i][j] == '0')
                putsquare(&cub->s_img, j, i, cub->texture.floor_color);    
            j++;
        }
        j = 0;                        // si x depasse la minimap, on arrete de print bruh;
        i++;
    }
}

void    putsquare(t_data *s_img, int x, int y, int color)
{    
    int    tmpx;
    int    tmpy; 

    tmpx = 0;
    tmpy = 0;
    while (tmpy <= 10)
    {
        while (tmpx <= 10)
        {
            my_mlx_pixel_put(s_img, (x * 10) + tmpx, (y * 10) + tmpy, color);
            tmpx++;
        }
        tmpx = 0;
        tmpy++;
    }
}