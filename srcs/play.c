/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:15:57 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 22:25:40 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void		play(t_env *e)
{
	int		c;
	int		ret;

	ret = -1;
	if (!init_game(&e))
		return ;
	init_win_tab(e);
	while (42)
	{
		draw_game(e);
		refresh_win_tab(e);
		c = getch();
		if (c > 0)
		{
			if (c == 27)
				quit(e);
			ret = move_numbers(e, c);
			if (ret == CHECK_MATE)
				loose_screen(e);
			if (ret == WIN && !e->won)
				win_screen(e);
		}
	}
}
