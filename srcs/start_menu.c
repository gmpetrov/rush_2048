/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:02:35 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 16:00:21 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

#include <stdio.h>

ITEM 	**init_item(void);
int 	menu_loop(MENU 	*my_menu);
void 	end_menu(ITEM **my_items, MENU *my_menu);

void 	start_menu(void)
{

	ITEM 	**my_items;
	MENU 	*my_menu;
	int 	n;

	n = 0;
	my_items = init_item();
	my_menu = new_menu((ITEM **)my_items);
	mvprintw(LINES - 2, 0, "F1 to Exit");
	post_menu(my_menu);
	refresh();
	n = menu_loop(my_menu);
	end_menu(my_items, my_menu);
}

int 	menu_loop(MENU 	*my_menu)
{
	int 	n;
	int 	c;

	n = 0;
	while((c = getch()) != KEY_F(1))
	{   
		if (c == KEY_DOWN){
			if (n < 1)
				n++;
			menu_driver(my_menu, REQ_DOWN_ITEM);
		}
		else if (c == KEY_UP){
			if (n > 0)
				n--;
			menu_driver(my_menu, REQ_UP_ITEM);
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
	endwin();
}