/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2_4_8_16_32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:55:47 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 15:25:57 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_2(t_env *e, int j, int i)
{
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

void 	print_4(t_env *e, int j, int i)
{
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 1, \
		((e->width / e->grid_size) / 2) - 5, " __    __ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 2, \
		((e->width / e->grid_size) / 2) - 5, "/  |  /  |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 3, \
		((e->width / e->grid_size) / 2) - 5, "$$ |  $$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 4, \
		((e->width / e->grid_size) / 2) - 5, "$$ |__$$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 5, \
		((e->width / e->grid_size) / 2) - 5, "$$    $$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 6, \
		((e->width / e->grid_size) / 2) - 5, "$$$$$$$$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 7, \
		((e->width / e->grid_size) / 2) - 5, "      $$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 8, \
		((e->width / e->grid_size) / 2) - 5, "      $$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 9, \
		((e->width / e->grid_size) / 2) - 5, "      $$/");
}

void 	print_8(t_env *e, int j, int i)
{
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 1, \
		((e->width / e->grid_size) / 2) - 5, "  ______  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 2, \
		((e->width / e->grid_size) / 2) - 5, " /      \\ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 3, \
		((e->width / e->grid_size) / 2) - 5, "/$$$$$$  |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 4, \
		((e->width / e->grid_size) / 2) - 5, "$$ \\__$$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 5, \
		((e->width / e->grid_size) / 2) - 5, "$$    $$< ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 6, \
		((e->width / e->grid_size) / 2) - 5, " $$$$$$  |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 7, \
		((e->width / e->grid_size) / 2) - 5, "$$ \\__$$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 8, \
		((e->width / e->grid_size) / 2) - 5, "$$    $$/ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 9, \
		((e->width / e->grid_size) / 2) - 5, " $$$$$$/  ");
}

void 	print_16(t_env *e, int j, int i)
{
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 1, \
		((e->width / e->grid_size) / 2) - 7, "   __     ______  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 2, \
		((e->width / e->grid_size) / 2) - 7, " _/  |   /      \\ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 3, \
		((e->width / e->grid_size) / 2) - 7, "/ $$ |  /$$$$$$  |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 4, \
		((e->width / e->grid_size) / 2) - 7, "$$$$ |  $$ \\__$$/ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 5, \
		((e->width / e->grid_size) / 2) - 7, "  $$ |  $$      \\ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 6, \
		((e->width / e->grid_size) / 2) - 7, "  $$ |  $$$$$$$  |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 7, \
		((e->width / e->grid_size) / 2) - 7, " _$$ |_ $$ \\__$$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 8, \
		((e->width / e->grid_size) / 2) - 7, "/ $$   |$$    $$/ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 9, \
		((e->width / e->grid_size) / 2) - 7, "$$$$$$/  $$$$$$/  ");
}

void 	print_32(t_env *e, int j, int i)
{
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 1, \
		((e->width / e->grid_size) / 2) - 8, "  ______    ______  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 2, \
		((e->width / e->grid_size) / 2) - 8, " /      \\  /      \\ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 3, \
		((e->width / e->grid_size) / 2) - 8, "/$$$$$$  |/$$$$$$  |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 4, \
		((e->width / e->grid_size) / 2) - 8, "$$ ___$$ |$$____$$ |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 5, \
		((e->width / e->grid_size) / 2) - 8, "  /   $$<  /    $$/ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 6, \
		((e->width / e->grid_size) / 2) - 8, " _$$$$$  |/$$$$$$/  ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 7, \
		((e->width / e->grid_size) / 2) - 8, "/  \\__$$ |$$ |_____ ");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 8, \
		((e->width / e->grid_size) / 2) - 8, "$$    $$/ $$       |");
	mvwprintw(e->win_tab[j][i], ((e->height / e->grid_size) / 2) - 6 + 9, \
		((e->width / e->grid_size) / 2) - 8, " $$$$$$/  $$$$$$$$/");
}
