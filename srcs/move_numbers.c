/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static int	check_around(t_env *env, int y, int x)
{
	if (y < (env->height + 1) && env->game[y + 1][x] == env->game[y][x])
		return (1);
	if (y > 0 && env->game[y - 1][x] == env->game[y][x])
		return (1);
	if (x > 0 && env->game[y][x - 1] == env->game[y][x])
		return (1);
	if (x < (env->width + 1) && env->game[y][x + 1] == env->game[y][x])
		return (1);
	return (0);
}

static int	is_check_mate(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			if (check_around(env, y, x))
				return (0);
			x++;
		}
		y++;
	}
	ft_putendl("Is check mate");
	return (1);
}

int		move_numbers(t_env *env, int direction)
{
	int		ret;

	ret = 0;
	if (direction == 0)
		ret = move_up(env);
	if (ret)
	{
		if (is_check_mate(env))
			return (1);
		generate_rand_numb(env);
	}
	return (ret);
}
