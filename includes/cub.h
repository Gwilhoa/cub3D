/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:07:35 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/08 14:48:32 by gchatain         ###   ########.fr       */
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
# define PI 3.14159265358979323846
# define EVENT_W 13	// c'etait 6 (why?) moi jai 13
# define EVENT_A 0
# define EVENT_S 1
# define EVENT_D 2
# define EVENT_SPACE 49
# define EVENT_ESC 53
# define EVENT_SHIFT 257
# define EVENT_ROTR 124
# define EVENT_ROTL 123
typedef struct s_ray
{
	double	posx;
	double	posy;
	double	raydirx;
	double	raydiry;
	double	planx;
	double	plany;
	double	dirx;
	double	diry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx; //length of ray from one x or y-side to next x or y-side
	double	deltadisty;
	int		stepx; //what direction to tep in x or y direction;
	int		stepy;
	int		hit;//is there a wall hit;
	int		side;	// was a NS or a EW wall hit;
	float perpwalldist;
	int lineheight;
	int		drawstart;
	int		drawend;
	int		x;
	float	speed;
	float	t_speed;	
	double	time;
	double	oldtime;
}	t_ray;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
}	t_point2D;

typedef struct s_texture_img
{
	t_data	data;
	int		width;
	int		heigth;
}	t_texture_img;

typedef struct s_texture
{
	t_texture_img		no_texture;
	t_texture_img		so_texture;
	t_texture_img		we_texture;
	t_texture_img		ea_texture;
	int					floor_color;
	int					ceiling_color;
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
	// direction;
}	t_perso;

typedef struct s_map
{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	long	f;
	long	c;
	int		height;
	int		width;
	double	pos_x;
	double	pos_y;
}			t_map;

typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
}			t_player;

typedef struct s_key
{
	int	key_w;
	int	key_s;
	int	rotr;
	int	rotl;

}	t_key;

typedef struct s_cub
{
	void		*link;
	void		*fen;
	void		*img;
	int			height;
	int			width;
	t_data		s_img;
	int			keybol;
	t_map		map;
	t_player	perso;
	t_ray		s_ray;
	t_key		key;
	double		time;
	double		oldtime;
	t_texture	texture;
}	t_cub;

int		game(t_cub *cub);
int		init_cub(t_cub *cub, int fd);
void	print_sky_floor(t_cub *cub, t_data *s_img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		print_minimap(int keycode, t_cub *cub);
int		init_cub(t_cub *cub, int fd);
int		parsing_main(char *filename, t_cub *cub);
int		parsing_fd(char *filename, t_cub *cub);
void	mm_putperso(t_data *s_img, float j, float i, int color);
void	mm_findperso(t_cub *cub);
// void	mm_printwall(t_cub *cub, t_data *s_img, int x, int y);
void	mm_wall(t_cub *cub, t_data *s_img, int x, int y);
void	mm_putsquare(t_data *s_img, int x, int y, int color);
void	mm_putmap(t_cub *cub, t_data *s_img);
int		next_mvmt(t_cub *cub, char c, int keycode);
int		loop(t_cub *s_cub);
void	calcule_ray(t_cub *cub);
void	calcul_step_sidedist(t_cub *s_cub);
void	do_dda(t_cub *s_cub);
void	raytodraw(t_cub *s_cub);
void	draw_line(t_cub *s_cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	initializ_ray(t_cub *s_cub);
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
// void	mm_putperso(t_data *s_img, float j, float i, int color);
void 	mm_findperso(t_cub *cub);
// void	mm_printwall(t_cub *cub, t_data *s_img, int x, int y);
// void	mm_wall(t_cub *cub, t_data *s_img, int x, int y);
// void	mm_putsquare(t_data *s_img, int x, int y, int color);
// void	mm_putmap(t_cub *cub, t_data *s_img);
// int		next_mvmt(t_cub *cub, char c, int keycode);
int	get_pixel(t_data data, int x, int y);
void	ft_dda(t_cub *s_cub);
void 	ft_initialize_s(t_cub *cub);
void	start_game(t_cub *cub);
void 	init_mlx(t_cub *cub);
int		keypad_press(int keycode, t_cub *cub);
int		keypad_release(int keycode, t_cub *cub);
int		ft_move(t_cub *cub);
void	init_display(t_cub *cub);
int		find_wall_pos(t_cub *cub);
int		get_textural_x(int wallx, t_texture_img img, t_cub *cub);

#endif