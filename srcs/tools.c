/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:58:37 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 18:19:10 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	quit(void)
{
	nocbreak();
	echo();
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
}