/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_end_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:06:48 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 21:33:45 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	my_end_menu(t_env **e, ITEM **my_items, MENU *my_menu)
{
	(*e)->is_menu = -42;
	if (my_items)
	{
		free_item(my_items[0]);
		free_item(my_items[1]);
		free(my_items);
	}
	if (my_menu)
		free_menu(my_menu);
	(*e)->items = NULL;
	(*e)->menu = NULL;
}
