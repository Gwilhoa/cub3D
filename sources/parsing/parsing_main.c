/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:50:24 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/04 10:03:10 by gchatain         ###   ########.fr       */
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
		return (1);
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
	while ()
	{
		
	}
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
}
