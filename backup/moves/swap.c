/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:11 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/23 11:33:28 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_stack *stack, int flag)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
	return (i);
}

int	sb(t_stack *stack, int flag)
{
	int	tmp;
	int	i;

	i = 1;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
	return (i);
}
