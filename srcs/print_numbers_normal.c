/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers_normal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:07:51 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:08:51 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_numbers_normal(t_env *e, int j, int i, char *nb)
{
	if (e->game[j][i] == 0)
		mvwprintw(e->win_tab[j][i], (e->height / e->grid_size) / 2, \
			(e->width / e->grid_size) / 2, "");
	else
		mvwprintw(e->win_tab[j][i], (e->height / e->grid_size) / 2, \
			(e->width / e->grid_size) / 2, nb);
}
