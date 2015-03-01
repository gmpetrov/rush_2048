/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:02:35 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 20:36:03 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	start_menu(void)
{
	int		c;
	t_env	*e;

	c = 0;
	e = get_env();
	e->is_menu = 1;
	keypad(e->menu_win, TRUE);
	draw_menu();
	c = my_menu_loop();
	if (c == 27)
		quit();
	e->grid_size = (e->boolean == 1 ? 5 : 4);
	my_end_menu(e->items, e->menu);
}
