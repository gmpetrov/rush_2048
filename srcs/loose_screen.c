/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loose_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:04:14 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 22:01:39 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	loose_screen(t_env *e)
{
	int		c;

	e->is_menu = LOOSE_MENU;
	clear();
	mvwprintw(stdscr, (LINES / 2), (COLS / 2) - 5, \
		"You loose !");
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
