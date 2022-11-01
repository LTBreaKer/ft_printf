/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:08:27 by aharrass          #+#    #+#             */
/*   Updated: 2022/11/01 18:26:18 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_len(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	put_unsigned(int n)
{
	unsigned int	l;

	l = (unsigned int) n;
	if (l / 10 != 0)
	{
		ft_putnbr_len(l / 10);
		ft_putnbr_len(l % 10);
	}
	else
	{
		ft_putchar_fd(l + '0', 1);
	}
	return (unsigned_len(l));
}
