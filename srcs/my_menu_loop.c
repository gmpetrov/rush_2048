/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_menu_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:06:11 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:07:19 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int		my_menu_loop(void)
{
	int		n;
	int		c;
	t_env	*e;

	n = 0;
	e = get_env();
	while ((c = wgetch(e->menu_win)) != 27)
	{
		if (c == KEY_DOWN)
		{
			if (n < 1)
				n++;
			menu_driver(e->menu, REQ_DOWN_ITEM);
		}
		else if (c == KEY_UP)
		{
			if (n > 0)
				n--;
			menu_driver(e->menu, REQ_UP_ITEM);
		}
		else if (c == 10)
			break ;
	}
	return (n);
}
