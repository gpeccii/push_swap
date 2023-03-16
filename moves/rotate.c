/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:03:18 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/16 12:09:01 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack, int flag)
{
	int	i;
	int	tmp;

	i = stack->current_a;
	tmp = stack->stack_a[stack->current_a];
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->stack_a[0] = tmp;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int flag)
{
	int	i;
	int	tmp;

	i = stack->current_b;
	tmp = stack->stack_b[stack->current_b];
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->stack_b[0] = tmp;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	ra(t_stack *stack, int flag)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->stack_a[0];
	while (i < stack->current_a)
	{
		stack->stack_a[i] = stack->stack_a[i + 1];
		i++;
	}
	stack->stack_a[stack->current_a] = tmp;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int flag)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->stack_b[0];
	while (i < stack->current_b)
	{
		stack->stack_b[i] = stack->stack_b[i + 1];
		i++;
	}
	stack->stack_b[stack->current_b] = tmp;
	if (flag == 1)
		write(1, "rb\n", 3);
}
