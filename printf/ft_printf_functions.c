/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:45:39 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/04 03:22:54 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
		return (i);
	}
	else
		return (ft_putstr("(null)"));
}

int	nbr(long n, char *base)
{
	long	lenbase;
	int		len_n;

	len_n = 0;
	lenbase = ft_strlen(base);
	if (n < 0)
	{
		len_n++;
		ft_putchar('-');
		n = n * (-1);
	}
	if (n >= lenbase)
	{
		len_n += nbr(n / lenbase, base);
		len_n += nbr(n % lenbase, base);
	}
	else
		len_n += ft_putchar(base[n]);
	return (len_n);
}

int	adress(unsigned long n, char *base)
{
	unsigned long	lenbase;
	int				len_print;

	len_print = 0;
	lenbase = ft_strlen(base);
	if (n >= lenbase)
	{
		len_print += adress(n / lenbase, base);
		len_print += adress(n % lenbase, base);
	}
	else
		len_print += ft_putchar(base[n]);
	return (len_print);
}
