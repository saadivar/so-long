/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:30:20 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 21:04:23 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_win *win)
{
	int			h;
	int			w;
	t_player	*player;

	player = malloc(sizeof(t_player));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->height, win->width, "so_long");
	win->m_player = player;
	win->tower = mlx_xpm_file_to_image(win->mlx, "./Textures/tro.xpm", &h, &w);
	win->m_player->player = mlx_xpm_file_to_image(win->mlx,
			"./Textures/maroc.xpm", &h, &w);
	win->col = mlx_xpm_file_to_image(win->mlx, "./Textures/polisario.xpm",
			&h, &w);
	win->land = mlx_xpm_file_to_image(win->mlx, "./Textures/land.xpm", &h, &w);
	win->exit = mlx_xpm_file_to_image(win->mlx, "./Textures/spain.xpm", &h, &w);
	if (!win->col || !win->land || !win->exit
		|| !win->m_player->player || !win->tower)
	{
		ft_printf("Error\nwrong pic path");
		exit(1);
	}
}

void	readmap(t_win *win, char *av)
{
	int		fd;
	char	*line;

	fd = (open(av, O_RDONLY));
	if (fd < 0)
	{
		ft_printf("Error\nmap not found");
		exit(1);
	}
	win->all_lines = ft_calloc(1, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		win->all_lines = ft_strjoin(win->all_lines, line);
		free(line);
	}
}

int	end_program(t_win *win)
{
	(void)win;
	ft_printf("you end the game");
	exit(1);
	return (0);
}

void	checkallpaths(t_win *win)
{
	t_point	size;
	t_point	begin;

	size.x = win->lenx;
	size.y = win->lenw;
	begin.x = win->m_player->x;
	begin.y = win->m_player->y;
	flood_fill(win->check, size, begin);
	checkpath(win);
	floode(win->check, size, begin);
	checkexit(win);
}

int	main(int ac, char *av[])
{
	t_win	win;

	if (ac == 2)
	{
		checkext(av[1]);
		readmap(&win, av[1]);
		notf(&win);
		checknl(&win);
		lenw(&win, '\n');
		converttotabs(&win);
		checkrec(&win);
		init(&win);
		win.count = 0;
		win.movement = 0;
		checkperim(&win);
		posp(&win);
		nbrdata(&win);
		checkallpaths(&win);
		parse(&win);
		mlx_hook(win.win, 2, 0, key_hook, &win);
		mlx_hook(win.win, 17, 0l, end_program, &win);
		mlx_loop(win.mlx);
	}
	else
		return (ft_printf("Error\nwrong params"));
}
