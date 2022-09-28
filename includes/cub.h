/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:07:35 by gchatain          #+#    #+#             */
/*   Updated: 2022/09/28 18:41:11 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "mlx.h"
# include "libft.h"

typedef struct t_point3D
{
	float	x;
	float	y;
	float	z;
}	t_point3D;

typedef struct t_point2D
{
	int		x;
	int		y;
}	t_point2D;


typedef struct s_cub
{
	void	*link;
	void	*fen;
	int		width;
	int		height;
	char	**map;
}	t_cub;

int	parsing_main(char *filename, t_cub *cub);
int	parsing_fd(char *filename, t_cub *cub);
int	init_cub(t_cub *cub, int fd);
int		init_cub(t_cub *cub, int fd);
void	put_line(void *link, void *fen, t_point2D init, t_point2D end, int color);
void	put_rectangle(void *link, void *fen, t_point2D init, t_point2D end, int color);

#endif