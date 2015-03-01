/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:11:43 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 17:19:49 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

t_env		*getEnv(void)
{
	static t_env	*e = NULL;

	if (e == NULL)
		e = init_env(5);
	return (e);
}

void		free_env(t_env **env)
{
	int		i;

	i = 0;
	while ((*env) && (*env)->game && i < (*env)->grid_size)
	{
		free((*env)->game[i]);
		i++;
	}
	if ((*env)->game)
		free((*env)->game);
	free((*env));
	*env = NULL;
}

static int	**allocate_game_grid(int grid_size)
{
	int	**game;
	int	i;
	int	j;

	i = 0;
	if (!(game = malloc(grid_size * sizeof(int *))))
		return (NULL);
	while (i < grid_size)
	{
		if (!(game[i] = malloc(grid_size * sizeof(int))))
			return (NULL);
		j = 0;
		while (j < grid_size)
		{
			game[i][j] = 0;
			j++;
		}
		i++;
	}
	return (game);
}

int			init_game(t_env **e)
{
	(*e)->game = allocate_game_grid((*e)->grid_size);
	if (!(*e)->game)
		return (0);
	generate_rand_numb(*e);
	generate_rand_numb(*e);
	return (1);
}

t_env		*init_env(int grid_size)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->last_x = -1;
	env->last_y = -1;
	env->width = COLS;
	env->height = LINES;
	env->is_menu = 0;
	env->menu_win = newwin(10, 40, (LINES / 2) - 5, (COLS / 2) - 20);
	env->items = init_item();
	env->menu = new_menu((ITEM **)env->items);
	env->game = NULL;
	env->score = 0;
	env->grid_size = grid_size;
	return (env);
}
