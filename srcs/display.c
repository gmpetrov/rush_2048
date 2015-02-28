/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:41:34 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 16:25:59 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	initDisplay(void)
{
	initscr();
	start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	signal(SIGWINCH, resizeHandler);
}