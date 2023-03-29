/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:33 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/27 17:54:08 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_lis(int temp, int i, t_stack *stack)
{
	stack->size_lis = temp;
	stack->index_lis = i - stack->size_lis;
}

void	lis(t_stack *stack)
{
	int	i;
	int	temp;
	int	flag;

	i = 0;
	while (i < stack->current_a)
	{
		temp = 1;
		while (stack->a[i + 1] && (stack->a[i] < stack->a[i + 1]))
		{
			if (i == 0)
				flag = 1;
			temp++;
			i++;
		}
		i++;
		if (flag == 1)
			set_lis(temp, i, stack);
		flag = 0;
		if (temp > stack->size_lis)
			set_lis(temp, i, stack);
	}
}
