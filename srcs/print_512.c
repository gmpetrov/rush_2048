/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:11:29 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 20:25:34 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_512(t_env *e, int j, int i)
{
	wattron(e->win_tab[j][i], COLOR_PAIR(4));
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 1, \
		((e->width / e->grid_size) / 2) - 12, "                         ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 2, \
		((e->width / e->grid_size) / 2) - 12, " _|_|_|_|    _|    _|_|  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 3, \
		((e->width / e->grid_size) / 2) - 12, " _|        _|_|  _|    _|");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 4, \
		((e->width / e->grid_size) / 2) - 12, " _|_|_|      _|      _|  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 5, \
		((e->width / e->grid_size) / 2) - 12, "       _|    _|    _|    ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 6, \
		((e->width / e->grid_size) / 2) - 12, " _|_|_|      _|  _|_|_|_|");
}
