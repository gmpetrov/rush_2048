/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 15:06:53 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 21:59:18 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_numbers(t_env *e)
{
	int		j;
	int		i;
	char	*nb;

	i = 0;
	j = 0;
	while (j < e->grid_size)
	{
		while (i < e->grid_size)
		{
			nb = ft_itoa(e->game[j][i]);
			wattron(e->win_tab[j][i], COLOR_PAIR(1));
			if ((e->height / e->grid_size) >= 8 && \
				(e->width / e->grid_size) >= 21 && e->game[j][i] <= 1024)
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
