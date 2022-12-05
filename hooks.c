/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:29:13 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/04 20:54:00 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wkey(t_win *p)
{
	if (is_wall(p->m_player->x, p->m_player->y - 1, p))
	{
		if (is_space(p->m_player->x, p->m_player->y - 1, p))
			moveup(p);
		else if (is_collec(p->m_player->x, p->m_player->y - 1, p))
		{
			moveup(p);
			p->count -= 1;
		}
		else if (is_exit(p->m_player->x, p->m_player->y - 1, p)
			&& p->count == 0)
		{
			p->movement += 1;
			ft_printf("player moves :%d\n", p->movement);
			mlx_destroy_window(p->mlx, p->win);
			ft_printf("congrats");
			exit(1);
		}
	}
	return (0);
}

int	skey(t_win *p)
{
	if (is_wall(p->m_player->x, p->m_player->y + 1, p))
	{
		if (is_space(p->m_player->x, p->m_player->y + 1, p))
			movedown(p);
		else if (is_collec(p->m_player->x, p->m_player->y + 1, p))
		{
			movedown(p);
			p->count -= 1;
		}
		else if (is_exit(p->m_player->x, p->m_player->y + 1, p)
			&& p->count == 0)
		{
			p->movement += 1;
			ft_printf("player moves :%d\n", p->movement);
			mlx_destroy_window(p->mlx, p->win);
			ft_printf("congrats");
			exit(1);
		}
	}
	return (0);
}

int	akey(t_win *p)
{
	if (is_wall(p->m_player->x - 1, p->m_player->y, p))
	{
		if (is_space(p->m_player->x - 1, p->m_player->y, p))
			moveleft(p);
		else if (is_collec(p->m_player->x - 1, p->m_player->y, p))
		{
			moveleft(p);
			p->count -= 1;
		}
		else if (is_exit(p->m_player->x - 1, p->m_player->y, p)
			&& p->count == 0)
		{
			p->movement += 1;
			ft_printf("player moves :%d\n", p->movement);
			mlx_destroy_window(p->mlx, p->win);
			ft_printf("congrats");
			exit(1);
		}
	}
	return (0);
}

int	dkey(t_win *p)
{
	if (is_wall(p->m_player->x + 1, p->m_player->y, p))
	{
		if (is_space(p->m_player->x + 1, p->m_player->y, p))
			moveright(p);
		else if (is_collec(p->m_player->x + 1, p->m_player->y, p))
		{
			moveright(p);
			p->count -= 1;
		}
		else if (is_exit(p->m_player->x + 1, p->m_player->y, p)
			&& p->count == 0)
		{
			p->movement += 1;
			ft_printf("player moves :%d\n", p->movement);
			mlx_destroy_window(p->mlx, p->win);
			ft_printf("congrats");
			exit(1);
		}
	}
	return (0);
}

int	key_hook(int keycode, t_win *p)
{
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx, p->win);
		ft_printf("you end the game");
		exit(1);
	}
	else if (keycode == 13)
		wkey(p);
	else if (keycode == 1)
		skey(p);
	else if (keycode == 0)
		akey(p);
	else if (keycode == 2)
		dkey(p);
	return (0);
}
