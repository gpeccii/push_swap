/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:45:09 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/04 19:04:41 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_error_check(t_stack *stack)
{
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	write(2, "Error\n", 6);
	exit (1);
}

void	other_or_error(t_stack *stack, char *str)
{
	if (ft_strcmp(str, "rra\n") == 1)
		rra(stack, 0);
	else if (ft_strcmp(str, "rrb\n") == 1)
		rrb(stack, 0);
	else if (ft_strcmp(str, "rrr\n") == 1)
		rrr(stack, 0);
	else
		exit_error_check(stack);
}

void	ft_checker(t_stack *stack, char *str)
{
	while (str != NULL)
	{
		if (ft_strcmp(str, "\n") == 1)
			return ;
		if (ft_strcmp(str, "sa\n") == 1)
			sa(stack, 0);
		else if (ft_strcmp(str, "sb\n") == 1)
			sb(stack, 0);
		else if (ft_strcmp(str, "ss\n") == 1)
			ss(stack, 0);
		else if (ft_strcmp(str, "pa\n") == 1)
			pa(stack, 0);
		else if (ft_strcmp(str, "pb\n") == 1)
			pb(stack, 0);
		else if (ft_strcmp(str, "ra\n") == 1)
			ra(stack, 0);
		else if (ft_strcmp(str, "rb\n") == 1)
			rb(stack, 0);
		else if (ft_strcmp(str, "rr\n") == 1)
			rr(stack, 0);
		else
			other_or_error(stack, str);
		str = get_next_line(0);
	}
	return ;
}

static void	ft_check_ordinate(t_stack *stack)
{
	if (ft_sorted(stack) == 0)
		write(1, "OK\n", 3);
	else if (ft_sorted(stack) == 1)
		write(1, "KO\n", 3);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	else if (argc == 2)
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
	ft_checker(&stack, get_next_line(0));
	ft_check_ordinate(&stack);
	return (0);
}
