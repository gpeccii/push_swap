/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:48:27 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 17:28:14 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_index_max_b(t_stack *stack)
{
	int	i;
	int	imax;
	int	max;

	i = 0;
	max = stack->b[0];
	imax = 0;
	while (i <= stack->last_b)
	{
		if (stack->b[i] > max)
		{
			max = stack->b[i];
			imax = i;
		}
		i++;
	}
	return (imax);
}

int	find_index_min_b(t_stack *stack)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	min = stack->b[0];
	index = 0;
	while (i <= stack->last_b)
	{
		if (stack->b[i] < min)
		{
			min = stack->b[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	count_moves(int i, t_stack *stack)
{
	int	j;
	int	min;
	int	max;

	j = 0;
	min = find_index_min_b(stack);
	max = find_index_max_b(stack);
	if (stack->a[i] > stack->b[max])
		return (max_to_insert(stack, i, j, max));
	else if (stack->a[i] < stack->b[min])
		return (min_to_insert(stack, i, j, min));
	else
		return (middle_insert(stack, i, j));
	return (500);
}

int	cheapest_move(t_stack *stack)
{
	int	i;
	int	n;
	int	ret;

	i = 0;
	ret = count_moves(0, stack);
	stack->index_min = 0;
	while (i <= stack->last_a)
	{
		n = count_moves(i, stack);
		if (n < ret)
		{
			stack->index_min = i;
			ret = n;
		}
		i++;
	}
	return (ret);
}
