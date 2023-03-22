/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:52 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/22 20:13:54 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	current_a; //index last of stack a
	int	current_b;//index last of stack b
	int	size_lis;
	int	index_lis;
	int	n_moves;
}			t_stack;

//push moves
int		pa(t_stack *stack, int flag);
int		pb(t_stack *stack, int flag);
//rotate moves
int		ra(t_stack *stack, int flag);
int		rb(t_stack *stack, int flag);
int		rra(t_stack *stack, int flag);
int		rrb(t_stack *stack, int flag);
//swap moves
int		sa(t_stack *stack, int flag);
int		sb(t_stack *stack, int flag);
//both stack moves
int		ss(t_stack *stack, int flag);
int		rr(t_stack *stack, int flag);
int		rrr(t_stack *stack, int flag);

int		alpha_check(char **argv);
int		ft_checkdoubles(char **argv, int argc);

void	lis(t_stack *stack);

void	sort_three(t_stack *stack);
void	sort_two(t_stack *stack);
void	lis_to_b(t_stack *stack);

#endif
