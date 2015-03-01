/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:55:16 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 22:02:03 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"
#include <time.h>

int		main(void)
{
	t_env	*e;

	if (!is_pow2(WIN_VALUE))
		return (error_win());
	srand(time(NULL));
	init_display();
	e = get_env();
	start_menu(e);
	play(e);
	quit(e);
	return (0);
}
