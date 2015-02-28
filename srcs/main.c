/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:55:16 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 13:58:31 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

int 	main(void)
{
	ft_putstr("game_2048\n");
	initscr();
	keypad(stdscr, TRUE);
	signal(SIGWINCH, resizeHandler);
	while (42)
		; /* Resize handling */
	return (0);
}