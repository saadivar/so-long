/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:12:46 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 03:32:26 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	land(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	win->width = 0;
	while (y < win->lenw)
	{
		x = 0;
		win->height = 0;
		while (win->tab[y][x] != '\0')
		{
			mlx_put_image_to_window(win->mlx, win->win, win->land, win->height,
				win->width);
			win->height += 100;
			x++;
		}
		y++;
		win->width += 100;
	}
}

void	collect(t_win *win)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_put_image_to_window(win->mlx, win->win, win->col, win->height,
		win->width);
	win->count += 1;
	win->height += 100;
}

void	personnage(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->m_player->player,
		win->height, win->width);
	win->height += 100;
	win->m_player->x = win->x;
	win->m_player->y = win->y;
}

void	ex(t_win *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->exit, win->height,
		win->width);
	win->height += 100;
}

void	parse(t_win *win)
{
	win->x = 0;
	win->y = 0;
	land(win);
	win->width = 0;
	while (win->y < win->lenw)
	{
		win->x = 0;
		win->height = 0;
		while (win->tab[win->y][win->x] != '\0')
		{
			if (win->tab[win->y][win->x] == '1')
				tower(win);
			else if (win->tab[win->y][win->x] == '0')
				win->height += 100;
			else if (win->tab[win->y][win->x] == 'C')
				collect(win);
			else if (win->tab[win->y][win->x] == 'P')
				personnage(win);
			else if (win->tab[win->y][win->x] == 'E')
				ex(win);
			win->x++;
		}
		win->width += 100;
		win->y++;
	}
}
