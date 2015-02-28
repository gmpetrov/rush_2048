/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:18:50 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 18:18:57 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	draw_menu(void)
{
	t_env 	*e;

	e = getEnv();
	mvwin(e->menu_win, (LINES / 2) - 5, (COLS / 2) - 20);
	set_menu_win(e->menu, e->menu_win);
	set_menu_sub(e->menu, derwin(e->menu_win, 6, 38, 3, 1));
	set_menu_mark(e->menu, " * ");
	box(e->menu_win, 0, 0);
	print_in_middle(1, 0, 40);
	mvwaddch(e->menu_win, 5, 0, ACS_LTEE);
	mvwhline(e->menu_win, 2, 1, ACS_HLINE, 38);
	mvwaddch(e->menu_win, 2, 39, ACS_RTEE);
	mvprintw(LINES - 2, 0, "ENTER to select - ESC to Exit");
	refresh();
	post_menu(e->menu);
	wrefresh(e->menu_win);
}