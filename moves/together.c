/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   together.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:04:21 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/16 12:04:24 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack, int flag)
{
	sa(stack, 0);
	sb(stack, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
}

void	rrr(t_stack *stack, int flag)
{
	rra(stack, 0);
	rrb(stack, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}

void	rr(t_stack *stack, int flag)
{
	ra(stack, 0);
	rb(stack, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}
