/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:52 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/31 15:28:04 by gpecci           ###   ########.fr       */
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
	int	current_a;
	int	current_b;
	int	size_lis;
	int	index_lis;
	int	n_moves;
	int	index_insert_to;
	int	index_min;

	int	*dp;
	int	*prev;
	int *lis_raw;
	int	lis_raw_len;
	int	*lis;
	int	lis_len;
	int	lis_used;
	int	len;
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

int		count_moves(int i, t_stack *stack);
int		cheapest_move(t_stack *stack);

void	sort_five(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_two(t_stack *stack);
void	lis_to_b(t_stack *stack);
void	sort_big(t_stack *stack);
int		find_max_b(t_stack *stack);

void	lis_finder(t_stack *stack);
void	push_new_lis_to_b(t_stack *stack);

#endif
