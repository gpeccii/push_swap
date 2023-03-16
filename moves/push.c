/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:02:54 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/16 12:02:57 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack, int flag)
{
	int	i;

	i = stack->current_a;
	while (i > 0)
	{
		stack->stack_a[i] = stack->stack_a[i - 1];
		i--;
	}
	stack->current_a++;
	stack->stack_a[0] = stack->stack_b[0];
	i = 1;
	while (i <= stack->current_b)
	{
		stack->stack_b[i - 1] = stack->stack_b[i];
		i++;
	}
	stack->current_b--;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack, int flag)
{
	int	i;

	i = stack->current_b;
	while (i > 0)
	{
		stack->stack_b[i] = stack->stack_b[i - 1];
		i--;
	}
	stack->current_b++;
	stack->stack_b[0] = stack->stack_a[0];
	i = 0;
	while (i <= stack->current_a)
	{
		stack->stack_a[i - 1] = stack->stack_a[i];
		i++;
	}
	stack->current_a--;
	if (flag == 1)
		write(1, "pb\n", 3);
}
