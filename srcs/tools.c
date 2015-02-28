/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:58:37 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 13:58:44 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void 	resizeHandler(int sig)
{
	t_env 	*e;

	(void)sig;
    endwin();
    refresh();
    clear();
    e = getEnv();
    e->width = COLS;
    e->height = LINES;
    mvprintw(0, 0, "COLS = %d, LINES = %d", e->width, e->height);
    refresh();
}