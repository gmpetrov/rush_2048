/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_menu_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:06:11 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 20:35:20 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		my_menu_loop(void)
{
	int		c;
	t_env	*e;

	e = get_env();
	e->boolean = 0;
	while ((c = wgetch(e->menu_win)) != 27)
	{
		if (c == KEY_DOWN)
		{
			if (e->boolean < 1)
				e->boolean++;
			menu_driver(e->menu, REQ_DOWN_ITEM);
		}
		else if (c == KEY_UP)
		{
			if (e->boolean > 0)
				e->boolean--;
			menu_driver(e->menu, REQ_UP_ITEM);
		}
		else if (c == 10)
			break ;
	}
	return (c);
}
