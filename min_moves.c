/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:48:27 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 13:44:23 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		stack->index_to = max;
		j = max;
		if (i <= (stack->last_a / 2) && j <= (stack->last_b / 2))
		{
			if (i <= j)
				return (i + (j - i) + 1);
			else
				return (j + (i - j) + 1);
		}
		else if (i <= (stack->last_a / 2) && j > (stack->last_b / 2))
			return (i + (stack->last_b - j + 1) + 1);
		else if (i > (stack->last_a / 2) && j <= (stack->last_b / 2))
			return ((stack->last_a - i + 1) + j + 1);
		else if (i > (stack->last_a / 2) && j > (stack->last_b / 2))
		{
			if ((stack->last_a - i) <= (stack->last_b - j))
				return ((stack->last_a - i + 1) + ((stack->last_b - j) - (stack->last_a - i)) + 1);
			else if ((stack->last_a - i) > (stack->last_b - j))
				return ((stack->last_b - j + 1) + ((stack->last_a - i) - (stack->last_b - j)) + 1);
		}
	}
	else if (stack->a[i] < stack->b[min])
	{
		if (min == stack->last_b)
		{
			stack->index_to = 0;
			j = 0;
			if (i <= (stack->last_a) / 2)
				return (i + 1);
			else if (i > stack->last_a / 2)
				return ((stack->last_a - i + 1) + 1);
		}
		else if (min != stack->last_b)
		{
			stack->index_to = min + 1;
			j = min + 1;
			if (i <= (stack->last_a / 2) && j <= (stack->last_b / 2))
			{
				if (i <= j)
					return (i + (j - i) + 1);
				else if (i > j)
					return (j + (i - j) + 1);
			}
			else if (i <= (stack->last_a / 2) && j > (stack->last_b / 2))
				return (i + (stack->last_b - j + 1) + 1);
			else if (i > (stack->last_a / 2) && j <= (stack->last_b / 2))
				return ((stack->last_a - i + 1) + j + 1);
			else if (i > (stack->last_a / 2) && j > (stack->last_b / 2))
			{
				if ((stack->last_a - i) <= (stack->last_b - j))
					return ((stack->last_a - i + 1) + ((stack->last_b - j) - (stack->last_a - i)) + 1);
				else if ((stack->last_a - i) > (stack->last_b - j))
					return ((stack->last_b - j + 1) + ((stack->last_a - i) - (stack->last_b - j)) + 1);
			}
		}
	}
	else
	{
		while (j <= stack->last_b)
		{
			if (j != stack->last_b)
			{
				if ((stack->a[i] < stack->b[j]) && (stack->a[i] > stack->b[j + 1]))
				{
					j++;
					stack->index_to = j;
					if (i <= (stack->last_a / 2) && j <= (stack->last_b / 2))
					{
						if (i <= j)
							return (i + (j - i) + 1);
						else if (i > j)
							return (j + (i - j) + 1);
					}
					else if (i <= (stack->last_a / 2) && j > (stack->last_b / 2))
						return (i + (stack->last_b - j + 1) + 1);
					else if (i > (stack->last_a / 2) && j <= (stack->last_b / 2))
						return ((stack->last_a - i + 1) + j + 1);
					else if (i > (stack->last_a / 2) && j > (stack->last_b / 2))
					{
						if ((stack->last_a - i) <= (stack->last_b - j))
							return ((stack->last_a - i + 1) + ((stack->last_b - j) - (stack->last_a - i)) + 1);
						else if ((stack->last_a - i) > (stack->last_b - j))
							return ((stack->last_b - j + 1) + ((stack->last_a - i) - (stack->last_b - j)) + 1);
					}
				}
			}
			else if (j == stack->last_b)
			{
				if ((stack->a[i] < stack->b[j]) && (stack->a[i] > stack->b[0]))
				{
					j = 0;
					stack->index_to = 0;
					if (i <= stack->last_a / 2)
						return (i + 1);
					else if (i > stack->last_a / 2)
						return ((stack->last_a - i + 1) + 1);
				}
			}
			j++;
		}
	}
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
