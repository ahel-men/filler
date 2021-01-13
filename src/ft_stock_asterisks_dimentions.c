/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_asterisks_dimentions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 12:11:37 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 11:20:12 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	ft_get_coordinates(t_filler *fill, int i, int j, int *y)
{
	fill->asterisks_xy[*y][0] = j;
	fill->asterisks_xy[*y][1] = i;
	(*y)++;
}

int		ft_stock_asterisks_dimensions(t_filler *fill)
{
	int i;
	int j;
	int y;

	if (!(fill->asterisks_xy = (int **)ft_memalloc(sizeof(int *) *
					fill->asterisks_counter)))
		return (0);
	i = -1;
	while (++i < fill->asterisks_counter)
		if (!(fill->asterisks_xy[i] = (int *)ft_memalloc(sizeof(int) * 2)))
			return (0);
	i = -1;
	y = 0;
	while (fill->piece[++i])
	{
		j = -1;
		while (fill->piece[i][++j])
		{
			if (fill->piece[i][j] == '*')
				ft_get_coordinates(fill, i, j, &y);
		}
	}
	return (1);
}
