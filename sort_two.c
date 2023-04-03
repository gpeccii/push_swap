/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:29:05 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 13:29:07 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->a[0];
	b = stack->a[1];
	if (a > b)
		stack->n_moves += sa(stack, 1);
	free(stack->a);
	free(stack->b);
}
