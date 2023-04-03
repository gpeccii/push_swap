/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeccstack->index_min <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:14:02 by gpeccstack->index_min            #+#    #+#             */
/*   Updated: 2023/03/31 20:19:42 by gpeccstack->index_min           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_ordinate_in_b(t_stack *stack)
{
	int	k;

	k = 0;
	cheapest_move(stack);
	count_moves(stack->index_min, stack);
	if ((stack->index_min <= (stack->current_a / 2)) && (stack->index_insert_to <= (stack->current_b / 2)))
	{
		if (stack->index_min <= stack->index_insert_to)
		{
			while (k < stack->index_min)
			{
				stack->n_moves += rr(stack, 1);
				k++;
			}
			k = 0;
			while (k < (stack->index_insert_to - stack->index_min))
			{
				stack->n_moves += rb(stack, 1);
				k++;
			}
			stack->n_moves += pb(stack, 1);
			return ;
		}
		else if (stack->index_min > stack->index_insert_to)
		{
			while (k < stack->index_insert_to)
			{
				stack->n_moves += rr(stack, 1);
				k++;
			}
			k = 0;
			while (k < (stack->index_min - stack->index_insert_to))
			{
				stack->n_moves += ra(stack, 1);
				k++;
			}
			stack->n_moves += pb(stack, 1);
			return ;
		}
	}
	else if ((stack->index_min <= (stack->current_a / 2)) && (stack->index_insert_to > (stack->current_b / 2)))
	{
		while (k < stack->index_min)
		{
			stack->n_moves += ra(stack, 1);
			k++;
		}
		k = 0;
		while (k <= (stack->current_b - stack->index_insert_to))
		{
			stack->n_moves += rrb(stack, 1);
			k++;
		}
		stack->n_moves += pb(stack, 1);
		return ;
	}
	else if ((stack->index_min > (stack->current_a / 2)) && (stack->index_insert_to <= (stack->current_b / 2)))
	{
		while (k <= (stack->current_a - stack->index_min))
		{
			stack->n_moves += rra(stack, 1);
			k++;
		}
		k = 0;
		while (k < stack->index_insert_to)
		{
			stack->n_moves += rb(stack, 1);
			k++;
		}
		stack->n_moves += pb(stack, 1);
		return ;
	}
	else if ((stack->index_min > (stack->current_a / 2)) && (stack->index_insert_to > (stack->current_b / 2)))
	{
		if ((stack->current_a - stack->index_min) <= (stack->current_b - stack->index_insert_to))
		{
			while (k <= (stack->current_a - stack->index_min))
			{
				stack->n_moves += rrr(stack, 1);
				k++;
			}
			k = 0;
			while (k < (stack->current_b - stack->index_insert_to) - (stack->current_a - stack->index_min))
			{
				stack->n_moves += rrb(stack, 1);
				k++;
			}
			stack->n_moves += pb(stack, 1);
			return ;
		}
		else if ((stack->current_a - stack->index_min) > (stack->current_b - stack->index_insert_to))
		{
			while (k <= (stack->current_b - stack->index_insert_to))
			{
				stack->n_moves += rrr(stack, 1);
				k++;
			}
			k = 0;
			while (k < (stack->current_a - stack->index_min) - (stack->current_b - stack->index_insert_to))
			{
				stack->n_moves += rra(stack, 1);
				k++;
			}
			stack->n_moves += pb(stack, 1);
			return ;
		}
	}
}

static void	find_max_and_rotate(t_stack *stack)
{
	int	index;

	index = find_index_max_b(stack);
	if (index <= (stack->current_b / 2))
	{
		while (index > 0)
		{
			stack->n_moves += rb(stack, 1);
			index--;
		}
	}
	else if (index > (stack->current_b / 2))
	{
		while (index <= stack->current_b)
		{
			stack->n_moves += rrb(stack, 1);
			index++;
		}
	}
}

void	sort_big(t_stack *stack)
{
	stack->n_moves += pb(stack, 1);
	stack->n_moves += pb(stack, 1);
	if (stack->b[0] < stack->b[1])
		stack->n_moves += sb(stack, 1);
	while (stack->current_a >= 0)
		push_ordinate_in_b(stack);
	find_max_and_rotate(stack);
	while (stack->current_b >= 0)
		stack->n_moves += pa(stack, 1);
	free(stack->a);
	free(stack->b);
}
