/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:55:16 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 18:26:46 by gmp              ###   ########.fr       */
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
	quit();

	if (!is_pow2(WIN_VALUE))
		return (error_win());
//	initscr();
//	keypad(stdscr, TRUE);
//	signal(SIGWINCH, resizeHandler);
	srand(time(NULL));
	if (!(env = init_env(4, 4)))
		return (error("Not enough memory"));
	getEnv(env);
	/*
	generate_rand_numb(env);
	generate_rand_numb(env);
	print_game(env);
	move_numbers(env, MOVE_UP);
	print_game(env);
	move_numbers(env, MOVE_DOWN);
	print_game(env);
	move_numbers(env, MOVE_LEFT);
	print_game(env);
	move_numbers(env, MOVE_RIGHT);
	print_game(env);
	*/
	/*
	debug_map(env);
	print_game(env);
	move_numbers(env, MOVE_UP);
	print_game(env);
	*/
	//debug_game(env, MOVE_LEFT);
	while (42)
	{
		break ;
		/* Resize handling */
	}
	free_env(&env);
	return (0);
}
