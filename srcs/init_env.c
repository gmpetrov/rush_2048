/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:02:09 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:03:04 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

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
