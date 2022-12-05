/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:57:30 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 04:09:06 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lenw(t_win *win, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (win->all_lines[i])
	{
		if (win->all_lines[i] == c && (win->all_lines[i] + 1 == c))
			return ;
		if (win->all_lines[i] == c)
			i++;
		else
		{
			count++;
			while (win->all_lines[i] && win->all_lines[i] != c)
				i++;
		}
	}
	win->lenw = count;
}

int	nbrdata(t_win *win)
{
	if (win->nbp > 1)
	{
		ft_printf("Error\nmore than one player");
		exit(1);
	}
	if (win->nbp == 0 || win->nbe == 0 || win->nbc == 0)
	{
		ft_printf("Error\nsomething is missing");
		exit(1);
	}
	if (win->nbe > 1)
	{
		ft_printf("Error\nmore than one exit");
		exit(1);
	}
	return (0);
}

int	converttotabs(t_win *win)
{
	win->tab = ft_split(win->all_lines, '\n');
	win->check = ft_split(win->all_lines, '\n');
	win->lenx = ft_strlen(win->tab[0]) - 1;
	win->height = ft_strlen(win->tab[0]) * 100;
	win->width = win->lenw * 100;
	return (0);
}

void	posp(t_win *win)
{
	int	y;
	int	x;

	y = 0;
	while (y < win->lenw)
	{
		x = 0;
		while (win->tab[y][x])
		{
			if (win->tab[y][x] == 'P')
			{
				win->m_player->x = x;
				win->m_player->y = y;
				win->nbp += 1;
			}
			else if (win->tab[y][x] == 'E')
				win->nbe += 1;
			else if (win->tab[y][x] == 'C')
				win->nbc += 1;
			x++;
		}
		y++;
	}
}

int	checknl(t_win *win)
{
	int	i;

	i = 0;
	while (win->all_lines[i])
	{
		if (win->all_lines[i] == '\n' && win->all_lines[i + 1] == '\n' )
		{
			ft_printf("Error\ninvalid map");
			exit(1);
		}
		i++;
	}
	i = 0;
	if (win->all_lines[i] == '\0')
	{
		ft_printf("Error\nmap empty");
		exit(1);
	}
	i = 0;
	if (win->all_lines[i] == '\n')
	{
		ft_printf("Error\ninvalid map");
		exit(1);
	}
	return (0);
}
