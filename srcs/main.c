/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:55:16 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 20:20:18 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"
#include <time.h>

int 	main(void)
{
	t_env	*env;

	ft_putstr("game_2048\n");

	initDisplay();
	start_menu();
	play();
	// quit();

	if (!is_pow2(WIN_VALUE))
		return (error_win());

//	initDisplay();
//	start_menu();
//	quit();

	srand(time(NULL));
	env = getEnv();
	if (!(env->game = init_game(env->height, env->width)))
	{
		free(env);
		return (1);
	}
	/*
	debug_map(env);
	print_game(env);
	move_numbers(env, MOVE_UP);
	print_game(env);
	*/
	debug_game(env, MOVE_LEFT);
	while (42)
	{
		/* Resize handling */
	}
	free_env(&env);
	return (0);
}
