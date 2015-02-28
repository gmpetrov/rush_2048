/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:15:57 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 20:16:39 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

#include <stdio.h>

void 	play(void)
{
	t_env 	*e;
	int 	c;
	int		ret;

	e = getEnv();
	if (!(e->game = init_game(e->height, e->width)))	
	{
		free_env(&e);
		return ;
	}
	while (e->score < (int)WIN_VALUE)
	{
		c = getch();
		if (c != -1)
		{
			mvprintw(0, 0, "KEY = %d\n", c);
			if (c == 27)
				quit();
			ret = move_numbers(e, c);
			if (ret == CHECK_MATE || ret == WIN)
				break ;
		}
	}
}
