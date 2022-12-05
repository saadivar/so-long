/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:31:56 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 21:07:04 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(int x, int y, t_win *win)
{
	if (win->tab[y][x] == '1')
		return (0);
	return (1);
}

int	is_space(int x, int y, t_win *win)
{
	if (win->tab[y][x] == '0' || win->tab[y][x] == 'P')
		return (1);
	return (0);
}

int	is_collec(int x, int y, t_win *win)
{
	if (win->tab[y][x] == 'C')
		return (1);
	return (0);
}

int	is_exit(int x, int y, t_win *win)
{
	if (win->tab[y][x] == 'E')
		return (1);
	return (0);
}

int	checkrec(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < win->lenw)
	{
		x = 0;
		while (win->tab[y][x])
			x++;
		x -= 1;
		if (x != win->lenx)
		{
			ft_printf("not rect");
			exit(1);
		}
		y++;
	}
	return (0);
}
