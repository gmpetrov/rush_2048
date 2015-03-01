/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_win_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:15:05 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:49:26 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	refresh_win_tab(void)
{
	t_env	*e;
	int		j;
	int		i;

	e = get_env();
	i = 0;
	j = 0;
	while (j < e->grid_size)
	{
		while (i < e->grid_size)
		{
			wnoutrefresh(e->win_tab[j][i]);
			i++;
		}
		i = 0;
		j++;
	}
	doupdate();
}
