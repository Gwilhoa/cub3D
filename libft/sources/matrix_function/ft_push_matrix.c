/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:55:05 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/04 11:58:36 by gchatain         ###   ########.fr       */
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
		tmp2 = malloc((sizeof(char *) * (ft_matrix_size((const char **) tmp) \
			+ 2)));
		tmp2[0] = ft_strdup(str);
		while (tmp[++i] != 0)
			tmp2[i + 1] = tmp[i];
		tmp2[i + 1] = 0;
	}
	*matrix = tmp2;
}
