/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 13:11:43 by gmp               #+#    #+#             */
/*   Updated: 2015/02/28 17:25:34 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

t_env	*getEnv(void)
{
	static t_env	*e = NULL;
	if (e == NULL){
		e = (t_env *)malloc(sizeof(t_env));
		e->width = COLS;
		e->height = LINES;
		e->is_menu = 0;
		e->menu_win = newwin(10, 40, (LINES / 2) - 5, (COLS / 2) - 20);
		e->items = init_item();
		e->menu = new_menu((ITEM **)e->items);
	}
	return e;
}