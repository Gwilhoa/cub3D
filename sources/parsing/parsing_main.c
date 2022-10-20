/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:50:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/20 11:56:25 by gchatain         ###   ########.fr       */
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
		if (is_orientedline(al))
			i = parsing_oriented(al + 2, ft_substr(al, 0, 2), cub);
		else if (ft_strncmp(al, "F", 1) == 0 || ft_strncmp(al, "C", 1) == 0)
			i = parsing_color(cub, al + 1, al[0]);
		else if (ft_strlen(cub->map.map[0]) > 1)
		{
			ft_putstr_fd("Error\nunexpected line in the map", 2);
			return (1);
		}
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

int	parsing_oriented(char *line, char *type, t_cub *cub)
{
	char	*path;
	int		fd;

	path = ft_strtrim(line, " \n\t\v\r\f");
	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		ft_putstr_fd("Error\nno such file or permission denied of ", 2);
		ft_putstr_fd(path, 2);
		return (1);
	}
	close(fd);
	if (ft_strcmp(type, "NO") == 0 && cub->texture.no_texture == NULL)
		cub->texture.no_texture = path;
	else if (ft_strcmp(type, "SO") == 0 && cub->texture.so_texture == NULL)
		cub->texture.so_texture = path;
	else if (ft_strcmp(type, "WE") == 0 && cub->texture.we_texture == NULL)
		cub->texture.we_texture = path;
	else if (ft_strcmp(type, "EA") == 0 && cub->texture.ea_texture == NULL)
		cub->texture.ea_texture = path;
	else
		return (1);
	return (0);
}
