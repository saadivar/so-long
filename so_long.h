/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-biyy <sel-biyy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 03:27:59 by sel-biyy          #+#    #+#             */
/*   Updated: 2022/12/05 03:49:28 by sel-biyy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;
typedef struct player
{
	int				x;
	int				y;
	void			*player;

}					t_player;
typedef struct window
{
	void			*mlx;
	void			*win;
	void			*col;
	void			*tower;
	void			*land;
	void			*exit;
	struct player	*m_player;
	int				width;
	int				height;
	char			**tab;
	char			**check;
	int				count;
	int				movement;
	char			*all_lines;
	int				lenw;
	int				lenx;
	int				nbp;
	int				nbe;
	int				nbc;
	int				x;
	int				y;
}					t_win;
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

char				*get_next_line(int fd);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
void				*ft_calloc(size_t count, size_t size);
char				**ft_split(char const *s, char c);
int					ft_printf(const char *s, ...);
int					ft_putchar(char c);
int					ft_putstr(char *s);
int					nbr(long nb, char *base);
int					adress(unsigned long nbr, char *base);
int					printing_format(char c, va_list argsptr);
void				flood_fill(char **tab, t_point size, t_point begin);
void				floode(char **tab, t_point size, t_point begin);
int					checkpath(t_win *win);
int					checkexit(t_win *win);
int					is_exit(int x, int y, t_win *win);
int					is_collec(int x, int y, t_win *win);
int					is_space(int x, int y, t_win *win);
int					is_wall(int x, int y, t_win *win);
int					checkext(char *av);
int					checkperim(t_win *win);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				init(t_win *win);
void				parse(t_win *win);
void				moveup(t_win *p);
void				movedown(t_win *p);
void				moveleft(t_win *p);
void				moveright(t_win *p);
int					key_hook(int keycode, t_win *p);
void				goup(char **tab, t_point size, t_point begin);
void				godown(char **tab, t_point size, t_point begin);
void				goleft(char **tab, t_point size, t_point begin);
void				goright(char **tab, t_point size, t_point begin);
void				lenw(t_win *win, char c);
int					nbrdata(t_win *win);
int					converttotabs(t_win *win);
void				posp(t_win *win);
int					checknl(t_win *win);
void				tower(t_win *win);
int				checkrec(t_win *win);
int					notf(t_win *win);
#endif
