/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:15:04 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:15:46 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	draw_game(void)
{
	t_env	*e;
	int		j;
	int		i;

	i = 0;
	j = 0;
	e = get_env();
	while (j < e->grid_size)
	{
		while (i < e->grid_size)
		{
			wclear(e->win_tab[j][i]);
			wresize(e->win_tab[j][i], (e->height / e->grid_size), \
				(e->width / e->grid_size));
			mvwin(e->win_tab[j][i], j * (e->height / e->grid_size), \
				i * (e->width / e->grid_size));
			wattron(e->win_tab[j][i], COLOR_PAIR(3));
			box(e->win_tab[j][i], 0, 0);
			i++;
		}
		i = 0;
		j++;
	}
	print_numbers();
}
