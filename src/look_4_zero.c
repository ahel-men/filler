/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_4_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:29:58 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 10:30:57 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int	look_for_zero(t_filler *fill)
{
	int x;
	int y;

	y = -1;
	while (++y < fill->map_height)
	{
		x = -1;
		while (++x < fill->map_width)
		{
			if (fill->int_map[y][x] == 0)
				return (1);
		}
	}
	return (0);
}
