/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:15:57 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 17:52:20 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	refresh_win_tab(void)
{
	t_env	*e;
	int		j;
	int		i;

	e = get_env();
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

void	init_win_tab(void)
{
	t_env	*e;
	int		j;
	int		i;

	e = get_env();
	i = 0;
	j = 0;
	e->win_tab = (WINDOW ***)malloc(sizeof(WINDOW **) * e->grid_size);
	while (j < e->grid_size)
	{
		e->win_tab[j] = (WINDOW **)malloc(sizeof(WINDOW *) * e->grid_size);
		while (i < e->grid_size)
		{
			e->win_tab[j][i] = newwin((e->height / e->grid_size), \
				(e->width / e->grid_size), \
				j * (e->height / e->grid_size), i * (e->width / e->grid_size));
			box(e->win_tab[j][i], 0, 0);
			i++;
		}
		i = 0;
		j++;
	}
}

void	choose_screen(int ret)
{
	if (ret == CHECK_MATE)
		loose_screen();
}

void	play(void)
{
	t_env	*e;
	int		c;
	int		ret;

	ret = -1;
	e = get_env();
	if (!init_game(&e))
		return ;
	init_win_tab();
	while (e->score < (int)WIN_VALUE)
	{
		draw_game();
		refresh_win_tab();
		c = getch();
		if (c != -1)
		{
			if (c == 27)
				quit();
			ret = move_numbers(e, c);
			if (ret == CHECK_MATE || ret == WIN)
				break ;
		}
	}
	choose_screen(ret);
}

void	draw_game(void)
{
	t_env	*e;
	int		j;
	int		i;

	i = 0;
	j = 0;
	e = get_env();
	while (j < e->grid_size)
	{
		while (i < e->grid_size)
		{
			wclear(e->win_tab[j][i]);
			wresize(e->win_tab[j][i], (e->height / e->grid_size), \
				(e->width / e->grid_size));
			mvwin(e->win_tab[j][i], j * (e->height / e->grid_size), \
				i * (e->width / e->grid_size));
			wattron(e->win_tab[j][i], COLOR_PAIR(3));
			box(e->win_tab[j][i], 0, 0);
			i++;
		}
		i = 0;
		j++;
	}
	print_numbers();
}
