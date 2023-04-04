/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:46:36 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/04 18:46:49 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(int argc, char **argv, t_stack *stack)
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
		stack->a[i] = ft_atol(argv[j]);
		i++;
		j++;
	}
	stack->b = malloc(sizeof(int) * (stack->last_a + 1));
}

void	fill_stackone(char **argv, t_stack *stack)
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
		stack->a[i] = ft_atol(str[i]);
		i++;
	}
	i = 0;
	free_matrix(str);
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
