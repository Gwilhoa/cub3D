/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:06:33 by gchatain          #+#    #+#             */
/*   Updated: 2022/08/20 19:02:59 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int argc, char const *argv[])
{
	const char	*file;
	int			fd;
	t_cub		cub;

	file = argv[1];
	fd = open(file, O_RDONLY);
	if (!file || ft_memcmp(file + ft_strlen(file) - 4, ".cub", 4))
	{
		ft_putstr_fd("Error\nfile error", 2);
	}
	else if (fd < 1) 
		ft_putstr_fd("Error\nopen file", 2);
	else 
	{
		if (init_cub(&cub, fd) == -1)
			return (-1);
		cub.link = mlx_init();
		cub.height = 500;
		cub.width = 900;
		cub.fen = mlx_new_window(cub.link, cub.width, cub.height, "cub3d");
		t_point2D init;
		t_point2D end;
		init.x = 900;
		init.y = 250;
		end.x = 0;
		end.y = 250;
		put_line(cub.link, cub.fen, init, end, 0x00FF00);
		//put_rectangle(cub.link, cub.fen, init, end, 0x0000FF);
		mlx_loop(cub.link);
	}
	return (argc);
}

int	init_cub(t_cub *cub, int fd)
{
	char	*str;

	cub->map = malloc(sizeof(char *) * 2);
	str = get_next_line(fd);
	while (str != 0)
	{
		ft_push_matrix(&cub->map, str);
		str = get_next_line(fd);
	}
	return (0);
}
