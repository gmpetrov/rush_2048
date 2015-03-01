/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:06:53 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 17:09:12 by gmp              ###   ########.fr       */
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

void 	print_numbers(void)
{
	t_env	*e;
	int 	j;
	int 	i;
	char	*nb;

	i = 0;
	j = 0;
	e = get_env();
	while (j < e->grid_size)
	{
		while (i < e->grid_size)
		{
			nb = ft_itoa(e->game[j][i]);
			wattron(e->win_tab[j][i], COLOR_PAIR(1));
			if ((e->height / e->grid_size) >= 10 && \
				(e->width / e->grid_size) >= 21)
				print_numbers_ascii(e, j, i, e->game[j][i]);
			else
				print_numbers_normal(e, j, i, nb);
			i++;
			free(nb);
		}
		i = 0;
		j++;
	}
}

void 	print_numbers_ascii(t_env *e, int j, int i, int nb)
{
	if (nb == 2)
		print_2(e, j, i);
	else if (nb == 4)
		print_4(e, j, i);
	else if (nb == 8)
		print_8(e, j, i);
	else if (nb == 16)
		print_16(e, j, i);
	else if (nb == 32)
		print_32(e, j, i);
	else if (nb == 64)
		print_64(e, j, i);
	else if (nb == 128)
		print_128(e, j, i);
	else if (nb == 256)
		print_256(e, j, i);
	else if (nb == 512)
		print_512(e, j, i);
	else if (nb == 1024)
		print_1024(e, j, i);
}