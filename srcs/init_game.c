/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:02:10 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:16:05 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

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
