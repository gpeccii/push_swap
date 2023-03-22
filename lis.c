/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:33 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/22 20:13:35 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis(t_stack *stack)
{
	int	i;
	int	temp;
	int	flag;

	i = 0;
	while (stack->a[i])
	{
		temp = 1;
		while (stack->a[i + 1] && (stack->a[i] < stack->a[i + 1]))
		{
			if (i == 0)
				flag  = 1;
			temp++;
			i++;
		}
		i++;
		if (flag == 1)
		{
			stack->size_lis = temp;
			stack->index_lis = i - stack->size_lis;
		}
		flag = 0;
		if (temp > stack->size_lis)
		{
			stack->size_lis = temp;
			stack->index_lis = i - stack->size_lis;
		}
	}
}
