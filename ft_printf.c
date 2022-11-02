/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:06:58 by aharrass          #+#    #+#             */
/*   Updated: 2022/11/02 17:58:22 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_check(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's'
			|| s[i + 1] == 'p' || s[i + 1] == 'd' || s[i + 1] == 'i'
			|| s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X'
			|| s[i + 1] == '%'))
		return (1);
	return (0);
}

static int	format_print(const char c, int count, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		count += ft_putchar_len(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr_len(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_len(va_arg(args, int));
	else if (c == '%')
		count += ft_putchar_len('%');
	else if (c == 'x')
		count += put_hex((unsigned int)va_arg(args, int), 'x');
	else if (c == 'X')
		count += put_hex((unsigned int)va_arg(args, int), 'X');
	else if (c == 'u')
		count += put_unsigned(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		count += ft_putstr_len("0x");
		count += put_hex((unsigned long)va_arg(args, void *), 'x');
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (!format_check(s + i))
		{
			ft_putchar_fd(s[i], 1);
			count++;
		}
		else
			count = format_print(s[++i], count, args);
		i++;
	}
	return (count);
}

// int main()
// {
// 	//char *s = "hello";
// 	// printf("%d\n", ft_printf("%%"));
// 	printf("\n%d", ft_printf("%p", LONG_MIN));
// }
