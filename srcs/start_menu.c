/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:02:35 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 18:18:27 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

#include <stdio.h>

int 	menu_loop();
void 	end_menu(ITEM **my_items, MENU *my_menu);

void 	start_menu(void)
{

	int 	n;
	t_env 	*e;

	n = 0;
	e = getEnv();
	e->is_menu = 1;
	keypad(e->menu_win, TRUE);
	draw_menu();
	n = menu_loop();
	end_menu(e->items, e->menu);
}

void print_in_middle(int starty, int startx, int width)
{	int length, x, y;
	float temp;
	t_env 	*e;

	e = getEnv();
	// if(e->menu_win == NULL)
	// 	e->menu_win = stdscr;
	getyx(e->menu_win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;
	length = ft_strlen("2048");
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(e->menu_win, COLOR_PAIR(1));
	mvwprintw(e->menu_win, y, x, "%s", "2048");
	wattroff(e->menu_win, COLOR_PAIR(1));
	refresh();
}

int 	menu_loop()
{
	int 	n;
	int 	c;
	t_env 	*e;

	n = 0;
	e = getEnv();
	while((c = wgetch(e->menu_win)) != 27)
	{   
		if (c == KEY_DOWN){
			if (n < 1)
				n++;
			menu_driver(e->menu, REQ_DOWN_ITEM);
		}
		else if (c == KEY_UP){
			if (n > 0)
				n--;
			menu_driver(e->menu, REQ_UP_ITEM);
		}
		else if (c == 10)
			break ;
	}
	return n;
}

ITEM 	**init_item(void)
{
	ITEM **my_items;
	char *choices[2];

	choices[0] = "> 1 - 4x4 grid";
	choices[1] = "> 2 - 5x5 grid";
	my_items = (ITEM **)malloc((2 + 1) * sizeof(ITEM *));
	my_items[0] = new_item(choices[0], "");
	my_items[1] = new_item(choices[1], "");
	my_items[2] = (ITEM *)NULL;
	return my_items;
}

void 	end_menu(ITEM **my_items, MENU *my_menu)
{
	free_item(my_items[0]);
	free_item(my_items[1]);
	free_menu(my_menu);
}