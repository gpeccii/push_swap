/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:24 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 16:43:54 by gpecci           ###   ########.fr       */
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

int	checkone(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && (str[i] < 48 && str[i] > 57))
			return (0);
		i++;
	}
	return (1);
}

static int	dup_mine(int *check, int k, int i)
{
	int	j;

	while (++k < (i - 1))
	{
		j = k + 1;
		while (++j < i)
		{
			if (check[k] == check[j])
				return (0);
		}
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
		check[k] = ft_atoi(tmp[k]);
	k = -1;
	if (dup_mine(check, k, i) == 0)
		return (0);
	free(tmp);
	free(check);
	return (1);
}
