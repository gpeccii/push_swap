/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:46 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/23 16:49:02 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_stack(char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack->a = (int *)ft_calloc(sizeof(int), (stack->current_a) + 1);
	while (argv[j])
		stack->a[i++] = ft_atoi(argv[j++]);
	stack->a[i] = '\0';
	stack->b = (int *)ft_calloc(sizeof(int), (stack->current_a) + 1);
}

int	main(int argc, char **argv)
{
	//int	i = 0;
	t_stack	stack;

	if (alpha_check(argv) == 0 || ft_checkdoubles(argv, argc) == 0)
		ft_printf("Error\n");
	else
	{
		stack.current_a = argc - 2;
		stack.current_b = 0;
		fill_stack(argv, &stack);
		if (argc == 3)
			sort_two(&stack);
		else if (argc == 4)
			sort_three(&stack);
		else if (argc > 4)
			sort_big(&stack);
	}
	//while(stack.b[i])
	//{
	//	ft_printf("%d\n",stack.b[i]);
	//	i++;
	//}
	free(stack.a);
	free(stack.b);
	return (0);
}
