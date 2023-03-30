/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:48:27 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/30 11:56:23 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_b(t_stack *stack)
{
	int	i;
	int	imax;;
	int	max;

	i = 0;
	max = stack->b[0];
	while (i <= stack->current_b)
	{
		if (stack->b[i] >= max)
		{
			max = stack->b[i];
			imax = i;
		}
		i++;
	}
	return (imax);
}

static int	find_min_b(t_stack *stack)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	min = stack->b[0];
	while (i <= stack->current_b)
	{
		if (stack->b[i] <= min)
		{
			min = stack->b[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	count_moves_zero(int i, t_stack *stack)
{
	int	j;
	int	min;
	int	max;

	j = 0;
	min = find_min_b(stack);
	max = find_max_b(stack);
	if (stack->a[i] > stack->b[max])
	{
		stack->index_insert_to = max;
		j = max;
		if (i <= j)
			return (i + (j - i) + 1);
		else if (i > j)
			return (j + (i - j) + 1);
	}
	else if (stack->a[i] < stack->b[min])
	{
		if (min == stack->current_b)
		{
			stack->index_insert_to = 0;
			j = 0;
			if (i <= j)
				return (i + (j - i) + 1);
			else if (i > j)
				return (j + (i - j) + 1);
		}
		else if (min != stack->current_b)
		{
			stack->index_insert_to = min + 1;
			j = min + 1;
			if (i <= j)
				return (i + (j - i) + 1);
			else if (i > j)
				return (j + (i - j) + 1);
		}
	}
	else
	{
		while (j <= stack->current_b)
		{
			if (j != stack->current_b)
			{
				if ((stack->a[i] < stack->b[j]) && (stack->a[i] > stack->b[j + 1]))
				{
					j++;
					stack->index_insert_to = j;
					if (i <= j)
						return (i + (j - i) + 1);
					else if (i > j)
						return (j + (i - j) + 1);
				}
			}
			else if (j == stack->current_b)
			{
				if ((stack->a[i] < stack->b[j]) && (stack->a[i] > stack->b[0]))
				{
					j = 0;
					stack->index_insert_to = j;
					if (i <= j)
						return (i + (j - i) + 1);
					else if (i > j)
						return (j + (i - j) + 1);
				}
			}
			j++;
		}
	}
	return (-1);
}

int	cheapest_move(t_stack *stack)
{
	int	i;
	int	n;
	int	ret;

	i = 0;
	ret = count_moves_zero(0, stack);
	while (i <= stack->current_a)
	{
		n = count_moves_zero(i, stack);
		if (n <= ret)
		{
			stack->index_min = i;
			ret = n;
		}
		i++;
	}
	return (ret);
}
