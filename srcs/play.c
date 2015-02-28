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

	e = getEnv();
	while (e->score < (int)WIN_VALUE)
	{
		c = getch();
		mvprintw(0, 0, "KEY = %d\n", c);
		if (keyMap(c) != -1)
			e->tab[keyMap(c)]();
	}
}