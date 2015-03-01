/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:55:16 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 17:13:06 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"
#include <time.h>

int 	main(void)
{
	ft_putstr("game_2048\n");
	if (!is_pow2(WIN_VALUE))
		return (error_win());
	srand(time(NULL));
	init_display();
	start_menu();
	play();
	quit();
//	init_display();
//	start_menu();
//	quit();

//	env = getEnv();
//	if (!(env->game = init_game(env->height, env->width)))
//	{
//		free(env);
//		return (1);
//	}
	/*
	debug_map(env);
	print_game(env);
	move_numbers(env, MOVE_UP);
	print_game(env);
	*/
//	debug_game(env, MOVE_LEFT);
//	while (42)
//	{
		/* Resize handling */
//	}
	return (0);
}
