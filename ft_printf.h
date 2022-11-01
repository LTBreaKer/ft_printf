/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:07:02 by aharrass          #+#    #+#             */
/*   Updated: 2022/11/01 18:25:48 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include "limits.h"
# include <stdio.h>

int	ft_printf(const char *s, ...);
int	ft_putstr_len(const char *s);
int	ft_putnbr_len(int n);
int	put_hex(unsigned int n, const char c);
int	put_unsigned(int n);
#endif
