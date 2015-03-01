/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:02:35 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 21:57:19 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	start_menu(t_env *e)
{
	int		c;

	c = 0;
	e->is_menu = 1;
	keypad(e->menu_win, TRUE);
	draw_menu(e);
	c = my_menu_loop(e);
	if (c == 27)
		quit(e);
	e->grid_size = (e->boolean == 1 ? 5 : 4);
}
