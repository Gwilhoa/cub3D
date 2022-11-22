/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:50:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/22 20:39:08 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parsing_main(char *filename, t_cub *cub)
{
	int	fd;

	if (ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
		return (parse_nameformat());
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (fd_unvailable(filename));
	init_mlx(cub);
	cub->perso.pos.x = -1;
	if (init_map(cub, fd) == false || init_texture(cub) == false
		|| search_player(cub) == false)
		return (false);
	close(fd);
	init_minimap(cub);
	init_ray(cub);
	init_display(cub);
	init_key(cub);
	return (true);
}

int	parsing_texture(t_cub *cub)
{
	char	*al;
	int		i;

	i = true;
	while (is_textured(cub))
	{
		al = ft_strtrim(cub->map.map[0], " \n\t\v\r\f");
		if (!al)
			return (false);
		if (is_orientedline(al))
			i = parsing_oriented(al + 2, ft_substr(al, 0, 2), cub);
		else if (ft_strncmp(al, "F", 1) == 0 || ft_strncmp(al, "C", 1) == 0)
			i = parsing_color(cub, ft_strtrim(al + 1, " "), al[0]);
		else if (ft_strlen(cub->map.map[0]) > 1)
			return (color_unexpectedline(cub->map.map[0]));
		free(al);
		free(cub->map.map[0]);
		cub->map.map = cub->map.map + 1;
	}
	while (cub->map.map[0] != 0 && ft_strlen(cub->map.map[0]) <= 1)
	{
		free(cub->map.map[0]);
		cub->map.map = cub->map.map + 1;
	}
	return (i);
}

int	create_textures(t_cub *d, t_img *tex, char *path)
{
	tex->data.img = mlx_xpm_file_to_image
		(d->link, path, &tex->width, &tex->heigth);
	if (!tex->data.img)
		return (corrupt_texture(path));
	tex->data.addr = mlx_get_data_addr
		(tex->data.img, &tex->data.bits_per_pixel, &tex->data.line_length, \
	&tex->data.endian);
	tex->size = tex->data.bits_per_pixel
		* tex->data.line_length * tex->data.endian;
	return (true);
}

int	parsing_oriented(char *line, char *type, t_cub *cub)
{
	char	*path;
	int		r;

	r = true;
	path = ft_strtrim(line, " \n\t\v\r\f");
	if (path == NULL)
		return (false);
	if (ft_strcmp(type, "NO") == 0 && cub->texture.no_texture.data.img == NULL)
		r = create_textures(cub, &cub->texture.no_texture, path);
	else if (ft_strcmp(type, "SO") == 0
		&& cub->texture.so_texture.data.img == NULL)
		r = create_textures(cub, &cub->texture.so_texture, path);
	else if (ft_strcmp(type, "WE") == 0
		&& cub->texture.we_texture.data.img == NULL)
		r = create_textures(cub, &cub->texture.we_texture, path);
	else if (ft_strcmp(type, "EA") == 0
		&& cub->texture.ea_texture.data.img == NULL)
		r = create_textures(cub, &cub->texture.ea_texture, path);
	else
		r = false;
	free(type);
	free(path);
	return (r);
}

int	search_player(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.map[i] != 0)
	{
		j = 0;
		while (cub->map.map[i][j] != 0)
		{
			if (is_direction(cub->map.map[i][j]) && cub->perso.pos.x == -1)
			{
				cub->perso.direction = cub->map.map[i][j];
				cub->perso.pos.y = i + 0.5;
				cub->perso.pos.x = j + 0.5;
			}
			else if (is_direction(cub->map.map[i][j]) || (cub->map.map[i][j]
			!= '0' && cub->map.map[i][j] != '1' && cub->map.map[i][j] != ' '))
				return (map_badargument(cub->map.map[i][j]));
			j++;
		}
		i++;
	}
	if (map_validation(cub) == false)
		return (map_isopen());
	return (true);
}
