/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:13:24 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/22 20:13:26 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alpha_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha(argv[i][j]) == 1)
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
	int	ret;

	i = 1;
	j = 0;
	ret = 1;
	tmp = ft_calloc (sizeof(int), (argc - 1));
	if (!tmp)
		return (0);
	while (argv[i])
		tmp[j++] = atoi(argv[i++]);
	i = -1;
	j = -1;
	while (tmp[++i])
	{
		while (tmp[++j])
		{
			if (tmp[i] == tmp[j] && i != j)
				ret = 0;
		}
	}
	free(tmp);
	return (ret);
}
