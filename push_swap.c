/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:46 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/04 18:46:29 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack *stack)
{
	if (ft_sorted(stack) == 0)
		return ;
	if (stack->last_a == 0)
		return ;
	else if (stack->last_a == 1)
		sort_two(stack);
	else if (stack->last_a == 2)
		sort_three(stack);
	else if (stack->last_a == 4)
		sort_five(stack);
	else if (stack->last_a > 2)
		sort_big(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 2)
	{
		if (checkone(argv[1]) == 0 || ft_checkdoubles_2(argv[1]) == 0)
		{
			write(2, "Error\n", 6);
			return (EXIT_FAILURE);
		}
		fill_stackone(argv, &stack);
	}
	else if (argc > 2)
	{
		if (number_check(argv) == 0 || ft_checkdoubles(argv, argc) == 0)
		{
			write(2, "Error\n", 6);
			return (EXIT_FAILURE);
		}
		fill_stack(argc, argv, &stack);
	}
	sort(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
