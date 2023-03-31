/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:48:27 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/31 18:52:10 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_max_b(t_stack *stack)
{
	int	i;
	int	imax;;
	int	max;

	i = 0;
	max = stack->b[0];
	imax = 0;
	while (i <= stack->current_b)
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
	while (i <= stack->current_b)
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
	{
		stack->index_insert_to = max;
		j = max;
		if (i <= (stack->current_a / 2) && j <= (stack->current_b / 2))
		{
			if (i <= j)
				return (i + (j - i) + 1);
			else
				return (j + (i - j) + 1);
		}
		else if (i <= (stack->current_a / 2) && j > (stack->current_b / 2))
			return (i + (stack->current_b - j + 1) + 1);
		else if (i > (stack->current_a / 2) && j <= (stack->current_b / 2))
			return ((stack->current_a - i + 1) + j + 1);
		else if (i > (stack->current_a / 2) && j > (stack->current_b / 2))
		{
			if (i <= j)
				return ((stack->current_b - j + 1) + (j - i) + 1);
			else if (i > j)
				return ((stack->current_a - i + 1) + (i - j) + 1);
		}
	}
	else if (stack->a[i] < stack->b[min])
	{
		if (min == stack->current_b)
		{
			stack->index_insert_to = 0;
			j = 0;
			if (i <= (stack->current_a) / 2)
					return (i + 1);
			else if (i > stack->current_a / 2)
				return ((stack->current_a - i) + 1);
		}
		else if (min != stack->current_b)
		{
			stack->index_insert_to = min + 1;
			j = min + 1;
			if (i <= (stack->current_a / 2) && j <= (stack->current_b / 2))
			{
				if (i <= j)
					return (i + (j - i) + 1);
				else if (i > j)
					return (j + (i - j) + 1);
			}
			else if (i <= (stack->current_a / 2) && j > (stack->current_b / 2))
				return (i + (stack->current_b - j + 1) + 1);
			else if (i > (stack->current_a / 2) && j <= (stack->current_b / 2))
				return ((stack->current_a - i + 1) + j + 1);
			else if (i > (stack->current_a / 2) && j > (stack->current_b / 2))
			{
				if (i <= j)
					return ((stack->current_b - j + 1) + (j - i) + 1);
				else if (i > j)
					return ((stack->current_a - i + 1) + (i - j) + 1);
			}
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
					if (i <= (stack->current_a / 2) && j <= (stack->current_b / 2))
					{
						if (i <= j)
							return (i + (j - i) + 1);
						else if (i > j)
							return (j + (i - j) + 1);
					}
					else if (i <= (stack->current_a / 2) && j > (stack->current_b / 2))
						return (i + (stack->current_b - j + 1) + 1);
					else if (i > (stack->current_a / 2) && j <= (stack->current_b / 2))
						return ((stack->current_a - i + 1) + j + 1);
					else if (i > (stack->current_a / 2) && j > (stack->current_b / 2))
					{
						if (i <= j)
							return ((stack->current_b - j + 1) + (j - i) + 1);
						else if (i > j)
							return ((stack->current_a - i + 1) + (i - j) + 1);
					}
				}
			}
			else if (j == stack->current_b)
			{
				if ((stack->a[i] < stack->b[j]) && (stack->a[i] > stack->b[0]))
				{
					j = 0;
					stack->index_insert_to = 0;
					if (i <= stack->current_a / 2)
						return (i + 1);
					else if (i > stack->current_a / 2)
						return ((stack->current_a - i + 1) + 1);
				}
			}
			j++;
		}
	}
	return (5000);
}

int	cheapest_move(t_stack *stack)
{
	int	i;
	int	n;
	int	ret;

	i = 0;
	ret = count_moves(0, stack);
	stack->index_min = 0;
	while (i <= stack->current_a)
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
