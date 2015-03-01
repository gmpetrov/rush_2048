/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:02:09 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 22:24:22 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

t_env		*init_env(void)
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
	env->grid_size = 0;
	env->won = 0;
	return (env);
}
