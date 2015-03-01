/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:10:51 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 18:20:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	add_score(t_env *e, int number)
{
	int		i;
	int		n;

	if (number <= 4)
		return ;
	i = 2;
	n = 4;
	while (i < 16)
	{
		if (n == number)
		{
			e->score += i * n;
			return ;
		}
		n = 2 * n;
		i++;
	}
}
