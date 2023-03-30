/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:01:58 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/30 14:47:05 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init(t_stack *stack)
{
	stack->len = stack->current_a + 1;
	stack->lis_raw = (int *)malloc(stack->len * sizeof(int));
	stack->dp = (int *)malloc(stack->len * sizeof(int));
	stack->prev = (int *)malloc(stack->len * sizeof(int));
	stack->lis_used = 0;
}

static void	lis_raw_check(t_stack *stack)
{
	int	i;
	int	j;

	i = 1;
	while (i < stack->len)
	{
		j = 0;
		while (j < i)
		{
			if (stack->a[j] < stack->a[i] && stack->dp[j] + 1 > stack->dp[i])
			{
				stack->dp[i] = stack->dp[j] + 1;
				stack->prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

static void	find_max_lis(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->dp[i] > stack->dp[stack->lis_raw_len])
			stack->lis_raw_len = i;
		i++;
	}
}

static void	lis_raw_gen(t_stack *stack)
{
	int	i;
	int	j;

	i = stack->lis_raw_len;
	j = stack->dp[stack->lis_raw_len] - 1;
	while (i >= 0)
	{
		stack->lis_raw[j] = stack->a[i];
		i = stack->prev[i];
		j--;
	}
}

static int	get_lis_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->lis_raw_len)
	{
		if (stack->lis_raw[i] > stack->lis_raw[i + 1])
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

static void	lis_gen(t_stack *stack)
{
	int	i;

	i = 0;
	stack->lis_len = get_lis_len(stack);
	stack->lis = (int *)malloc(stack->lis_len * sizeof(int));
	while (i < stack->lis_len)
	{
		stack->lis[i] = stack->lis_raw[i];
		i++;
	}
}

static int ft_strchr_lis(int i, t_stack *stack)
{
	int j;
	int	k;

	j = 0;
	k = 0;
	while (stack->lis[k])
		k++;
	while (stack->lis[j])
	{
		if (stack->a[i] == stack->lis[k - 1])
			return (2);
		if (stack->a[i] == stack->lis[j])
			return (1);
		else
			j++;
	}
	return (0);

}

void	push_new_lis_to_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->current_a)
	{
		if (ft_strchr_lis(i, stack) == 0)
		{
			stack->n_moves += ra(stack, 1);
		}
		if (ft_strchr_lis(i, stack) == 1)
		{
			stack->n_moves += pb(stack, 1);
		}
		if (ft_strchr_lis(i, stack) == 2)
		{
			stack->n_moves += pb(stack, 1);
			return ;
		}
	}
}

void	lis_finder(t_stack *stack)
{
	int	i;

	i = 0;
	init(stack);
	while (i < stack->len)
	{
		stack->lis_raw[i] = 0;
		stack->dp[i] = 1;
		stack->prev[i] = -1;
		i++;
	}
	lis_raw_check(stack);
	find_max_lis(stack);
	lis_raw_gen(stack);
	lis_gen(stack);
	stack->lis_used = 1;
	i = 0;
	while (i < stack->lis_len)
	{
		ft_printf("%d\n", stack->lis[i]);
		i++;
	}
}
