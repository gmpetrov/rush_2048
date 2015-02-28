/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_hori.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static int	collide_hori_numbers(t_env *env, int prev_x, int y, int next_x)
{
	if (next_x >= env->width || next_x < 0)
		return (NOT_MOVED);
	if (env->game[y][prev_x] != 0 &&
		env->game[y][prev_x] == env->game[y][next_x])
	{
		env->game[y][next_x] = env->game[y][prev_x] * 2;
		env->game[y][prev_x] = 0;
		return (MOVED);
	}
	else if (env->game[y][next_x] == 0 && env->game[y][prev_x] != 0)
	{
		env->game[y][next_x] = env->game[y][prev_x];
		env->game[y][prev_x] = 0;
		return (MOVED);
	}
	return (NOT_MOVED);
}

int			move_left(t_env *env)
{
	int	x;
	int	y;
	int	ret;

	y = 0;
	ret = 0;
	while (y < env->height)
	{
		x = env->width - 1;
		while (x >= 0)
		{
			ret = collide_hori_numbers(env, x, y, x - 1) == 1 ? 1 : ret;
			x--;
		}
		y++;
	}
	return (ret);
}

int			move_right(t_env *env)
{
	int	x;
	int	y;
	int	ret;

	y = 0;
	ret = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			ret = collide_hori_numbers(env, x, y, x + 1) == 1 ? 1 : ret;
			x++;
		}
		y++;
	}
	return (ret);
}
