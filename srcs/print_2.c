/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:09:32 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 20:19:44 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_2(t_env *e, int j, int i)
{
	wattron(e->win_tab[j][i], COLOR_PAIR(2));
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 1, \
		((e->width / e->grid_size) / 2) - 5, "  ______  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 2, \
		((e->width / e->grid_size) / 2) - 5, " /      \\ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 3, \
		((e->width / e->grid_size) / 2) - 5, "/$$$$$$  |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 4, \
		((e->width / e->grid_size) / 2) - 5, "$$____$$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 5, \
		((e->width / e->grid_size) / 2) - 5, " /    $$/ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 6, \
		((e->width / e->grid_size) / 2) - 5, "/$$$$$$/  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 7, \
		((e->width / e->grid_size) / 2) - 5, "$$ |_____ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 8, \
		((e->width / e->grid_size) / 2) - 5, "$$       |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 9, \
		((e->width / e->grid_size) / 2) - 5, "$$$$$$$$/ ");
}
