/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:15:57 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 22:16:51 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

#include <stdio.h>

void	draw_game(void);

int 	game[5][5] = {
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1}
};

void 	refresh_win_tab(void)
{
	t_env	*e;
	int 	j;
	int 	i;

	e = getEnv();
	i = 0;
	j = 0;
	while (j < e->grid_size)
	{
		while (i < e->grid_size)
		{
			wrefresh(e->win_tab[j][i]);
			i++;
		}
		i = 0;
		j++;
	}	
}

void 	init_win_tab(void)
{
	t_env	*e;
	int 	j;
	int 	i;

	e = getEnv();
	i = 0;
	j = 0;
	e->win_tab = (WINDOW ***)malloc(sizeof(WINDOW **) * e->grid_size);
	while (j < e->grid_size)
	{
		e->win_tab[j] = (WINDOW **)malloc(sizeof(WINDOW *) * e->grid_size);
		while (i < e->grid_size)
		{
			e->win_tab[j][i] = newwin((e->height / e->grid_size), (e->width / e->grid_size), \
				j * (e->height / e->grid_size), i * (e->width / e->grid_size));
			box(e->win_tab[j][i], 0, 0);
			i++;
		}
		i = 0;
		j++;
	}
}

void 	play(void)
{
	t_env 	*e;
	int 	c;

	e = getEnv();
	init_win_tab();
	while (e->score < (int)WIN_VALUE)
	{
		draw_game();
		refresh_win_tab();
		c = getch();
		if (keyMap(c) != -1)
			e->tab[keyMap(c)]();
	}
}

void 	print_numbers(void)
{
	t_env	*e;
	int 	j;
	int 	i;
	char	*nb;

	i = 0;
	j = 0;
	e = getEnv();
	while (j < e->grid_size)
	{
		while (i < e->grid_size)
		{	
			nb = ft_itoa(game[j][i]);
			if (game[j][i] == 0)
				mvwprintw(e->win_tab[j][i], (e->height / e->grid_size) / 2, \
					(e->width / e->grid_size) / 2, "");
			else
				mvwprintw(e->win_tab[j][i], (e->height / e->grid_size) / 2, \
					(e->width / e->grid_size) / 2, nb);
			i++;
			free(nb);
		}
		i = 0;
		j++;
	}
}

void	draw_game(void)
{
	t_env	*e;
	int 	j;
	int 	i;

	i = 0;
	j = 0;
	e = getEnv();
	while (j < e->grid_size)
	{
		while (i < e->grid_size)
		{
			wclear(e->win_tab[j][i]);
			wresize(e->win_tab[j][i], (e->height / e->grid_size), (e->width / e->grid_size));
			mvwin(e->win_tab[j][i], j * (e->height / e->grid_size), i * (e->width / e->grid_size));
			box(e->win_tab[j][i], 0, 0);
			i++;
		}
		i = 0;
		j++;
	}
	print_numbers();
}	