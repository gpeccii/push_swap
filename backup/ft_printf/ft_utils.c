/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:12:58 by gpecci            #+#    #+#             */
/*   Updated: 2023/03/08 18:19:39 by gpecci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s)
{
	int	len;

	len = 0;
	while (!s)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (*s)
	{
		len += ft_putchar(*s);
		s++;
	}
	return (len);
}
