/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:07:35 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/12 14:25:25 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# define W_H 650
# define W_W 1000
# define MM_START_X 0 
# define MM_START_Y 0
# define MM_END_X 1000
# define MM_END_Y 100
# define PI 3.1415926535

typedef struct t_point3D
{
	float	x;
	float	y;
	float	z;
}	t_point3D;

typedef struct t_point2D
{
	float		x;
	float		y;
	float		i;
	float		j;
	double		dirx;
	double		diry;
	double		planx; 
	double		plany;
}	t_point2D;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_texture
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			floor_color;
	int			ceiling_color;
}	t_texture;

typedef struct t_perso
{
	t_point2D	pos;
	float		i;
	float		j;
	double		dirx;
	double 		diry;
	double		planx; 
	double		plany;
}	t_perso;

typedef struct m_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	s_mini;

typedef struct s_cub
{
	void		*link;
	void		*fen;
	int			width;
	int			height;
	char		**map;
	void		*img;
	int			keybol;
	t_perso		perso;
	t_data		*s_img;
	double		time;
	double		oldtime;
	t_texture	texture;
}	t_cub;

int		is_textured(t_cub *cub);
int		is_orientedline(char *line);
int		parsing_main(char *filename, t_cub *cub);
int		parsing_fd(char *filename, t_cub *cub);
int		init_cub(t_cub *cub, int fd);
int		parsing_texture(t_cub *cub);
int		parsing_oriented(char *line, char *type, t_cub *cub);
void	setcub(t_cub *cub);
int		parsing_color(t_cub *cub, char *actual_line, char type);
int		rgb_to_hexa(int r, int g, int b);
int		ft_search_player(t_cub *cub);
int		init_cub(t_cub *cub, int fd);
void	put_line(void *link, void *fen, t_point2D init, t_point2D end, int color);
void	put_rectangle(void *link, void *fen, t_point2D init, t_point2D end, int color);
void	print_sky_floor(t_cub *cub, t_data *s_img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 	print_minimap(int keycode, t_cub *cub);
int		parsing_main(char *filename, t_cub *cub);
int		parsing_fd(char *filename, t_cub *cub);
void	mm_putperso(t_data *s_img, float j, float i, int color);
void 	mm_findperso(t_cub *cub);
// void	mm_printwall(t_cub *cub, t_data *s_img, int x, int y);
void	mm_wall(t_cub *cub, t_data *s_img, int x, int y);
void	mm_putsquare(t_data *s_img, int x, int y, int color);
void	mm_putmap(t_cub *cub, t_data *s_img);
int		next_mvmt(t_cub *cub, char c, int keycode);
#endif