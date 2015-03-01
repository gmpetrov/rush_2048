/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_loose_screens.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 16:04:58 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 17:38:04 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_loose(int y, int x);
void	print_win(int y, int x);

void	loose_screen(void)
{
	t_env	*e;
	int		c;

	e = get_env();
	clear();
	print_loose((LINES / 2), (COLS / 2) - 40);
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
	print_win((LINES / 2), (COLS / 2) - 40);
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

void	print_win(int y, int x)
{
	mvwprintw(stdscr, y - 13, x, " __      __                         \
	__       __  __                  __ ");
	mvwprintw(stdscr, y - 12, x, "/  \\    /  |                       \
	/  |  _  /  |/  |                /  |");
	mvwprintw(stdscr, y - 11, x, "$$  \\  /$$/______   __    __      \
	$$ | / \\ $$ |$$/  _______        $$ |");
	mvwprintw(stdscr, y - 10, x, " $$  \\/$$//      \\ /  |  /  |    \
	$$ |/$  \\$$ |/  |/       \\       $$ |");
	mvwprintw(stdscr, y - 9, x, "  $$  $$//$$$$$$  |$$ |  $$ |      \
	$$ /$$$  $$ |$$ |$$$$$$$  |      $$ |");
	mvwprintw(stdscr, y - 8, x, "   $$$$/ $$ |  $$ |$$ |  $$ |      \
	$$ $$/$$ $$ |$$ |$$ |  $$ |      $$/ ");
	mvwprintw(stdscr, y - 7, x, "    $$ | $$ \\__$$ |$$ \\__$$ |    \
	$$$$/  $$$$ |$$ |$$ |  $$ |       __ ");
	mvwprintw(stdscr, y - 6, x, "    $$ | $$    $$/ $$    $$/       \
	$$$/    $$$ |$$ |$$ |  $$ |      /  |");
	mvwprintw(stdscr, y - 5, x, "    $$/   $$$$$$/   $$$$$$/        \
	$$/      $$/ $$/ $$/   $$/       $$/ ");
}

void	print_loose(int y, int x)
{
	mvwprintw(stdscr, y - 5, x, " __      __                         \
	__                                               ");
	mvwprintw(stdscr, y - 4, x, "/  \\    /  |                      \
	/  |                                              ");
	mvwprintw(stdscr, y - 3, x, "$$  \\  /$$/______   __    __      \
	$$ |        ______    ______    _______   ______  ");
	mvwprintw(stdscr, y - 2, x, " $$  \\/$$//      \\ /  |  /  |    \
	$$ |       /      \\  /      \\  /       | /      \\ ");
	mvwprintw(stdscr, y - 1, x, "  $$  $$//$$$$$$  |$$ |  $$ |      \
	$$ |      /$$$$$$  |/$$$$$$  |/$$$$$$$/ /$$$$$$  |");
	mvwprintw(stdscr, y - 0, x, "   $$$$/ $$ |  $$ |$$ |  $$ |      \
	$$ |      $$ |  $$ |$$ |  $$ |$$      \\ $$    $$ |");
	mvwprintw(stdscr, y + 1, x, "    $$ | $$ \\__$$ |$$ \\__$$ |    \
	$$ |_____ $$ \\__$$ |$$ \\__$$ | $$$$$$  |$$$$$$$$/ ");
	mvwprintw(stdscr, y + 2, x, "    $$ | $$    $$/ $$    $$/       \
	$$       |$$    $$/ $$    $$/ /     $$/ $$       |");
	mvwprintw(stdscr, y + 3, x, "    $$/   $$$$$$/   $$$$$$/        \
	$$$$$$$$/  $$$$$$/   $$$$$$/  $$$$$$$/   $$$$$$$/ ");
}
