/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:24 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/04 14:16:17 by gpecci           ###   ########.fr       */
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
	int	*tmp;

	i = 0;
	tmp = malloc (sizeof(int) * (argc - 1));
	while (argv[++i])
	{
		tmp[i - 1] = ft_atoi(argv[i]);
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
		{
			free(tmp);
			return (0);
		}
	}
	i = 0;
	if (dup_mine(tmp, i, argc) == 0)
		return (0);
	return (1);
}

int	checkone(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && (str[i] < 48 || str[i] > 57))
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkdoubles_2(char *str)
{
	int		i;
	int		k;
	char	**tmp;
	int		*check;

	i = 0;
	tmp = ft_split(str, ' ');
	while (tmp[i])
		i++;
	check = malloc(sizeof(int) * i);
	k = -1;
	while (++k < i)
	{
		check[k] = ft_atoi(tmp[k]);
		if (ft_atoi(tmp[k]) > INT_MAX || ft_atoi(tmp[k]) < INT_MIN)
		{
			free(check);
			free_matrix(tmp);
			return (0);
		}
	}
	free_matrix(tmp);
	if (dup_mine(check, 0, i) == 0)
		return (0);
	return (1);
}
