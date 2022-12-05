/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:53:51 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 03:48:32 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveup(t_win *p)
{
	p->movement += 1;
	ft_printf("player moves :%d\n", p->movement);
	mlx_put_image_to_window(p->mlx, p->win, p->land, p->m_player->x * 100,
		p->m_player->y * 100);
	p->m_player->y--;
	mlx_put_image_to_window(p->mlx, p->win, p->m_player->player, p->m_player->x
		* 100, p->m_player->y * 100);
	p->tab[p->m_player->y][p->m_player->x] = 'P';
	p->tab[p->m_player->y + 1][p->m_player->x] = '0';
}

void	movedown(t_win *p)
{
	p->movement += 1;
	ft_printf("player moves :%d\n", p->movement);
	mlx_put_image_to_window(p->mlx, p->win, p->land, p->m_player->x * 100,
		p->m_player->y * 100);
	p->m_player->y++;
	mlx_put_image_to_window(p->mlx, p->win, p->m_player->player, p->m_player->x
		* 100, p->m_player->y * 100);
	p->tab[p->m_player->y][p->m_player->x] = 'P';
	p->tab[p->m_player->y - 1][p->m_player->x] = '0';
}

void	moveleft(t_win *p)
{
	p->movement += 1;
	ft_printf("player moves :%d\n", p->movement);
	mlx_put_image_to_window(p->mlx, p->win, p->land, p->m_player->x * 100,
		p->m_player->y * 100);
	p->m_player->x--;
	mlx_put_image_to_window(p->mlx, p->win, p->m_player->player, p->m_player->x
		* 100, p->m_player->y * 100);
	p->tab[p->m_player->y][p->m_player->x] = 'P';
	p->tab[p->m_player->y][p->m_player->x + 1] = '0';
}

void	moveright(t_win *p)
{
	p->movement += 1;
	ft_printf("player moves :%d\n", p->movement);
	mlx_put_image_to_window(p->mlx, p->win, p->land, p->m_player->x * 100,
		p->m_player->y * 100);
	p->m_player->x++;
	mlx_put_image_to_window(p->mlx, p->win, p->m_player->player, p->m_player->x
		* 100, p->m_player->y * 100);
	p->tab[p->m_player->y][p->m_player->x] = 'P';
	p->tab[p->m_player->y][p->m_player->x - 1] = '0';
}

int	notf(t_win *win)
{
	int	i;

	i = 0;
	while (win->all_lines[i])
	{
		if (win->all_lines[i] != '0' && win->all_lines[i] != '1'
			&& win->all_lines[i] != 'P' && win->all_lines[i] != 'C'
			&& win->all_lines[i] != 'E' && win->all_lines[i] != '\n')
		{
			ft_printf("Erorr\ninvalid map");
			exit(1);
		}
		i++;
	}
	return (0);
}
