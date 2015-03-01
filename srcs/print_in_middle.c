/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_in_middle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:05:52 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:07:19 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_in_middle(int starty, int startx, int width)
{
	int		length;
	int		x;
	int		y;
	float	temp;
	t_env	*e;

	e = get_env();
	getyx(e->menu_win, y, x);
	if (startx != 0)
		x = startx;
	if (starty != 0)
		y = starty;
	if (width == 0)
		width = 80;
	length = ft_strlen("2048");
	temp = (width - length) / 2;
	x = startx + (int)temp;
	wattron(e->menu_win, COLOR_PAIR(1));
	mvwprintw(e->menu_win, y, x, "%s", "2048");
	wattroff(e->menu_win, COLOR_PAIR(1));
	refresh();
}
