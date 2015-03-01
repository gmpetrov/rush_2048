/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:15:08 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 21:57:33 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	init_win_tab(t_env *e)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	e->win_tab = (WINDOW ***)malloc(sizeof(WINDOW **) * e->grid_size);
	while (j < e->grid_size)
	{
		e->win_tab[j] = (WINDOW **)malloc(sizeof(WINDOW *) * e->grid_size);
		while (i < e->grid_size)
		{
			e->win_tab[j][i] = newwin((e->height / e->grid_size), \
				(e->width / e->grid_size), \
				j * (e->height / e->grid_size), i * (e->width / e->grid_size));
			box(e->win_tab[j][i], 0, 0);
			i++;
		}
		i = 0;
		j++;
	}
}
