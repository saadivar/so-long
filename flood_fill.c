/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:31:15 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 03:26:27 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	tab[begin.y][begin.x] = 'F';
	if (begin.y > 0 && (tab[begin.y - 1][begin.x] == '0' || tab[begin.y
			- 1][begin.x] == 'C'))
		goup(tab, size, begin);
	if ((begin.y < (size.y - 1)) && (tab[begin.y + 1][begin.x] == '0'
		|| tab[begin.y + 1][begin.x] == 'C'))
		godown(tab, size, begin);
	if ((begin.x < (size.x - 1)) && (tab[begin.y][begin.x + 1] == '0'
		|| tab[begin.y][begin.x + 1] == 'C'))
		goright(tab, size, begin);
	if (begin.x > 0 && (tab[begin.y][begin.x - 1] == '0' || tab[begin.y][begin.x
		- 1] == 'C'))
		goleft(tab, size, begin);
}

int	checkpath(t_win *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < win->lenw)
	{
		x = 0;
		while (win->check[y][x])
		{
			if (win->check[y][x] != 'F' && win->check[y][x] != '0'
				&& win->check[y][x] != '1' && win->check[y][x] != 'E')
			{
				ft_printf("Error\ninvalid path to a collectible");
				exit (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
