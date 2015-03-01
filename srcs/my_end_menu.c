/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_end_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:06:48 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:07:19 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	my_end_menu(ITEM **my_items, MENU *my_menu)
{
	t_env	*e;

	e = get_env();
	e->is_menu = -42;
	free_item(my_items[0]);
	free_item(my_items[1]);
	free_menu(my_menu);
}
