/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:10:09 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/15 17:32:18 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	map_badargument(char c)
{
	if (is_direction(c))
		ft_putstr_fd("Error\nPlayer already defined", 2);
	else
		ft_putstr_fd("Error\nUnrecognized charactere : ", 2);
	return (false);
}

int	parse_nameformat(void)
{
	ft_putstr_fd("Error\nWrong Fileformat, extension of file must be'.cub'", 2);
	return (false);
}

int	fd_unvailable(char	*filename)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd("does not exist or is not authorized to use this file", 2);
	return (false);
}

int	map_isopen(void)
{
	ft_putstr_fd("Error\nUndefined map : map is open", 2);
	return (false);
}

int	color_badargument(char type)
{
	ft_putstr_fd("error parsing color on ", 2);
	ft_putchar_fd(type, 2);
	ft_putchar_fd('\n', 2);
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
	return (false);
}
