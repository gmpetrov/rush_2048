/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 21:05:48 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static int	place_rand_number(int num, int x, int y, t_env *env)
{
	if (env->game[y][x] == 0)
	{
		env->game[y][x] = num;
		env->last_x = x;
		env->last_y = y;
		return (1);
	}
	return (0);
}

static void	place_fixed_number(int num, t_env *env)
{
	int	y;
	int	x;

	y = 0;
	while (y < env->grid_size)
	{
		x = 0;
		while (x < env->grid_size)
		{
			if (env->game[y][x] == 0)
			{
				env->game[y][x] = num;
				env->last_x = x;
				env->last_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void		generate_rand_numb(t_env *env)
{
	int	num;
	int	case_x;
	int	case_y;
	int	try;

	num = rand() % 10;
	num = num == 9 ? 4 : 2;
	case_x = 0;
	case_y = 0;
	try = 3;
	while (try)
	{
		case_x = (case_x + rand()) % env->grid_size;
		case_y = (case_y + rand()) % env->grid_size;
		if (place_rand_number(num, case_x, case_y, env))
			return ;
		try--;
	}
	if (!try)
		place_fixed_number(num, env);
}
