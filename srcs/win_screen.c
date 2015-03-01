/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:04:17 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 22:05:15 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	win_screen(t_env *e)
{
	int		c;

	e->is_menu = WIN_MENU;
	clear();
	mvwprintw(stdscr, (LINES / 2), (COLS / 2) - 5, "You win !");
	mvwprintw(stdscr, (LINES / 2) - 5 + 12, \
		(COLS / 2) - 10, "Your score : %d", e->score);
	mvwprintw(stdscr, LINES - 2, 2, "%s", "Press escape to quit");
	refresh();
	while (42)
	{
		c = getch();
		if (c == 27)
			quit(e);
	}
}
