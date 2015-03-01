/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:02:35 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 20:14:31 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	start_menu(void)
{
	int		n;
	t_env	*e;

	n = 0;
	e = get_env();
	e->is_menu = 1;
	keypad(e->menu_win, TRUE);
	draw_menu();
	n = my_menu_loop();
	if (n == 27)
		quit();
	e->grid_size = (n == 1 ? 5 : 4);
	my_end_menu(e->items, e->menu);
}
