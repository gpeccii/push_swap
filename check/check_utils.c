/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:12:57 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/05 13:10:39 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int	ft_atol(const char *str)
{
	int			i;
	long int	sign;
	long int	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * sign);
}

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
