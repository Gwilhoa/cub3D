/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:55:05 by gchatain          #+#    #+#             */
/*   Updated: 2022/09/29 16:32:56 by gchatain         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_matrix(char ***matrix, char *str)
{
	char	**tmp;
	char	**tmp2;
	int		i;

	i = -1;
	tmp = *matrix;
	if (tmp == 0)
	{
		tmp2 = malloc(sizeof(char *) * 2);
		tmp2[0] = ft_strdup(str);
		tmp2[1] = 0;
	}
	else
	{
		i = ft_matrix_size((const char **) tmp);
		tmp2 = malloc((sizeof(char *) * (i + 2)));
		tmp2[0] = str;
		i = -1;
		while (tmp[++i] != 0)
			tmp2[i + 1] = ft_strdup(tmp[i]);
		tmp2[i + 1] = 0;
		ft_free_matrix(tmp);
		free(tmp);
	}
	*matrix = tmp2;
}
