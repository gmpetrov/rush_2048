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

static int	move_handler(t_env *env, int direction)
{
	int		try;
	int		cond;
	int		(*f)(t_env *);

	try = 0;
	if (direction == MOVE_UP || direction == MOVE_DOWN)
		cond = env->height;
	else
		cond = env->width;
	if (direction == MOVE_UP)
		f = move_up;
	else if (direction == MOVE_DOWN)
		f = move_down;
	else if (direction == MOVE_LEFT)
		f = move_left;
	else if (direction == MOVE_RIGHT)
		f = move_right;
	while (try < cond && f(env) == MOVED)
		try++;
	if (try)
		return (MOVED);
	return (NOT_MOVED);
}

int			move_numbers(t_env *env, int direction)
{
	int		ret;

	ret = 0;
	mov_notif(direction);
	ret = move_handler(env, direction);
	if (ret == MOVED)
	{
		if (is_check_mate(env))
			return (CHECK_MATE);
		generate_rand_numb(env);
	}
	return (ret);
}
