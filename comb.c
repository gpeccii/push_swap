/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:30:48 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 13:34:12 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	comb1_1(t_stack *stack)
{
	int	k;

	k = 0;
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

void	comb1_2(t_stack *stack)
{
	int	k;

	k = 0;
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
