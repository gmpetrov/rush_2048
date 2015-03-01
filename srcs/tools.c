/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:58:37 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 17:11:41 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	quit(void)
{
	t_env *e;

	e = get_env();
	free_env(&e);
	nocbreak();
	echo();
    curs_set(1);
    endwin();
	exit(0);
}

void 	resize_handler(int sig)
{
	t_env 	*e;

	(void)sig;
	e = get_env();
    endwin();
    refresh();
    clear();
    e = get_env();
    e->width = COLS;
    e->height = LINES;
    mvprintw(0, 0, "COLS = %d, LINES = %d", e->width, e->height);
    if (e->is_menu == 1)
    	draw_menu();
    else if (e->is_menu == -42)
    {
        clear();
        draw_game();
        refresh_win_tab();
    }
}
