/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:07:35 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/17 21:58:35 by gchatain         ###   ########.fr       */
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
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	time;
	double	oldtime;
	float	speed;
	float	t_speed;
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

//--------conditions-----------//

/**
 * @param cub global instance
 * @category conditions
 * @brief if any texture value is set
 **/
int		is_textured(t_cub *cub);

/**
 * @param line char * to examinate 
 * @category conditions
 * @brief if any texture value is set
 **/
int		is_orientedline(char *line);

/**
 * @param c char to verify
 * @category conditions
 * @brief if the char is a direction
 **/
int		is_direction(char c);

//-----------parsing----------//

/**
 * @param filename map's path
 * @param cub global instance
 * @brief function to mange a program's parsing
 **/
int		parsing_main(char *filename, t_cub *cub);

/**
 * @param cub global instance
 * @param fd file descriptor of map
 * @brief setup map
 **/
int		init_map(t_cub *cub, int fd);

/**
 * @param cub global instance
 * @brief setup the textures
 **/
int		init_texture(t_cub *cub);

/**
 * @param cub global instance
 * @brief setup raycasting to default memory
 **/
void	init_ray(t_cub *cub);
/**
 * @param cub global instance
 * @brief setup raycasting to default memory
 **/
void	init_ray2(t_cub *cub);
void	init_minimap(t_cub *cub);
void	init_key(t_cub *cub);
/**
 * @param cub global instance
 * @brief setup screen to default memory
 **/
void	init_display(t_cub *cub);

/**
 * @param cub global instance
 * @brief launcher recursivity to a verify map
 **/
int		map_validation(t_cub *cub);
int		square_verify(int x, int y, char **map);

//------error------//

int		map_badargument(char c);
int		parse_nameformat(void);
int		parse_nameformat(void);
int		fd_unvailable(char	*filename);
int		map_isopen(void);
int		color_badargument(char type);
int		color_numberformat(char c);
int		color_unexpectedline(char *line);
int		empty_map(void);
int		corrupt_texture(char *path);
//--------------------//
int		search_player(t_cub *cub);
void	init_screen(t_cub *cub);
void	init_posplayer(t_cub *cub);
void	putminimap(t_cub *cub);
void	putperso(t_cub *cub);
void printminimap(t_cub *cub);
void    putsquare(t_data *s_img, int x, int y, int color);
//----------------//

int		game(t_cub *cub);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		print_minimap(int keycode, t_cub *cub);
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
int		parsing_fd(char *filename, t_cub *cub);
int		init_cub(t_cub *cub, int fd);
int		parsing_texture(t_cub *cub);
int		parsing_oriented(char *line, char *type, t_cub *cub);
void	setcub(t_cub *cub);
int		parsing_color(t_cub *cub, char *actual_line, char type);
int		rgb_to_hexa(int r, int g, int b);
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
int		get_pixel(t_data *data, int x, int y);
void	ft_dda(t_cub *s_cub);
void	start_game(t_cub *cub);
void 	init_mlx(t_cub *cub);
int		keypad_press(int keycode, t_cub *cub);
int		keypad_release(int keycode, t_cub *cub);
int		ft_move(t_cub *cub);
int		find_wall_pos(t_cub *cub);
int		get_textural_x(int wallx, t_img img, t_cub *cub);

#endif