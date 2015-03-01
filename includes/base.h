/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:28:21 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 17:16:39 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include "libft.h"
# include <ncurses.h>
# include <signal.h>
# include <menu.h>
# include <stdlib.h>

# define CHECK_MATE 42
# define GAME_STOPPED 0
# define MOVED 1
# define NOT_MOVED 0
# define WIN 1337

typedef enum	e_const
{
	WIN_VALUE = 2048
}				t_const;

typedef struct	s_env
{
	int			**game;
	int			width;
	int			height;
	int			last_x;
	int			last_y;
	int			grid_size;
	int			is_menu;
	WINDOW		*menu_win;
	MENU		*menu;
	ITEM		**items;
	int			score;
	WINDOW		***win_tab;
}				t_env;

int		error_win(void);
int		error(char *message);
void	print_game(t_env *env);
void	num_pop(int num, int x, int y);
void	mov_notif(int direction);
void	debug_map(t_env *env);
void	debug_game(t_env *env, int direction);
int		is_pow2(unsigned long x);
void	generate_rand_numb(t_env *env);
t_env	*getEnv(void);
t_env	*init_env(int grid_size);
int		init_game(t_env **e);
void	free_env(t_env **env);
int		move_numbers(t_env *env, int key);
int		move_up(t_env *env);
int		move_down(t_env *env);
int		move_left(t_env *env);
int		move_right(t_env *env);
void	resizeHandler(int signal);
void	initDisplay(void);
void	start_menu(void);
void	draw_menu(void);
void	quit(void);
void	print_in_middle(int starty, int startx, int width);
ITEM	**init_item(void);
void	play(void);
void	initPtrTab(t_env *e);
int		keyMap(int keycode);
void	init_win_tab(void);
void	refresh_win_tab(void);
void	draw_game(void);
void	print_numbers(void);

void	print_numbers_normal(t_env *e, int j, int i, char *nb);
void	print_numbers_ascii(t_env *e, int j, int i, int nb);
void	print_2(t_env *e, int j, int i);
void	print_4(t_env *e, int j, int i);
void	print_8(t_env *e, int j, int i);
void	print_16(t_env *e, int j, int i);
void	print_32(t_env *e, int j, int i);
void	print_64(t_env *e, int j, int i);
void	print_128(t_env *e, int j, int i);
void	print_256(t_env *e, int j, int i);
void	print_512(t_env *e, int j, int i);
void	print_1024(t_env *e, int j, int i);
void	loose_screen(void);
void	win_screen(void);

void	key_escape(void);

#endif
