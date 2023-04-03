/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:44:51 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 17:28:18 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	funz(t_stack *stack, int i, int j)
{
	if ((i <= (stack->last_a / 2)) && (j <= (stack->last_b / 2)))
	{
		if (i <= j)
			comb1_1(stack, i, j);
		else if (i > j)
			comb1_2(stack, i, j);
	}
	else if ((i <= (stack->last_a / 2)) && (j > (stack->last_b / 2)))
		comb2(stack, i, j);
	else if ((i > (stack->last_a / 2)) && (j <= (stack->last_b / 2)))
		comb3(stack, i, j);
	else if ((i > (stack->last_a / 2)) && (j > (stack->last_b / 2)))
	{
		if ((stack->last_a - i) <= (stack->last_b - j))
			comb4_1(stack, i, j);
		else if ((stack->last_a - i) > (stack->last_b - j))
			comb4_2(stack, i, j);
	}
}

static void	push_ordinate_in_b(t_stack *stack)
{
	int	k;

	k = 0;
	cheapest_move(stack);
	count_moves(stack->index_min, stack);
	funz(stack, stack->index_min, stack->index_to);
}

static void	find_max_and_rotate(t_stack *stack)
{
	int	index;

	index = find_index_max_b(stack);
	if (index <= (stack->last_b / 2))
	{
		while (index > 0)
		{
			stack->n_moves += rb(stack, 1);
			index--;
		}
	}
	else if (index > (stack->last_b / 2))
	{
		while (index <= stack->last_b)
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
	while (stack->last_a >= 0)
		push_ordinate_in_b(stack);
	find_max_and_rotate(stack);
	while (stack->last_b >= 0)
		stack->n_moves += pa(stack, 1);
	free(stack->a);
	free(stack->b);
}
