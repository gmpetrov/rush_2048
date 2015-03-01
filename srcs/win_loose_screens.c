/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_loose_screens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:04:58 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 18:05:26 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	loose_screen(void)
{
	t_env	*e;
	int		c;

	e = get_env();
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
			quit();
	}
}

void	win_screen(void)
{
	t_env	*e;
	int		c;

	e = get_env();
	clear();
	mvwprintw(stdscr, (LINES / 2), (COLS / 2) - 5, \
		"You win !");	
	mvwprintw(stdscr, (LINES / 2) - 5 + 12, \
		(COLS / 2) - 10, "Your score : %d", e->score);
	mvwprintw(stdscr, LINES - 2, 2, "%s", "Press escape to quit");
	refresh();
	while (42)
	{
		c = getch();
		if (c == 27)
			quit();
	}
}