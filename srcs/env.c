/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:11:43 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 13:16:00 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

t_env		*getEnv(t_env *env)
{
	static t_env	*e = NULL;

	if (env)
		e = env;
	else if (e == NULL)
		e = init_env(4, 4);
	return e;
}

void		free_env(t_env **env)
{
	int		i;

	i = 0;
	while (i < (*env)->height)
	{
		free((*env)->game[i]);
		i++;
	}
	free((*env)->game);
	free((*env));
	*env = NULL;
}

static int	**init_game(int x, int y)
{
	int	**game;
	int	i;
	int	j;

	i = 0;
	if (!(game = malloc(y * sizeof(int *))))
		return (NULL);
	while (i < y)
	{
		if (!(game[i] = malloc(x * sizeof(int))))
			return (NULL);
		j = 0;
		while (j < x)
		{
			game[i][j] = 0;
			j++;
		}
		i++;
	}
	return (game);
}

t_env		*init_env(int x, int y)
{
	t_env	*env;

	if (!(env = malloc(sizeof(t_env))))
		return (NULL);
	env->width = x;
	env->height = y;
	if (!(env->game = init_game(x, y)))
	{
		free(env);
		return (NULL);
	}
	return (env);
}
