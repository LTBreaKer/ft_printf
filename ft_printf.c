/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:06:58 by aharrass          #+#    #+#             */
/*   Updated: 2022/10/30 21:49:56 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_check(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == '%' && (s[i + 1] == 'c' || s[i + 1] == 's'
      || s[i + 1] == 'p' || s[i + 1] == 'd'|| s[i + 1] == 'i'
			|| s[i + 1] == 'u' || s[i + 1] == 'x' || s[i + 1] == 'X'
			|| s[i + 1] == '%'))
    return (1);
  return (0);
}

static int	format_print(const char c, int count, va_list args)
{
	int i;

	i = 0;
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		count++;
	}
	if (c == 's')
	{
		count += ft_putstr_len(va_arg(args, char *));
	}
	if (c == 'd' || c == 'i')
		count += ft_putnbr_len(va_arg(args, int));
		//printf("count:%d\n", count);
	return(count);
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
// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_printf(" %c ", '0'));
// 	//ft_printf("%s", (char *)NULL);
// }