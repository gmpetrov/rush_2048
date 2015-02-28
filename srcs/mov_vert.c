/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_vert.c                                         :+:      :+:    :+:   */
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
	if (upper_y >= env->grid_size || upper_y < 0)
		return (NOT_MOVED);
	if (env->game[lower_y][x] != 0 &&
		env->game[lower_y][x] == env->game[upper_y][x])
	{
		env->game[upper_y][x] = env->game[lower_y][x] * 2;
		env->game[lower_y][x] = 0;
		return (MOVED);
	}
	else if (env->game[upper_y][x] == 0 && env->game[lower_y][x] != 0)
	{
		env->game[upper_y][x] = env->game[lower_y][x];
		env->game[lower_y][x] = 0;
		return (MOVED);
	}
	return (NOT_MOVED);
}

int			move_up(t_env *env)
{
	int	x;
	int	y;
	int	ret;

	y = env->grid_size - 1;
	ret = NOT_MOVED;
	while (y >= 0)
	{
		x = 0;
		while (x < env->grid_size)
		{
			ret = collide_vert_numbers(env, y, x, y - 1) ? MOVED : ret;
			x++;
		}
		y--;
	}
	return (ret);
}

int			move_down(t_env *env)
{
	int	x;
	int	y;
	int	ret;

	y = 0;
	ret = NOT_MOVED;
	while (y < env->grid_size)
	{
		x = 0;
		while (x < env->grid_size)
		{
			ret = collide_vert_numbers(env, y, x, y + 1) ? MOVED : ret;
			x++;
		}
		y++;
	}
	return (ret);
}
