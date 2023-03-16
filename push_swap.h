/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:05:22 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/16 12:10:06 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	current_b;	//index top of stack a
	int	current_a;	//index top of stack b
}	t_stack;

//push moves
void	pa(t_stack *stack, int flag);
void	pb(t_stack *stack, int flag);
//rotate moves
void	ra(t_stack *stack, int flag);
void	rb(t_stack *stack, int flag);
void	rra(t_stack *stack, int flag);
void	rrb(t_stack *stack, int flag);
//swap moves
void	sa(t_stack *stack, int flag);
void	sb(t_stack *stack, int flag);
//both stack moves
void	ss(t_stack *stack, int flag);
void	rr(t_stack *stack, int flag);
void	rrr(t_stack *stack, int flag);

#endif
