/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_64_128_256_512.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:22:12 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 17:29:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_64(t_env *e, int j, int i)
{
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

void	print_128(t_env *e, int j, int i)
{
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 1, \
		((e->width / e->grid_size) / 2) - 12, "                         ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 2, \
		((e->width / e->grid_size) / 2) - 12, "   _|    _|_|      _|_|  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 3, \
		((e->width / e->grid_size) / 2) - 12, " _|_|  _|    _|  _|    _|");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 4, \
		((e->width / e->grid_size) / 2) - 12, "   _|      _|      _|_|  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 5, \
		((e->width / e->grid_size) / 2) - 12, "   _|    _|      _|    _|");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 6, \
		((e->width / e->grid_size) / 2) - 12, "   _|  _|_|_|_|    _|_|  ");
}

void	print_256(t_env *e, int j, int i)
{
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 1, \
		((e->width / e->grid_size) / 2) - 12, "                             ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 2, \
		((e->width / e->grid_size) / 2) - 12, "   _|_|    _|_|_|_|    _|_|_|");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 3, \
		((e->width / e->grid_size) / 2) - 12, " _|    _|  _|        _|      ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 4, \
		((e->width / e->grid_size) / 2) - 12, "     _|    _|_|_|    _|_|_|  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 5, \
		((e->width / e->grid_size) / 2) - 12, "   _|            _|  _|    _|");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 6, \
		((e->width / e->grid_size) / 2) - 12, " _|_|_|_|  _|_|_|      _|_| ");
}

void	print_512(t_env *e, int j, int i)
{
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

void	print_1024(t_env *e, int j, int i)
{
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 1, \
		((e->width / e->grid_size) / 2) - 12, "  ,-. .--. .---.   .-. ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 2, \
		((e->width / e->grid_size) / 2) - 12, ".'  :: ,. :`--. : .'.' ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 3, \
		((e->width / e->grid_size) / 2) - 12, " `: :: :: :  ,','.'.'_ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 4, \
		((e->width / e->grid_size) / 2) - 12, "  : :: :; :.'.'_ :_ ` :");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 5 + 5, \
		((e->width / e->grid_size) / 2) - 12, "  :_;`.__.':____;  :_: ");
}
