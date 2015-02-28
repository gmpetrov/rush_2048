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
#include <time.h>

int 	main(void)
{
	t_env	*env;

	ft_putstr("game_2048\n");
	if (!is_pow2(WIN_VALUE))
		return (error_win());
//	initscr();
//	keypad(stdscr, TRUE);
//	signal(SIGWINCH, resizeHandler);
	srand(time(NULL));
	env = init_env(5, 5);
	getEnv(env);
	generate_rand_numb(env);
	generate_rand_numb(env);
//	env->game[4][4] = 4;
//	env->game[0][4] = 4;
	print_game(env);
	while (42)
	{
		if (move_numbers(env, 0))
		{
			write(1, "==========\n", 11);
			print_game(env);
		}
		; /* Resize handling */
	}
	return (0);
}
