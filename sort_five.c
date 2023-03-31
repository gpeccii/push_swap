/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:37:38 by enoviell          #+#    #+#             */
/*   Updated: 2023/03/31 13:07:41 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_a(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->a[0];
	while (i <= stack->current_a)
	{
		if (stack->a[i] <= min)
			min = stack->b[i];
		i++;
	}
	return (min);
}

int	find_max_a(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->a[0];
	while (i <= stack->current_a)
	{
		if (stack->a[i] >= max)
			max = stack->b[i];
		i++;
	}
	return (max);
}

static void	push_min_max(t_stack *stack)
{
	int	max;
	int	min;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = find_max_a(stack);
	min = find_min_a(stack);
	while (i < min)
	{
		stack->n_moves += ra(stack, 1);
		i++;
	}
	stack->n_moves += pb(stack, 1);
	i = 1;
	while (i < max - min)
	{
		stack->n_moves += ra(stack, 1);
		i++;
	}
	stack->n_moves += pb(stack, 1);
}

static void	push_max_min(t_stack *stack)
{
	int	max;
	int	min;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = find_max_a(stack);
	min = find_min_a(stack);
	while (i < max)
	{
		stack->n_moves += ra(stack, 1);
		i++;
	}
	stack->n_moves += pb(stack, 1);
	i = 1;
	while (i < min - max)
	{
		stack->n_moves += ra(stack, 1);
		i++;
	}
	stack->n_moves += pb(stack, 1);
}

void	sort_five(t_stack *stack)
{
	int	max;
	int	min;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = find_max_a(stack);
	min = find_min_a(stack);
	if (min < max)
		push_min_max(stack);
	else
		push_max_min(stack);
	sort_three(stack);
	if (stack->b[0] > stack->b[1])
		stack->n_moves += sb(stack, 1);
	stack->n_moves += pa(stack, 1);
	stack->n_moves += pa(stack, 1);
	stack->n_moves += ra(stack, 1);
}
