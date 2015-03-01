/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:04:17 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 22:25:28 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	win_screen(t_env *e)
{
	int		c;

	e->is_menu = WIN_MENU;
	e->won = 1;
	clear();
	mvwprintw(stdscr, (LINES / 2), (COLS / 2) - 5, "You win !");
	mvwprintw(stdscr, (LINES / 2) - 5 + 12, \
		(COLS / 2) - 10, "Your score : %d", e->score);
	mvwprintw(stdscr, LINES - 2, 2, "%s", "Press escape to return");
	refresh();
	while (42)
	{
		c = getch();
		if (c == 27)
			break ;
	}
	e->is_menu = 1;
}
