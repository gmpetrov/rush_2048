/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_game(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			ft_putnbr(env->game[i][j]);
			j++;
			write(1, "    ", 4);
		}
		write(1, "\n", 1);
		i++;
	}
	ft_putendl("----------------");
}

void	num_pop(int num, int x, int y)
{
	ft_putstr("Num ");
	ft_putnbr(num);
	ft_putstr(" popped at: y=");
	ft_putnbr(y);
	ft_putstr(" x=");
	ft_putnbr(x);
	ft_putendl("");
}

void	mov_notif(int direction)
{
	ft_putstr("Moved ");
	if (direction == MOVE_UP)
		ft_putendl("UP");
	else if (direction == MOVE_DOWN)
		ft_putendl("DOWN");
	else if (direction == MOVE_LEFT)
		ft_putendl("LEFT");
	else if (direction == MOVE_RIGHT)
		ft_putendl("RIGHT");
}

void	debug_map(t_env *env)
{
	env->game[3][2] = 2;
	env->game[2][2] = 4;
}

void	debug_game(t_env *env, int direction)
{
	int	ret;

	env->game[0][0] = 2;
	env->game[1][1] = 4;
//	generate_rand_numb(env);
//	generate_rand_numb(env);
	print_game(env);
	while (42)
	{
		ret = move_numbers(env, direction);
		print_game(env);
		if (ret == GAME_STOPPED)
			break ;
		if (ret == CHECK_MATE)
			break ;
	}
	if (ret == GAME_STOPPED)
		ft_putendl("No more move in that direction");
}
