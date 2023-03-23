/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:14:02 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/23 16:43:24 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a[0];
	b = stack->a[1];
	c = stack->a[2];
	if (a > b && b < c && c > a)
		stack->n_moves += sa(stack, 1);
	else if (a > b && b > c && c < a)
	{
		stack->n_moves += sa(stack, 1);
		stack->n_moves += rra(stack, 1);
	}
	else if (a > b && b < c && c < a)
		stack->n_moves += ra(stack, 1);
	else if (a < b && b > c && c > a)
	{
		stack->n_moves += sa(stack, 1);
		stack->n_moves += ra(stack, 1);
	}
	else if (a < b && b > c && c < a)
		stack->n_moves += rra(stack, 1);
}

void	sort_two(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->a[0];
	b = stack->a[1];
	if (a > b)
		stack->n_moves += sa(stack, 1);
}

void	lis_to_b(t_stack *stack)
{
	int	i;
	int	t;
	int	z;

	lis(stack);
	t = stack->index_lis;
	z = stack->size_lis + 1;
	i = -1;
	if (stack->index_lis <= (stack->current_a / 2))
	{
		while (++i < t)
			stack->n_moves += ra(stack, 1);
	}
	else if (stack->index_lis > (stack->current_a / 2))
	{
		while (t >= stack->index_lis)
		{
			stack->n_moves += rra(stack, 1);
			t--;
		}
	}
	while (--z > 0)
		stack->n_moves += pb(stack, 1);
}

void	sort_big(t_stack *stack)
{
	int	i;
	lis_to_b(stack);
	i = cheapest_move(stack);
	ft_printf("%d\n", i);
}
