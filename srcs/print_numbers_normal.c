/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:07:51 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 22:38:28 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void	color_number(t_env *e, int j, int i)
{
	if (e->game[j][i] == 2)
		wattron(e->win_tab[j][i], COLOR_PAIR(2));
	else if (e->game[j][i] == 4)
		wattron(e->win_tab[j][i], COLOR_PAIR(1));
	else if (e->game[j][i] == 8)
		wattron(e->win_tab[j][i], COLOR_PAIR(4));
	else if (e->game[j][i] == 16)
		wattron(e->win_tab[j][i], COLOR_PAIR(5));
	else if (e->game[j][i] == 32)
		wattron(e->win_tab[j][i], COLOR_PAIR(6));
	else if (e->game[j][i] == 64)
		wattron(e->win_tab[j][i], COLOR_PAIR(7));
	else if (e->game[j][i] == 128)
		wattron(e->win_tab[j][i], COLOR_PAIR(1));
	else if (e->game[j][i] == 256)
		wattron(e->win_tab[j][i], COLOR_PAIR(2));
	else if (e->game[j][i] == 512)
		wattron(e->win_tab[j][i], COLOR_PAIR(4));
	else if (e->game[j][i] == 1024)
		wattron(e->win_tab[j][i], COLOR_PAIR(5));
	else if (e->game[j][i] == 2048)
		wattron(e->win_tab[j][i], COLOR_PAIR(1));
}

void		print_numbers_normal(t_env *e, int j, int i, char *nb)
{
	if (e->game[j][i] == 0)
		mvwprintw(e->win_tab[j][i], (e->height / e->grid_size) / 2, \
			(e->width / e->grid_size) / 2, "");
	else
	{
		color_number(e, j, i);
		mvwprintw(e->win_tab[j][i], (e->height / e->grid_size) / 2, \
			(e->width / e->grid_size) / 2, nb);
	}
}
