/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_rectangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:32:40 by gchatain          #+#    #+#             */
/*   Updated: 2022/09/26 18:03:08 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_rectangle(void *link, void *fen,
			t_point2D init, t_point2D end, int color)
{
	t_point2D	tmp;
	t_point2D	tmp2;

	tmp.x = init.x;
	tmp.y = end.y;
	tmp2.x = end.x;
	tmp2.y = init.y;

	put_line(link, fen, init, tmp, color);
	put_line(link, fen, tmp, end, color);
	put_line(link, fen, end, tmp2, color);
	put_line(link, fen, tmp2, init, color);
}
