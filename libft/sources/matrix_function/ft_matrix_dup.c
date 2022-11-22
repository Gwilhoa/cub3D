/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchatain <gchatain@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:53:59 by gchatain          #+#    #+#             */
/*   Updated: 2022/11/22 20:04:28 by gchatain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrix_dup(char **matrix)
{
	char	**new;
	int		i;

	new = malloc((ft_matrix_size((const char **)matrix) + 1) * sizeof(char *));
	i = 0;
	while (matrix[i] != 0)
	{
		new[i] = ft_strdup(matrix[i]);
		if (new[i] == 0)
			return (0);
		i++;
	}
	new[i] = 0;
	return (new);
}
