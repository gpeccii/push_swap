/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:12:57 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/04 14:13:36 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup_mine(int *check, int k, int i)
{
	int	j;

	while (k < (i - 1))
	{
		j = k + 1;
		while (j < i)
		{
			if (check[k] == check[j])
			{
				free(check);
				return (0);
			}
			j++;
		}
		k++;
	}
	free(check);
	return (1);
}

void	free_matrix(char **matrix)
{
	int	k;

	k = -1;
	while (matrix[++k])
		free(matrix[k]);
	free(matrix);
}
