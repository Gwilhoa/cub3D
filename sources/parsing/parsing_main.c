/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guyar <guyar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:50:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/12 21:07:23 by guyar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * return 0 ok
 * return 1 error parsing
 **/

int	parsing_main(char *filename, t_cub *cub)
{
	setcub(cub);
	if (filename == NULL)
		return (1);
	if (ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
	{
		ft_putstr_fd
		("Error\nwrong Fileformat, extension of file must be'.cub'", 2);
		return (1);
	}
	if (parsing_fd(filename, cub) == 1 || parsing_texture
		(cub) == 1 || ft_search_player(cub) == 1)
		return (1);
	return (0);
}

int	parsing_fd(char *filename, t_cub *cub)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd
		("Error\nno such file or you don't have permission to do this", 2);
		return (1);
	}
	init_cub(cub, fd);
	close(fd);
	return (0);
}

int	parsing_texture(t_cub *cub)
{
	char	*al;
	int		i;

	i = 0;
	while (is_textured(cub))
	{
		al = ft_strtrim(cub->map.map[0], " \n\t\v\r\f");
		ft_printf("al = %s\n", al);
		if (is_orientedline(al))
			i = parsing_oriented(al + 2, ft_substr(al, 0, 2), cub);
		else if (ft_strncmp(al, "F", 1) == 0 || ft_strncmp(al, "C", 1) == 0)
			i = parsing_color(cub, ft_strtrim(al + 1, " "), al[0]);
		else if (ft_strlen(cub->map.map[0]) > 1)
		{
			ft_putstr_fd("Error\nunexpected line in the map", 2);
			return (1);
		}
		free(al);
		free(cub->map.map[0]);
		cub->map.map = cub->map.map + 1;
		if (cub->map.map[0] == 0 || i == 1)
			return (1);
	}
	i = 0;
	while (ft_strlen(cub->map.map[0]) <= 1)
	{
		free(cub->map.map[0]);
		cub->map.map = cub->map.map + 1;
	}
	return (0);
}

void	create_textures(t_cub *d, t_texture_img *tex, char *path)
{
	tex->data.img = mlx_xpm_file_to_image(d->link, path, &tex->width, &tex->heigth);
	if (!tex->data.img)
		return ;
	tex->data.addr = mlx_get_data_addr(tex->data.img, &tex->data.bits_per_pixel, &tex->data.line_length, \
	&tex->data.endian);
	tex->size = tex->data.bits_per_pixel * tex->data.line_length * tex->data.endian;
}

int	parsing_oriented(char *line, char *type, t_cub *cub)
{
	char	*path;
	// void	*img;
	int		fd;
	// int		w;
	// int		h;

	path = ft_strtrim(line, " \n\t\v\r\f");
	dprintf(2, "path = %s\n", path);
	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		ft_putstr_fd("Error\nno such file or permission denied of ", 2);
		ft_putstr_fd(path, 2);
		return (1);
	}
	close(fd);
	// img = mlx_xpm_file_to_image(cub->link, path, &h, &w);
	if (ft_strcmp(type, "NO") == 0 && cub->texture.no_texture.data.img == NULL)
	{
		create_textures(cub, &cub->texture.no_texture, path);
		//cub->texture.no_text = mlx_get_data_addr(img, &cub->s_img.bits_per_pixel, &cub->s_img.line_length, &cub->s_img.endian);
		// cub->texture.no_texture.data.addr = mlx_get_data_addr(img, &cub->texture.no_texture.data.bits_per_pixel, &cub->texture.no_texture.data.line_length, &cub->texture.no_texture.data.endian);
		// cub->texture.no_texture.heigth = h;
		// cub->texture.no_texture.width = w;
	}
	else if (ft_strcmp(type, "SO") == 0 && cub->texture.so_texture.data.img == NULL)
	{
		create_textures(cub, &cub->texture.so_texture, path);
		// cub->texture.so_texture.data.addr = mlx_get_data_addr(img, &cub->texture.so_texture.data.bits_per_pixel, &cub->texture.so_texture.data.line_length, &cub->texture.so_texture.data.endian);
		// cub->texture.so_texture.heigth = h;
		// cub->texture.so_texture.width = w;
	}
	else if (ft_strcmp(type, "WE") == 0 && cub->texture.we_texture.data.img == NULL)
	{
		create_textures(cub, &cub->texture.we_texture, path);
		// cub->texture.we_texture.data.addr = mlx_get_data_addr(img, &cub->texture.we_texture.data.bits_per_pixel, &cub->texture.we_texture.data.line_length, &cub->texture.we_texture.data.endian);
		// cub->texture.we_texture.heigth = h;
		// cub->texture.we_texture.width = w;
	}
	else if (ft_strcmp(type, "EA") == 0 && cub->texture.ea_texture.data.img == NULL)
	{
		create_textures(cub, &cub->texture.ea_texture, path);
		// cub->texture.ea_texture.data.addr = mlx_get_data_addr(img, &cub->texture.ea_texture.data.bits_per_pixel, &cub->texture.ea_texture.data.line_length, &cub->texture.ea_texture.data.endian);
		// cub->texture.ea_texture.heigth = h;
		// cub->texture.ea_texture.width = w;
	}
	else
		return (1);
	free(type);
	return (0);
}
