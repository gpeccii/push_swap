/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:46 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 17:25:14 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(int argc, char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack->last_a = argc - 2;
	stack->last_b = -1;
	stack->a = malloc(sizeof(int) * (stack->last_a + 1));
	while (argv[j])
	{
		stack->a[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
	stack->b = malloc(sizeof(int) * (stack->last_a + 1));
}

static void	fill_stackone(char **argv, t_stack *stack)
{
	char	**str;
	int		i;

	str = ft_split(argv[1], ' ');
	i = 0;
	while (str[i])
		i++;
	stack->last_a = i - 1;
	stack->last_b = -1;
	stack->a = malloc(sizeof(int) * (stack->last_a + 1));
	i = 0;
	while (str[i])
	{
		stack->a[i] = ft_atoi(str[i]);
		i++;
	}
	stack->b = malloc(sizeof(int) * (stack->last_a + 1));
}

int	ft_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->last_a)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static void	sort(t_stack *stack)
{
	if (ft_sorted(stack) == 0)
		return ;
	if (stack->last_a == 1)
		return ;
	else if (stack->last_a == 3)
		sort_two(stack);
	else if (stack->last_a == 4)
		sort_three(stack);
	else if (stack->last_a == 6)
		sort_five(stack);
	else if (stack->last_a > 4)
		sort_big(stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 2)
	{
		if (checkone(argv[1]) == 0 || ft_checkdoubles_2(argv[1]) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		fill_stackone(argv, &stack);
	}
	else if (argc > 2)
	{
		if (number_check(argv) == 0 || ft_checkdoubles(argv, argc) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		fill_stack(argc, argv, &stack);
	}
	sort(&stack);
	return (0);
}
