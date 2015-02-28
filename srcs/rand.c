/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 22:47:41 by mdufaud           #+#    #+#             */
/*   Updated: 2014/05/04 22:42:53 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static int	place_rand_number(int num, int x, int y, t_env *env)
{
	if (env->game[y][x] == 0)
	{
		env->game[y][x] = num;
		return (1);
	}
	return (0);
}

static void	place_fixed_number(int num, t_env *env)
{
	int	y;
	int	x;
	int	has_break;

	y = 0;
	has_break = 0;
	ft_putendl("uh ho");
	while (y < env->height)
	{
		x = 0;
		while (x < env->height)
		{
			if (env->game[y][x] == 0)
			{
				env->game[y][x] = num;
				has_break = 1;
				break ;
			}
			x++;
		}
		if (has_break)
			break ;
		y++;
	}
}

void		generate_rand_numb(t_env *env)
{
	int	num;
	int	case_x;
	int	case_y;
	int	try;

	num = ((rand() % 2) + 1) * 2;
	case_x = 0;
	case_y = 0;
	try = 3;
	while (try--)
	{
		case_x = (case_x + rand()) % env->width;
		case_y = (case_y + rand()) % env->height;
		if (place_rand_number(num, case_x, case_y, env))
			break ;
		try--;
	}
	if (!try)
		place_fixed_number(num, env);
}
