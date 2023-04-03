/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:58:10 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 17:28:11 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_to_insert(t_stack *stack, int i, int j, int max)
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
			return ((stack->last_a - i + 1)
				+ ((stack->last_b - j) - (stack->last_a - i)) + 1);
		else if ((stack->last_a - i) > (stack->last_b - j))
			return ((stack->last_b - j + 1)
				+ ((stack->last_a - i) - (stack->last_b - j)) + 1);
	}
	return (500);
}

static int	min_insert_utils(t_stack *stack, int i, int j, int min)
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
			return ((stack->last_a - i + 1)
				+ ((stack->last_b - j) - (stack->last_a - i)) + 1);
		else if ((stack->last_a - i) > (stack->last_b - j))
			return ((stack->last_b - j + 1)
				+ ((stack->last_a - i) - (stack->last_b - j)) + 1);
	}
	return (500);
}

int	min_to_insert(t_stack *stack, int i, int j, int min)
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
		return (min_insert_utils(stack, i, j, min));
	return (500);
}

static int	middle_insert_utils(t_stack *stack, int i, int j)
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
			return ((stack->last_a - i + 1)
				+ ((stack->last_b - j) - (stack->last_a - i)) + 1);
		else if ((stack->last_a - i) > (stack->last_b - j))
			return ((stack->last_b - j + 1)
				+ ((stack->last_a - i) - (stack->last_b - j)) + 1);
	}
	return (500);
}

int	middle_insert(t_stack *stack, int i, int j)
{
	while (j <= stack->last_b)
	{
		if (j != stack->last_b)
		{
			if ((stack->a[i] < stack->b[j]) && (stack->a[i] > stack->b[j + 1]))
				return (middle_insert_utils(stack, i, j));
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
	return (500);
}
