/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_64.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:11:21 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 20:23:44 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_64(t_env *e, int j, int i)
{
	wattron(e->win_tab[j][i], COLOR_PAIR(7));
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 1, \
		((e->width / e->grid_size) / 2) - 8, "  ______   __    __ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 2, \
		((e->width / e->grid_size) / 2) - 8, " /      \\ /  |  /  |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 3, \
		((e->width / e->grid_size) / 2) - 8, "/$$$$$$  |$$ |  $$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 4, \
		((e->width / e->grid_size) / 2) - 8, "$$ \\__$$/ $$ |__$$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 5, \
		((e->width / e->grid_size) / 2) - 8, "$$      \\ $$    $$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 6, \
		((e->width / e->grid_size) / 2) - 8, "$$$$$$$  |$$$$$$$$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 7, \
		((e->width / e->grid_size) / 2) - 8, "$$ \\__$$ |      $$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 8, \
		((e->width / e->grid_size) / 2) - 8, "$$    $$/       $$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 9, \
		((e->width / e->grid_size) / 2) - 8, " $$$$$$/        $$/ ");
}
