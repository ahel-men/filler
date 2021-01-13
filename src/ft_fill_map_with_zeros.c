/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map_with_zeros.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 21:49:04 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 11:19:59 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		**ft_allocate_int_2d_array(t_filler *fill)
{
	int **tab;
	int i;

	i = -1;
	if (!(tab = (int **)ft_memalloc(sizeof(int *) * fill->map_height)))
		return (0);
	while (++i < fill->map_height)
	{
		if (!(tab[i] = (int *)ft_memalloc(sizeof(int *) *
						fill->first_width)))
			return (0);
	}
	return (tab);
}

void	ft_mark_each_player1(t_filler *fill, int i, int j)
{
	if (fill->map[i][j] == 'O' || fill->map[i][j] == 'o')
		fill->int_map[fill->z][++(fill->w)] = -2;
	else if (fill->map[i][j] == 'X' || fill->map[i][j] == 'x')
		fill->int_map[fill->z][++(fill->w)] = -1;
}

void	ft_mark_each_player2(t_filler *fill, int i, int j)
{
	if (fill->map[i][j] == 'X' || fill->map[i][j] == 'x')
		fill->int_map[fill->z][++(fill->w)] = -2;
	else if (fill->map[i][j] == 'O' || fill->map[i][j] == 'o')
		fill->int_map[fill->z][++(fill->w)] = -1;
}

void	ft_fill_map_with_zeros(t_filler *fill)
{
	int	i;
	int	j;

	i = -1;
	fill->z = 0;
	if (!fill->int_map)
		fill->int_map = ft_allocate_int_2d_array(fill);
	while (fill->map[++i])
	{
		j = -1;
		fill->w = -1;
		while (fill->map[i][++j])
		{
			if (fill->map[i][j] == '.')
				fill->int_map[fill->z][++(fill->w)] = 0;
			else if (fill->player == 1)
				ft_mark_each_player1(fill, i, j);
			else if (fill->player == 2)
				ft_mark_each_player2(fill, i, j);
		}
		(fill->z)++;
	}
}

void	ft_put_my_player(t_filler *fill)
{
	int x;
	int y;

	y = -1;
	while (++y < fill->map_height)
	{
		x = -1;
		while (++x < fill->map_width)
		{
			if (fill->player == 1)
			{
				if (fill->map[y][x] == 'O' || fill->map[y][x] == 'o')
					fill->int_map[y][x] = -2;
			}
			else if (fill->player == 2)
			{
				if (fill->map[y][x] == 'X' || fill->map[y][x] == 'x')
					fill->int_map[y][x] = -2;
			}
		}
	}
}
