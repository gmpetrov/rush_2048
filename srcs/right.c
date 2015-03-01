/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:16:58 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 16:49:43 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static int	merge_value(t_env *env, int x, int y, int prev_x)
{
	if (prev_x >= (env->grid_size - 1) || prev_x < 0 ||
			env->game[y][prev_x] == 0)
		return (NOT_MOVED);
	if (env->game[y][prev_x] == env->game[y][x])
	{
		env->game[y][x] = env->game[y][prev_x] * 2;
		env->game[y][prev_x] = 0;
		return (MOVED);
	}
	return (NOT_MOVED);
}

static int	merge(t_env *env)
{
	int		x;
	int		y;
	int		ret;

	y = 0;
	ret = NOT_MOVED;
	while (y < env->grid_size)
	{
		x = env->grid_size - 1;
		while (x >= 0)
		{
			ret = merge_value(env, x, y, x - 1) ? MOVED : ret;
			x--;
		}
		y++;
	}
	return (ret);
}

static int	change_pos(t_env *env, int x, int y)
{
	int		i;

	i = x + 1;
	if (env->game[y][x] == 0)
		return (NOT_MOVED);
	while (i < env->grid_size && env->game[y][i] == 0)
		i++;
	if (i - 1 >= 0 && i - 1 < env->grid_size
			&& env->game[y][i - 1] == 0)
	{
		env->game[y][i - 1] = env->game[y][x];
		env->game[y][x] = 0;
		return (MOVED);
	}
	return (NOT_MOVED);
}

static int	move_space(t_env *env)
{
	int		x;
	int		y;
	int		ret;

	y = 0;
	ret = NOT_MOVED;
	while (y < env->grid_size)
	{
		x = env->grid_size - 1;
		while (x >= 0)
		{
			ret = change_pos(env, x, y) ? MOVED : ret;
			x--;
		}
		y++;
	}
	return (ret);
}

int			move_right(t_env *env)
{
	int		ret;

	ret = move_space(env);
	ret = merge(env) ? MOVED : ret;
	ret = move_space(env) ? MOVED : ret;
	return (ret);
}
