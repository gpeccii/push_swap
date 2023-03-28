/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:48:27 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/28 15:35:03 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_b(t_stack *stack)
{
	int	i;
	int	imax;;
	int	max;

	i = -1;
	max = stack->b[0];
	while (++i <= stack->current_b)
	{
		if (stack->b[i] >= max)
		{
			max = stack->b[i];
			imax = i;
		}
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
		if (stack->b[i] < min)
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
			//printf("DIOCANE\n");
			//printf("jei = %d\n", j);
			if (j != stack->current_b)
			{
				if ((stack->a[i] < stack->b[j]) && (stack->a[i] > stack->b[j + 1]))
				{
					j++;
					stack->index_insert_to = j;
					//printf("i = %d j = %d\n", i, j);
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
	return (42);
}

//int	       count_moves_last(int i, t_stack *stack)
//{
//	int	j;

//	j = stack->current_b;
//	while (--j >= 0)
//	{
//		if (stack->a[i] < stack->b[j])
//		{
//			stack->index_insert_to = j;
//			if (i >= j)
//				return ((stack->current_b - j) + (i - j) + 1);
//			else if (i < j)
//				return ((stack->current_a - i) + (j - i) + 1);
//		}
//	}
//	stack->index_insert_to = 0;
//	return ((stack->current_a - i + 1));
//}

int	cheapest_move(t_stack *stack)
{
	int	i;
	int	j;
	int	n;
	int	ret;

	i = 0;
	j = stack->current_a + 1;
	ret = count_moves_zero(0, stack);
	while (i <= stack->current_a)
	{
		n = count_moves_zero(i, stack);
		if (n < ret)
		{
			stack->index_min = i;
			ret = n;
		}
		i++;
	}
	//while (--j >= (stack->current_a / 2))
	//{
	//	n = count_moves_last(j, stack);
	//	if (n < ret)
	//	{
	//		stack->index_min = j;
	//		ret = n;
	//	}
	//}
	//ft_printf("\n");
	//printf("min %d ret %d\n", stack->index_min, ret);
	return (ret);
}
