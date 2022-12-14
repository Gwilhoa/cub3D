/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:07:35 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/28 22:53:32 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# define W_H 800
# define W_W 1200
# define MM_START_X 0 
# define MM_START_Y 0
# define MM_END_X 1000
# define MM_END_Y 100
# define PI 3.14159265358979323846
# define EVENT_W 13
# define EVENT_A 0
# define EVENT_S 1
# define EVENT_D 2
# define EVENT_SPACE 49
# define EVENT_ESC 53
# define EVENT_SHIFT 257
# define EVENT_ROTR 124
# define EVENT_ROTL 123
# define EVENT_M 46

typedef struct s_ray
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planx;
	double	plany;
	double	camerax;
	double	dirx_dist;
	double	diry_dist;
	double	deltadistx;
	double	deltadisty;
	double	time;
	double	oldtime;
	float	speed;
	float	perpwalldist;
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		x;
}	t_ray;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct t_point2D
{
	float		x;
	float		y;
}	t_point2D;

typedef struct s_img
{
	t_data	data;
	int		size;
	int		width;
	int		heigth;
}	t_img;

typedef struct s_texture
{
	t_img	no_texture;
	t_img	so_texture;
	t_img	we_texture;
	t_img	ea_texture;
	int		floor_color;
	int		ceiling_color;
}	t_texture;

typedef struct s_player
{
	t_point2D	pos;
	float		i;
	float		j;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	char		direction;
}	t_player;

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

typedef struct s_key
{
	int	key_w;
	int	key_s;
	int	rotr;
	int	rotl;
	int	key_a;
	int	key_d;
	int	key_m;
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
	t_ray		ray;
	t_key		key;
	double		time;
	double		oldtime;
	t_texture	texture;
}	t_cub;

int		color_badargument(char type);
int		size_map(char **map);
int		is_textured(t_cub *cub);
int		is_orientedline(char *line);
int		is_direction(char c);
int		parsing_main(char *filename, t_cub *cub);
int		init_map(t_cub *cub, int fd);
void	map_validation(t_cub *cub);
void	square_verify(int x, int y, char **map);
int		map_badargument(char c);
int		parse_nameformat(void);
int		parse_nameformat(void);
int		fd_unvailable(char	*filename);
int		map_isopen(void);
int		isvalid_color(char *color, char type);
int		color_numberformat(char c);
int		color_unexpectedline(char *line, char *al);
int		empty_map(void);
int		corrupt_texture(char *path);
int		game(t_cub *cub);
int		print_minimap(int keycode, t_cub *cub);
int		parsing_main(char *filename, t_cub *cub);
int		parsing_fd(char *filename, t_cub *cub);
int		next_mvmt(t_cub *cub, char c, int keycode);
int		parsing_fd(char *filename, t_cub *cub);
int		init_cub(t_cub *cub, int fd);
int		parsing_texture(t_cub *cub);
int		parsing_oriented(char *line, char *type, t_cub *cub);
int		parsing_color(t_cub *cub, char *actual_line, char type);
int		rgb_to_hexa(int r, int g, int b);
int		init_cub(t_cub *cub, int fd);
int		print_minimap(int keycode, t_cub *cub);
int		parsing_main(char *filename, t_cub *cub);
int		keypad_press(int keycode, t_cub *cub);
int		keypad_release(int keycode, t_cub *cub);
int		ft_move(t_cub *cub);
int		find_wall_pos(t_cub *cub);
int		get_textural_x(int wallx, t_img img, t_cub *cub);
int		my_close(t_cub *cub);
int		get_pixel(t_data *data, int x, int y);
int		loop(t_cub *s_cub);
int		search_player(t_cub *cub);
int		init_texture(t_cub *cub);
void	init_ray(t_cub *cub);
void	init_ray2(t_cub *cub);
void	init_minimap(t_cub *cub);
void	init_key(t_cub *cub);
void	init_display(t_cub *cub);
void	init_screen(t_cub *cub);
void	init_posplayer(t_cub *cub);
void	putminimap(t_cub *cub);
void	putperso(t_cub *cub);
void	printminimap(t_cub *cub);
void	putsquare(t_data *s_img, int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	calcule_ray(t_cub *cub);
void	calcul_step_sidedist(t_cub *s_cub);
void	do_dda(t_cub *s_cub);
void	raytodraw(t_cub *s_cub);
void	draw_line(t_cub *s_cub);
void	setcub(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_dda(t_cub *cub);
void	start_game(t_cub *cub);
void	init_mlx(t_cub *cub);
void	ray_manager(t_cub *cub);
void	draw_wall(t_cub *cub);
void	movement_key(t_cub *cub);
void	rotate_key(double tmpdirx, double tmpplnx, t_cub *cub);
void	key_hook_w(t_cub *cub);
void	key_hook_a(t_cub *cub);
void	key_hook_s(t_cub *cub);
void	key_hook_d(t_cub *cub);
void	draw_line(t_cub *cub);
double	get_wallx(t_cub *cub);
t_img	getside_img(t_cub *cub);

#endif