/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:06:34 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:07:19 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

ITEM	**init_item(void)
{
	ITEM **my_items;
	char *choices[2];

	choices[0] = "> 1 - 4x4 grid";
	choices[1] = "> 2 - 5x5 grid";
	my_items = (ITEM **)malloc((2 + 1) * sizeof(ITEM *));
	my_items[0] = new_item(choices[0], "");
	my_items[1] = new_item(choices[1], "");
	my_items[2] = (ITEM *)NULL;
	return (my_items);
}
