/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:48:27 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/23 17:12:29 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_moves_zero(int i, int size1, int last_index_to, int *from, int *to)
{
	int	j;

	j = -1;
	while (to[++j] < (last_index_to / 2))
	{
		if (from[i] > to[j])
		{
			if (i <= j)
				return (i + (j - i) + 1);
			else if (i > j)
				return (j + (i - j) + 1);
		}
	}
	return (count_moves_last(i, size1, last_index_to, from, to));
}

int	count_moves_last(int i, int size1, int last_index_to, int *from, int *to)
{
	int	j;

	j = last_index_to + 1;
	while (to[--j] >= (last_index_to / 2))
	{
		if (from[i] < to[j])
		{
			if (i >= j)
				return ((size1 - i) - (j - last_index_to) + 1);
			else if (i < j)
				return ((j - last_index_to) - (size1 - i) + 1);
		}
	}
	return (2);
}
int	cheapest_move(t_stack *stack)
{
	int	i;
	int	j;
	int	n;
	int	ret;

	i = -1;
	j = stack->current_a + 1;
	ret = 5500;
	while(++i < (stack->current_a / 2))
	{
		n = count_moves_zero(i, stack->current_a, stack->current_b, stack->a, stack->b);
		if (n < ret)
			ret = n;
	}
	while (--j >= (stack->current_a / 2))
	{
		n = count_moves_last(j, stack->current_a, stack->current_b, stack->a, stack->b);
		if (n < ret)
			ret = n;
	}
	return (ret);
}
