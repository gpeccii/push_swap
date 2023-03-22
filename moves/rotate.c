/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:00 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/22 20:13:04 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_stack *stack, int flag)
{
	int	tmp;
	int	j;

	j = stack->current_a;
	tmp = stack->a[j];
	while (j > 0)
	{
		stack->a[j] = stack->a[j - 1];
		j--;
	}
	stack->a[0] = tmp;
	if (flag == 1)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *stack, int flag)
{
	int	tmp;
	int	j;

	j = stack->current_b;
	tmp = stack->b[j];
	while (j > 0)
	{
		stack->b[j] = stack->b[j - 1];
		j--;
	}
	stack->b[0] = tmp;
	if (flag == 1)
		write(1, "rrb\n", 4);
	return (1);
}

int	ra(t_stack *stack, int flag)
{
	int	tmp;
	int	j;

	j = 0;
	tmp = stack->a[0];
	while (j < stack->current_a)
	{
		stack->a[j] = stack->a[j + 1];
		j++;
	}
	stack->a[stack->current_a] = tmp;
	if (flag == 1)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack *stack, int flag)
{
	int	tmp;
	int	j;

	j = 0;
	tmp = stack->b[0];
	while (j < stack->current_b)
	{
		stack->b[j] = stack->b[j + 1];
		j++;
	}
	stack->b[stack->current_b] = tmp;
	if (flag == 1)
		write(1, "rb\n", 3);
	return (1);
}
