/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:32:19 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/24 10:24:20 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	corrupt_texture(char *path)
{
	ft_putstr_fd("Error\nTexture File\n", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(" Corrupted or non-existent\n", 2);
	exit(1);
	return (false);
}

int	color_numberformat(char c)
{
	ft_putstr_fd("error number format exception '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("' is not a number\n", 2);
	return (false);
}

int	color_unexpectedline(char *line)
{
	ft_putstr_fd("Error\nunexpected line in the map : ", 2);
	ft_putstr_fd(line, 2);
	ft_putchar_fd('\n', 2);
	return (false);
}

int	empty_map(void)
{
	ft_putstr_fd("Error\nEmpty file or directory file\n", 2);
	return (false);
}

int	size_map(char **map)
{
	if (ft_matrix_size((const char **) map) > 3)
		return (true);
	ft_putstr_fd("Error\nMap too small\n", 2);
	return (false);
}
