/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoviell <enoviell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:37:38 by enoviell          #+#    #+#             */
/*   Updated: 2023/03/29 17:27:19 by enoviell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_a(t_stack *stack)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = stack->a[0];
	while (i <= stack->current_a)
	{
		if (stack->a[i] >= max)
		{
			max = stack-> a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static int	find_min_a(t_stack *stack)
{
	int i;
	int min;
	int index;

	i = 0;
	min = stack->a[0];
	while (i <= stack->current_a)
	{
		if (stack->a[i] <= min)
		{
			min = stack->a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	sort_five(t_stack *stack)
{
	int max;
	int min;
	int i;
	int j;

	i = 0;
	j = 0;
	max = find_max_a(stack);
	min = find_min_a(stack);
	

	if( min < max)
	{
		while(i < min)
		{
			ra(stack, 1);
			i++;
		}
		pb(stack, 1);
		i = 1;
		while (i < max - min)
		{
			ra(stack, 1);
			i++;
		}
		pb(stack, 1);
	}
	else
	{
		while(i < max)
		{
			ra(stack, 1);
			i++;
		}
		pb(stack, 1);
		i = 1;
		while (i < min - max)
		{
			ra(stack, 1);
			i++;
		}
		pb(stack, 1);
	}


	// while (i <= stack->current_a)
	// {
	// 	if (stack->a[0] == stack->a[max] || stack->a[0] == stack->a[min])
	// 		pb(stack, 1);
	// 	else
	// 	{
	// 	 if (stack->current_a > 2)
	// 			ra(stack, 1);
	// 	}
	// 	i++;
	// }
	sort_three(stack);
	//  if (stack->b[0]> stack->b[1])
	//  	sb(stack, 1);
	//  pa(stack, 1);
	//  pa(stack, 1);
	//  ra(stack, 1);
}
