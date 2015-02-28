/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static int	collide_vert_numbers(t_env *env, int lower_y, int x, int upper_y)
{
	if (upper_y >= env->height || upper_y < 0)
		return (0);
	if (env->game[lower_y][x] != 0 &&
		env->game[lower_y][x] == env->game[upper_y][x])
	{
		env->game[upper_y][x] = env->game[lower_y][x] * 2;
		env->game[lower_y][x] = 0;
	}
	else if (env->game[upper_y][x] == 0)
	{
		env->game[upper_y][x] = env->game[lower_y][x];
		env->game[lower_y][x] = 0;
	}
	else if (env->game[upper_y][x] != 0 && env->game[lower_y][x] != 0)
		return (0);
	return (1);
}

int			move_up(t_env *env)
{
	int	x;
	int	y;
	int	ret;

	y = env->height - 1;
	ret = 0;
	while (y >= 0)
	{
		x = 0;
		while (x < env->width)
		{
			ret = collide_vert_numbers(env, y, x, y - 1) == 1 ? 1 : ret;
			x++;
		}
		y--;
	}
	return (ret);
}
