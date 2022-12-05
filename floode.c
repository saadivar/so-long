/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:31:21 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 02:47:32 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floode(char **tab, t_point size, t_point begin)
{
	tab[begin.y][begin.x] = 'X';
	if (begin.y > 0 && ((tab[begin.y - 1][begin.x] == 'E') || (tab[begin.y
				- 1][begin.x] == 'F')))
		goup(tab, size, begin);
	if ((begin.y < (size.y - 1)) && ((tab[begin.y + 1][begin.x] == 'E')
		|| (tab[begin.y + 1][begin.x] == 'F')))
		godown(tab, size, begin);
	if (begin.x < (size.x - 1) && (tab[begin.y][begin.x + 1] == 'E'
		|| tab[begin.y][begin.x + 1] == 'F'))
		goright(tab, size, begin);
	if (begin.x > 0 && ((tab[begin.y][begin.x - 1] == 'E')
		|| (tab[begin.y][begin.x - 1] == 'F')))
		goleft(tab, size, begin);
}

int	checkexit(t_win *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < win->lenw)
	{
		x = 0;
		while (win->check[y][x])
		{
			if (win->check[y][x] != 'X' && win->check[y][x] != '0'
				&& win->check[y][x] != '1')
			{
				ft_printf("Error\ninvalid PATH to exit");
				exit (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	tower(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->tower, win->height,
		win->width);
	win->height += 100;
}
