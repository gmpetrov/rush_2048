/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 14:16:57 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 17:52:37 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static int	merge_value(t_env *env, int x, int y, int upper_y)
{
	if (upper_y > (env->grid_size - 1) || upper_y < 0 ||
			env->game[upper_y][x] == 0)
		return (NOT_MOVED);
	if (env->game[upper_y][x] == env->game[y][x])
	{
		env->game[y][x] = env->game[upper_y][x] * 2;
		env->game[upper_y][x] = 0;
		return (MOVED);
	}
	return (NOT_MOVED);
}

static int	merge(t_env *env)
{
	int		x;
	int		y;
	int		ret;

	x = 0;
	ret = NOT_MOVED;
	while (x < env->grid_size)
	{
		y = env->grid_size - 1;
		while (y >= 0)
		{
			ret = merge_value(env, x, y, y - 1) ? MOVED : ret;
			y--;
		}
		x++;
	}
	return (ret);
}

static int	change_pos(t_env *env, int x, int y)
{
	int		i;

	i = y + 1;
	if (env->game[y][x] == 0)
		return (NOT_MOVED);
	while (i < env->grid_size && env->game[i][x] == 0)
		i++;
	if (i - 1 >= 0 && i - 1 < env->grid_size
			&& env->game[i - 1][x] == 0)
	{
		env->game[i - 1][x] = env->game[y][x];
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

	x = 0;
	ret = NOT_MOVED;
	while (x < env->grid_size)
	{
		y = env->grid_size - 1;
		while (y >= 0)
		{
			ret = change_pos(env, x, y) ? MOVED : ret;
			y--;
		}
		x++;
	}
	return (ret);
}

int			move_down(t_env *env)
{
	int		ret;

	ret = move_space(env);
	ret = merge(env) ? MOVED : ret;
	ret = move_space(env) ? MOVED : ret;
	return (ret);
}
