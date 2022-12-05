/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:59:21 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/04 03:22:56 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	printing_format(char c, va_list argsptr)
{
	int	count;

	count = 0;
	if (c == 'C')
		count = ft_putchar(va_arg(argsptr, int));
	else if (c == 's')
		count = ft_putstr(va_arg(argsptr, char *));
	else if (c == 'P')
	{
		count = ft_putstr("0x");
		count += adress((unsigned long)va_arg(argsptr, void *),
				"0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		count += nbr(va_arg(argsptr, int), "0123456789");
	else if (c == 'u')
		count += nbr(va_arg(argsptr, unsigned int), "0123456789");
	else if (c == 'x')
		count += nbr(va_arg(argsptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += nbr(va_arg(argsptr, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	argsptr;
	int		count;

	va_start(argsptr, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			count += printing_format(*s, argsptr);
		}
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(argsptr);
	return (count);
}
