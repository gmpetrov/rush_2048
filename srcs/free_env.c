/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:02:13 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 21:32:29 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void	free_win(t_env *e)
{
	int		j;
	int		i;

	j = 0;
	while (j < e->grid_size)
	{
		i = 0;
		while (i < e->grid_size)
		{
			delwin(e->win_tab[j][i]);
			i++;
		}
		free(e->win_tab[j]);
		j++;
	}
	free(e->win_tab);
}

void		free_env(t_env **env)
{
	int		i;

	i = 0;
	while ((*env) && (*env)->game && i < (*env)->grid_size)
	{
		free((*env)->game[i]);
		i++;
	}
	free((*env)->game);
	free_win(*env);
	my_end_menu(env, (*env)->items, (*env)->menu);
	free((*env));
	*env = NULL;
}
