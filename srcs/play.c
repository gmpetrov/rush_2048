/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 19:15:57 by gmp               #+#    #+#             */
/*   Updated: 2015/03/01 19:49:18 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

static void	choose_screen(int ret)
{
	if (ret == CHECK_MATE)
		loose_screen();
	else if (ret == WIN)
		win_screen();
}

void		play(void)
{
	t_env	*e;
	int		c;
	int		ret;

	ret = -1;
	e = get_env();
	if (!init_game(&e))
		return ;
	init_win_tab();
	while (42)
	{
		draw_game();
		refresh_win_tab();
		c = getch();
		if (c > 0)
		{
			if (c == 27)
				quit();
			ret = move_numbers(e, c);
			if (ret == CHECK_MATE || ret == WIN)
				break ;
		}
	}
	choose_screen(ret);
}
