/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:45:15 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/04 18:40:42 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

void	exit_error_check(t_stack *stack);
void	other_or_error(t_stack *stack, char *str);
void	ft_checker(t_stack *stack, char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
