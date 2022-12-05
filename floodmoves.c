/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodmoves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 21:20:15 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 02:19:03 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	goup(char **tab, t_point size, t_point begin)
{
	t_point	p;

	p.x = begin.x;
	p.y = begin.y - 1;
	if (tab[begin.y][begin.x] == 'F')
		flood_fill(tab, size, p);
	else
		floode(tab, size, p);
}

void	godown(char **tab, t_point size, t_point begin)
{
	t_point	p;

	p.x = begin.x;
	p.y = begin.y + 1;
	if (tab[begin.y][begin.x] == 'F')
		flood_fill(tab, size, p);
	else
		floode(tab, size, p);
}

void	goleft(char **tab, t_point size, t_point begin)
{
	t_point	p;

	p.x = begin.x - 1;
	p.y = begin.y;
	if (tab[begin.y][begin.x] == 'F')
		flood_fill(tab, size, p);
	else
		floode(tab, size, p);
}

void	goright(char **tab, t_point size, t_point begin)
{
	t_point	p;

	p.x = begin.x + 1;
	p.y = begin.y;
	if (tab[begin.y][begin.x] == 'F')
		flood_fill(tab, size, p);
	else
		floode(tab, size, p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	if (!s)
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!(p))
		return (NULL);
	while (s[start + i] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
