/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:37:07 by aharrass          #+#    #+#             */
/*   Updated: 2022/10/30 21:47:58 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_putstr_len(const char *s)
{
	int	i;
	
	i = 0;
	if (!s)
	{
		ft_putstr_len("(null)");
		return (6);
	}
	while(s[i])
		ft_putchar_fd(s[i++], 1);
	return (i);
}

static int	int_len(long n)
{
	int	len;
	int	buff;

	len = 1;
	if (n >= 0)
		buff = n;
	else
	{
		len++;
		buff = -n;
	}
	while (buff > 9)
	{
		buff /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_len(int n)
{
	if (n == -2147483648)
	{
		return(ft_putstr_len("-2147483648"));
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_len(-n);
	}
	else if (n / 10 != 0)
	{
		ft_putnbr_len(n / 10);
		ft_putnbr_len(n % 10);
	}
	else
	{
		ft_putchar_fd(n + '0', 1);
	}
	return (int_len((long) n));
}