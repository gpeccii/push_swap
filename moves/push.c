/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:12:51 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/22 20:12:54 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack *stack, int flag)
{
	int	j;
	int	i;

	i = 1;
	j = stack->current_a;
	while (j > 0)
	{
		stack->a[j] = stack->a[j - 1];
		j--;
	}
	stack->current_a++;
	stack->a[0] = stack->b[0];
	j = 1;
	while (j <= stack->current_b)
	{
		stack->b[j - 1] = stack->b[j];
		j++;
	}
	stack->current_b--;
	if (flag == 1)
		write(1, "pa\n", 3);
	return (i);
}

int	pb(t_stack *stack, int flag)
{
	int	j;
	int	i;

	i = 1;
	j = stack->current_b;
	while (j > 0)
	{
		stack->b[j] = stack->b[j - 1];
		j--;
	}
	stack->current_b++;
	stack->b[0] = stack->a[0];
	j = 0;
	while (j <= stack->current_a)
	{
		stack->a[j - 1] = stack->a[j];
		j++;
	}
	stack->current_a--;
	if (flag == 1)
		write(1, "pb\n", 3);
		return (i);
}
