/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:59:35 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:37:58 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void	draw_loose_screen(void)
{
	t_env	*e;

	e = get_env();	
	clear();
	mvwprintw(stdscr, (LINES / 2), (COLS / 2) - 5, \
		"You loose !");
	mvwprintw(stdscr, (LINES / 2) - 5 + 12, \
		(COLS / 2) - 10, "Your score : %d", e->score);
	mvwprintw(stdscr, LINES - 2, 2, "%s", "Press escape to quit");
	refresh();
}

static void	draw_win_screen(void)
{
	t_env	*e;

	e = get_env();
	clear();
	mvwprintw(stdscr, (LINES / 2), (COLS / 2) - 5, "You win !");
	mvwprintw(stdscr, (LINES / 2) - 5 + 12,\
		(COLS / 2) - 10, "Your score : %d", e->score);
	mvwprintw(stdscr, LINES - 2, 2, "%s", "Press escape to quit");
	refresh();
}

static void	choose_menu(t_env *e)
{
	if (e->is_menu == 1)
		draw_menu();
	else if (e->is_menu == WIN_MENU)
		draw_win_screen();
	else if (e->is_menu == LOOSE_MENU)
		draw_loose_screen();
	else if (e->is_menu == -42)
	{
		clear();
		draw_game();
		refresh_win_tab();
	}
}

void		resize_handler(int sig)
{
	t_env	*e;

	(void)sig;
	e = get_env();
	endwin();
	refresh();
	clear();
	e = get_env();
	e->width = COLS;
	e->height = LINES;
	choose_menu(e);
}
