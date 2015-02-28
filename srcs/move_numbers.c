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
	if (env->game[y][x] == 0)
		return (1);
	if (env->game[y][x] == WIN_VALUE)
		return (WIN);
	if (y < (env->grid_size - 1) && env->game[y + 1][x] == env->game[y][x])
		return (1);
	if (y > 0 && env->game[y - 1][x] == env->game[y][x])
		return (1);
	if (x > 0 && env->game[y][x - 1] == env->game[y][x])
		return (1);
	if (x < (env->grid_size - 1) && env->game[y][x + 1] == env->game[y][x])
		return (1);
	return (0);
}

static int	is_check_mate(t_env *env)
{
	int	x;
	int	y;
	int	ret;

	y = 0;
	while (y < env->grid_size)
	{
		x = 0;
		while (x < env->grid_size)
		{
			if ((ret = check_around(env, y, x)) > 0)
				return (ret);
			x++;
		}
		y++;
	}
	return (CHECK_MATE);
}

static int	move_handler(t_env *env, int key)
{
	int		try;
	int		cond;
	int		(*f)(t_env *);

	try = 0;
	f = NULL;
	if (key == KEY_UP || key == KEY_DOWN)
		cond = env->grid_size;
	else
		cond = env->grid_size;
	if (key == KEY_UP)
		f = move_up;
	else if (key == KEY_DOWN)
		f = move_down;
	else if (key == KEY_LEFT)
		f = move_left;
	else if (key == KEY_RIGHT)
		f = move_right;
	while (f && try < cond && f(env) == MOVED)
		try++;
	if (try)
		return (MOVED);
	return (NOT_MOVED);
}

int			move_numbers(t_env *env, int key)
{
	int		moved;
	int		ret;	

	ret = 0;
	moved = 0;
	moved = move_handler(env, key);
	if (moved == MOVED)
	{
		generate_rand_numb(env);
		ret = is_check_mate(env);
		if (ret == WIN || ret == CHECK_MATE)
			return (ret);
	}
	return (moved);
}
