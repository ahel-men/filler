/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:21:41 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 11:19:50 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	ft_store_piece_demensions(t_filler *fill, char *line, int i, int y)
{
	char	*str;

	str = &line[i];
	fill->p_height = ft_define_number(str, fill);
	str = &line[y + fill->index];
	fill->p_width = ft_define_number(str, fill);
}

void	ft_print_coordinates(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void	ft_search_for_best_score(t_filler *fill, int x, int y, int *i)
{
	while (++(*i) < fill->asterisks_counter)
	{
		fill->w = fill->asterisks_xy[*i][0] + x;
		fill->z = fill->asterisks_xy[*i][1] + y;
		if (fill->w >= fill->map_width ||
				fill->w < 0 || fill->z >= fill->map_height ||
				fill->z < 0 || fill->int_map[fill->z][fill->w] == -1)
			break ;
		else
		{
			if (fill->int_map[fill->z][fill->w] == -2)
			{
				fill->best_x = fill->w - fill->asterisks_xy[*i][0];
				fill->best_y = fill->z - fill->asterisks_xy[*i][1];
				fill->on_top_of_one += fill->int_map[fill->z][fill->w];
				if (fill->on_top_of_one == -4)
					break ;
			}
			fill->score += fill->int_map[fill->z][fill->w];
		}
	}
}

void	ft_save_smallest_score(t_filler *fill)
{
	if (!fill->save_smallest_score)
	{
		fill->save_smallest_score = fill->score;
		fill->save_x = fill->best_x;
		fill->save_y = fill->best_y;
	}
	else if (fill->score < fill->save_smallest_score)
	{
		fill->save_smallest_score = fill->score;
		fill->save_x = fill->best_x;
		fill->save_y = fill->best_y;
	}
}

int		ft_get_dimensions_to_place_piece(t_filler *fill)
{
	int		x;
	int		y;
	int		i;

	fill->score = 0;
	fill->on_top_of_one = 0;
	fill->save_smallest_score = 0;
	y = -1;
	while (++y < fill->map_height)
	{
		x = -1;
		while (++x < fill->map_width)
		{
			i = -1;
			ft_search_for_best_score(fill, x, y, &i);
			if (i == fill->asterisks_counter && fill->on_top_of_one == -2)
				ft_save_smallest_score(fill);
			fill->score = 0;
			fill->on_top_of_one = 0;
		}
	}
	ft_print_coordinates(fill->save_y, fill->save_x);
	return (0);
}
