/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb2_comb3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:36:28 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 17:28:01 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	comb2(t_stack *stack, int i, int j)
{
	int	k;

	k = 0;
	while (k < i)
	{
		stack->n_moves += ra(stack, 1);
		k++;
	}
	k = 0;
	while (k <= (stack->last_b - j))
	{
		stack->n_moves += rrb(stack, 1);
		k++;
	}
	stack->n_moves += pb(stack, 1);
	return ;
}

void	comb3(t_stack *stack, int i, int j)
{
	int	k;

	k = 0;
	while (k <= (stack->last_a - i))
	{
		stack->n_moves += rra(stack, 1);
		k++;
	}
	k = 0;
	while (k < j)
	{
		stack->n_moves += rb(stack, 1);
		k++;
	}
	stack->n_moves += pb(stack, 1);
	return ;
}
