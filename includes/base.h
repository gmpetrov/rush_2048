/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:28:21 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 19:32:42 by gmp              ###   ########.fr       */
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

/* !!!!!! LOOK UP NORME FOR ENUM TYPEDEF  !!!!! */
typedef enum 	t_const
{
	WIN_VALUE = 2048
}				e_const;

typedef struct 	s_env
{
	int			**game;
	int			width;
	int 		height;
	int			last_x;
	int			last_y;
	int 		grid_size;
	int 		is_menu;
	WINDOW 		*menu_win;
	MENU 		*menu;
	ITEM 		**items;
	int 		score;
}				t_env;

/* STRUCTURES */


/* PROTOTYPES */

int		error_win(void);
int		error(char *message);
void	print_game(t_env *env);
void	num_pop(int num, int x, int y);
void	mov_notif(int direction);
void	debug_map(t_env *env);
void	debug_game(t_env *env, int direction);
int		is_pow2(unsigned long x);
void	generate_rand_numb(t_env *env);
// t_env	*getEnv(t_env *env);
t_env	*getEnv(void);
t_env	*init_env(int x, int y);
int		**init_game(int x, int y);
void	free_env(t_env **env);
int		move_numbers(t_env *env, int key);
int		move_up(t_env *env);
int		move_down(t_env *env);
int		move_left(t_env *env);
int		move_right(t_env *env);
void 	resizeHandler(int signal);
void	initDisplay(void);
void 	start_menu(void);
void 	draw_menu(void);
void 	quit(void);
void 	print_in_middle(int starty, int startx, int width);
ITEM 	**init_item(void);
void 	play(void);

/* KEYS */

void    key_escape(void);

/* END PROTOTYPES */

#endif
