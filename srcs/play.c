/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:15:57 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 21:33:09 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

#include <stdio.h>

void	draw_game(void);

int 	game[4][4] = {
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 1, 1},
	{1, 1, 1, 1}
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
		mvprintw(0, 0, "KEY = %d\n", c);
		if (keyMap(c) != -1)
			e->tab[keyMap(c)]();
	}
}

void	draw_game(void)
{
	t_env 	*e;

	e = getEnv();
}	