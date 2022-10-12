/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_back_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:15:18 by gchatain          #+#    #+#             */
/*   Updated: 2022/10/12 14:36:58 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_back_matrix(char ***matrix, char *str)
{
	char	**tmp;
	char	**tmp2;
	int		i;

	i = 0;
	tmp = *matrix;
	if (tmp == NULL)
	{
		ft_push_matrix(matrix, str);
		return ;
	}
	tmp2 = malloc(sizeof(char *) * (ft_matrix_size((const char **)tmp) + 2));
	while (tmp[i] != 0)
	{
		tmp2[i] = ft_strdup(tmp[i]);
		i++;
	}
	tmp2[i] = ft_strdup(str);
	tmp2[i + 1] = 0;
	ft_free_matrix(tmp);
	free(tmp);
	*matrix = tmp2;
}
