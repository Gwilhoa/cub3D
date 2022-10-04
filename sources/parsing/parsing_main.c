/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:50:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/04 17:03:33 by gchatain         ###   ########.fr       */
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
		("[cub] wrong Fileformat, extension of file must be'.cub'", 2);
		return (1);
	}
	if (parsing_fd(filename, cub) == 1)
		return (1);
	if (parsing_texture(cub) == 1)
	{
		ft_putstr_fd("incorrect file format\n", 2);
		return (1);
	}
	return (0);
}

int	parsing_fd(char *filename, t_cub *cub)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("no such file or you don't have permission to do this", 2);
		return (1);
	}
	init_cub(cub, fd);
	close(fd);
	return (0);
}

int	init_cub(t_cub *cub, int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str != 0)
	{
		ft_push_back_matrix(&cub->map, str);
		str = get_next_line(fd);
	}
	return (0);
}

int	parsing_texture(t_cub *cub)
{
	char	*actual_line;

	while (istextured(cub))
	{
		actual_line = ft_strtrim(cub->map[0], " \n");
		if (actual_line == 0)
		{
			free(cub->map[0]);
			cub->map = cub->map + 1;
		}
		else
		{
			if (ft_strncmp(actual_line, "NO", 2) == 0)
				cub->no_texture = ft_strtrim(actual_line + 2, " ");
			else if (ft_strncmp(actual_line, "SO", 2) == 0)
				cub->so_texture = ft_strtrim(actual_line + 2, " ");
			else if (ft_strncmp(actual_line, "WE", 2) == 0)
				cub->we_texture = ft_strtrim(actual_line + 2, " ");
			else if (ft_strncmp(actual_line, "EA", 2) == 0)
				cub->ea_texture = ft_strtrim(actual_line + 2, " ");
			else if (ft_strncmp(actual_line, "F", 1) == 0 || ft_strncmp(actual_line, "C", 1) == 0)
			{
				if (parsing_color(cub, actual_line + 1, actual_line[0]) == 1)
					return (1);
			}
			cub->map = cub->map + 1;
			if (cub->map[0] == 0)
				return (1);
		}
	}
	return (0);
}

void	setcub(t_cub *cub)
{
	cub->map = NULL;
	cub->no_texture = NULL;
	cub->so_texture = 0;
	cub->we_texture = 0;
	cub->ea_texture = 0;
	cub->ceiling_color = -1;
	cub->floor_color = -1;
	return ;
}

int	istextured(t_cub *cub)
{
	if (cub->no_texture == 0)
		return (1);
	if (cub->so_texture == 0)
		return (1);
	if (cub->we_texture == 0)
		return (1);
	if (cub->ea_texture == 0)
		return (1);
	if (cub->ceiling_color == -1)
		return (1);
	if (cub->floor_color == -1)
		return (1);
	return (0);
}
