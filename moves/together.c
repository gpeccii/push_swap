/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   together.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:17 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/22 20:13:19 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ss(t_stack *stack, int flag)
{
	int	i;

	i = 1;
	sa(stack, 0);
	sb(stack, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
	return (i);
}

int	rrr(t_stack *stack, int flag)
{
	int	i;

	i = 1;
	rra(stack, 0);
	rrb(stack, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
	return (i);
}

int	rr(t_stack *stack, int flag)
{
	int	i;

	i = 1;
	ra(stack, 0);
	rb(stack, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
	return (i);
}
