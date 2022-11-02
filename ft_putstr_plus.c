/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:08:27 by aharrass          #+#    #+#             */
/*   Updated: 2022/11/02 18:00:54 by aharrass         ###   ########.fr       */
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

int	put_unsigned(unsigned int n)
{
	if (n / 10 != 0)
	{
		ft_putnbr_len(n / 10);
		ft_putnbr_len(n % 10);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
	}
	return (unsigned_len(n));
}

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}
