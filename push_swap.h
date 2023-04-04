/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:52 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/04 14:14:02 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	last_a;
	int	last_b;
	int	n_moves;
	int	index_to;
	int	index_min;
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

int		number_check(char **argv);
int		ft_checkdoubles(char **argv, int argc);
int		checkone(char *str);
int		ft_checkdoubles_2(char *str);
int		dup_mine(int *check, int k, int i);
void	free_matrix(char **matrix);

int		count_moves(int i, t_stack *stack);
int		cheapest_move(t_stack *stack);

void	comb1_1(t_stack *stack, int i, int j);
void	comb1_2(t_stack *stack, int i, int j);
void	comb2(t_stack *stack, int i, int j);
void	comb3(t_stack *stack, int i, int j);
void	comb4_1(t_stack *stack, int i, int j);
void	comb4_2(t_stack *stack, int i, int j);

int		max_to_insert(t_stack *stack, int i, int j, int max);
int		min_to_insert(t_stack *stack, int i, int j, int min);
int		middle_insert(t_stack *stack, int i, int j);

int		ft_sorted(t_stack *stack);

void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack);
void	sort_big(t_stack *stack);
int		find_index_min_b(t_stack *stack);
int		find_index_max_b(t_stack *stack);
int		find_index_min_a(t_stack *stack);
int		find_index_max_a(t_stack *stack);

#endif
