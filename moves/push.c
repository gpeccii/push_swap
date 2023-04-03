/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:12:51 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 13:44:23 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack *stack, int flag)
{
	int	j;
	int	i;

	i = 1;
	j = stack->last_a;
	while (j >= 0)
	{
		stack->a[j + 1] = stack->a[j];
		j--;
	}
	stack->last_a += 1;
	stack->a[0] = stack->b[0];
	j = 0;
	while (j < stack->last_b)
	{
		stack->b[j] = stack->b[j + 1];
		j++;
	}
	stack->last_b -= 1;
	if (flag == 1)
		write(1, "pa\n", 3);
	return (i);
}

int	pb(t_stack *stack, int flag)
{
	int	j;
	int	i;

	i = 1;
	j = stack->last_b;
	while (j >= 0)
	{
		stack->b[j + 1] = stack->b[j];
		j--;
	}
	stack->last_b += 1;
	stack->b[0] = stack->a[0];
	j = 0;
	while (j < stack->last_a)
	{
		stack->a[j] = stack->a[j + 1];
		j++;
	}
	stack->last_a -= 1;
	if (flag == 1)
		write(1, "pb\n", 3);
	return (i);
}
