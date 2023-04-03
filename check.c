/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:24 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 13:22:57 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_checkdoubles(char **argv, int argc)
{
	int	i;
	int	j;
	int	*tmp;

	i = 1;
	j = 0;
	tmp = malloc (sizeof(int) * (argc - 1));
	if (!tmp)
		return (0);
	while (argv[i])
		tmp[j++] = atoi(argv[i++]);
	i = -1;
	j = 0;
	while (i < (argc - 1))
	{
		while (j < (argc - 1))
		{
			if (tmp[i] == tmp[j])
				return (0);
			j++;
		}
		i++;
	}
	free(tmp);
	return (1);
}
