/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:59:35 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:20:21 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void	choose_menu(t_env *e)
{
	if (e->is_menu == 1)
		draw_menu();
	else if (e->is_menu == WIN_MENU)
		win_screen();
	else if (e->is_menu == LOOSE_MENU)
		loose_screen();
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
	mvprintw(0, 0, "COLS = %d, LINES = %d", e->width, e->height);
	choose_menu(e);
}
