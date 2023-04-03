/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:24 by gpecci            #+#    #+#             */
/*   Updated: 2023/04/03 14:20:44 by gpecci           ###   ########.fr       */
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
		if (str[i] != 32 || (str[i] < 48 && str[i] > 57))
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkdoubles_2(char *argv)
{
	int		i;
	int		j;
	char	**tmp;
	int		*check;

	i = -1;
	tmp = ft_split(argv, ' ');
	while (tmp[++i])
	check = malloc (sizeof(int) * i);
	i = -1;
	while (tmp[++i])
		check[i] = ft_atoi(tmp[i]);
	i = -1;
	j = 0;
	while (check[++i])
	{
		while (check[++j])
			if (check[i] == check[j])
				return (0);
	}
	free(tmp);
	free(check);
	return (1);
}
