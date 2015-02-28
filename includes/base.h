/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 10:28:21 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 17:53:32 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include "libft.h"
# include <curses.h>
# include <signal.h>
# include <menu.h>

/* !!!!!! LOOK UP NORME FOR ENUM TYPEDEF  !!!!! */
typedef enum 	t_const
{
	WIN_VALUE = 2048
}				e_const;

typedef struct 	s_env
{
	int			width;
	int 		height;
	int 		grid_size;
	int 		is_menu;
	WINDOW 		*menu_win;
	MENU 		*menu;
	ITEM 		**items;
}				t_env;


/* STRUCTURES */


/* PROTOTYPES */

t_env	*getEnv(void);
void 	resizeHandler(int signal);
void	initDisplay(void);
void 	start_menu(void);
void 	draw_menu(void);
void 	quit(void);
void 	print_in_middle(int starty, int startx, int width);
ITEM 	**init_item(void);

/* END PROTOTYPES */

#endif