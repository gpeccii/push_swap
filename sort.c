/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:14:02 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/31 20:19:42 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a[0];
	b = stack->a[1];
	c = stack->a[2];
	if (a > b && b < c && c > a)
		stack->n_moves += sa(stack, 1);
	else if (a > b && b > c && c < a)
	{
		stack->n_moves += sa(stack, 1);
		stack->n_moves += rra(stack, 1);
	}
	else if (a > b && b < c && c < a)
		stack->n_moves += ra(stack, 1);
	else if (a < b && b > c && c > a)
	{
		stack->n_moves += sa(stack, 1);
		stack->n_moves += ra(stack, 1);
	}
	else if (a < b && b > c && c < a)
		stack->n_moves += rra(stack, 1);
}

void	sort_two(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->a[0];
	b = stack->a[1];
	if (a > b)
		stack->n_moves += sa(stack, 1);
}

void	lis_to_b(t_stack *stack)
{
	int	i;
	int	j;
	int	t;
	int	z;

	lis(stack);
	t = stack->index_lis;
	z = stack->size_lis;
	i = -1;
	j = stack->current_a + 1;
	if (stack->index_lis <= (stack->current_a / 2))
	{
		while (++i < t)
			stack->n_moves += ra(stack, 1);
	}
	else if (stack->index_lis > (stack->current_a / 2))
	{
		while (--j >= t)
			stack->n_moves += rra(stack, 1);
	}
	while (--z > 0)
		stack->n_moves += pb(stack, 1);
}

static void	push_ordinate_in_b(t_stack *stack)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	cheapest_move(stack);
	count_moves(stack->index_min, stack);
	i = stack->index_min;
	j = stack->index_insert_to;
	if ((i <= (stack->current_a / 2)) && (j <= (stack->current_b / 2)))
	{
		if (i <= j)
		{
			while (k < i)
			{
				stack->n_moves += rr(stack, 1);
				k++;
			}
			k = 0;
			while (k < (j - i))
			{
				stack->n_moves += rb(stack, 1);
				k++;
			}
			stack->n_moves += pb(stack, 1);
			return ;
		}
		else if (i > j)
		{
			while (k < j)
			{
				stack->n_moves += rr(stack, 1);
				k++;
			}
			k = 0;
			while (k < (i - j))
			{
				stack->n_moves += ra(stack, 1);
				k++;
			}
			stack->n_moves += pb(stack, 1);
			return ;
		}
	}
	else if ((i <= (stack->current_a / 2)) && (j > (stack->current_b / 2)))
	{
		while (k < i)
		{
			stack->n_moves += ra(stack, 1);
			k++;
		}
		k = 0;
		while (k <= (stack->current_b - j))
		{
			stack->n_moves += rrb(stack, 1);
			k++;
		}
		stack->n_moves += pb(stack, 1);
		return ;
	}
	else if ((i > (stack->current_a / 2)) && (j <= (stack->current_b / 2)))
	{
		while (k <= (stack->current_a - i))
		{
			stack->n_moves += rra(stack, 1);
			k++;
		}
		k = 0;
		while (k < j)
		{
			stack->n_moves += rb(stack, 1);
			k++;
		}
		stack->n_moves += pb(stack, 1);
		return ;
	}
	else if ((i > (stack->current_a / 2)) && (j > (stack->current_b / 2)))
	{
		if (i <= j && stack->current_a >= stack->current_b)
		{
			while (k <= (stack->current_b - j))
			{
				stack->n_moves += rrr(stack, 1);
				k++;
			}
			k = 0;
			while (k < (stack->current_a - i) - (stack->current_b - j))
			{
				stack->n_moves += rra(stack, 1);
				k++;
			}
			stack->n_moves += pb(stack, 1);
			return ;
		}
		else if (i >= j && stack->current_a < stack->current_b)
		{
			while (k <= (stack->current_a - i))
			{
				stack->n_moves += rrr(stack, 1);
				k++;
			}
			k = 0;
			while (k < (stack->current_b - j) - (stack->current_a - i))
			{
				stack->n_moves += rrb(stack, 1);
				k++;
			}
			stack->n_moves += pb(stack, 1);
			return ;
		}
	}
}

static void	find_max_and_rotate(t_stack *stack)
{
	int index;

	index = find_index_max_b(stack);
	if (index <= (stack->current_b / 2))
	{
		while (index > 0)
		{
			stack->n_moves += rb(stack, 1);
			index--;
		}
	}
	else if (index > (stack->current_b / 2))
	{
		while (index <= stack->current_b)
		{
			stack->n_moves += rrb(stack, 1);
			index++;
		}
	}
}

void	sort_big(t_stack *stack)
{
	//lis_finder(stack);
	//push_new_lis_to_b(stack);
	stack->n_moves += pb(stack, 1);
	stack->n_moves += pb(stack, 1);
	//lis_to_b(stack);
	//rr(stack, 1);
	while (stack->current_a >= 0)
		push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//push_ordinate_in_b(stack);
		//cheapest_move(stack);
		//count_moves(stack->index_min, stack);
		//printf("ca = %d , cb = %d\n", stack->current_a, stack->current_b);
		//printf("i = %d , j = %d\n", stack->index_min, stack->index_insert_to);
	find_max_and_rotate(stack);
	while(stack->current_b >= 0)
		stack->n_moves += pa(stack, 1);
}
