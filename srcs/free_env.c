/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:02:13 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:03:17 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void		free_env(t_env **env)
{
	int		i;

	i = 0;
	while ((*env) && (*env)->game && i < (*env)->grid_size)
	{
		free((*env)->game[i]);
		i++;
	}
	if ((*env)->game)
		free((*env)->game);
	free((*env));
	*env = NULL;
}
