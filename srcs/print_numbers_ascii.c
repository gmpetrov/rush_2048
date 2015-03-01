/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers_ascii.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:08:22 by mdufaud           #+#    #+#             */
/*   Updated: 2015/03/01 19:08:46 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.h"

void	print_numbers_ascii(t_env *e, int j, int i, int nb)
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
