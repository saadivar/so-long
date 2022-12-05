/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:32:52 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 03:43:33 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	errtop(void)
{
	ft_printf("Error\ninvalid map");
	exit(1);
}

int	errbot(void)
{
	ft_printf("Error\ninvalid map");
	exit(1);
}

int	perimerr(void)
{
	ft_printf("Error\ninvalid map");
	exit(1);
}

int	checkperim(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	while (win->tab[0][x])
	{
		if (win->tab[0][x] != '1')
			errtop();
		x++;
	}
	x = 0;
	while (win->tab[win->lenw - 1][x])
	{
		if (win->tab[win->lenw - 1][x] != '1')
			errbot();
		x++;
	}
	y = 0;
	while (y < win->lenw)
	{
		if (win->tab[y][0] != '1' || win->tab[y][win->lenx] != '1')
			perimerr();
		y++;
	}
	return (0);
}

int	checkext(char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	i -= 1;
	if (av[i] != 'r' || av[i - 1] != 'e' || av[i - 2] != 'b' || av[i
			- 3] != '.')
	{
		ft_printf("Error\nwrong extension");
		exit(1);
	}
	return (0);
}
