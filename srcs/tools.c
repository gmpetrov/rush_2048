/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:58:37 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 22:24:41 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	quit(void)
{
	nocbreak();
	echo();
    curs_set(1);
    endwin();
	exit(0);
}

void 	resizeHandler(int sig)
{
	t_env 	*e;

	(void)sig;
	e = getEnv();
    endwin();
    refresh();
    clear();
    e = getEnv();
    e->width = COLS;
    e->height = LINES;
    mvprintw(0, 0, "COLS = %d, LINES = %d", e->width, e->height);
    if (e->is_menu == 1)
    	draw_menu();
    else if (e->is_menu == -42){
        clear();
        draw_game();
        refresh_win_tab();
    }
}

void    initPtrTab(t_env *e)
{
    e->tab[0] = &key_escape;
}

int     keyMap(int keycode)
{
    if (27 == keycode)
        return 0;
    return -1;
}

void    key_escape(void)
{
    quit();
}