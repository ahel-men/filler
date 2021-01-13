/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:12:52 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 10:21:36 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		ft_check_case(t_filler *fill, int x, int y)
{
	int res;

	res = fill->int_map[y][x];
	return (res == 0 || res == -2);
}

void	ft_check2(t_filler *fill, int x, int y, int sv)
{
	if ((x - 1) >= 0 && (y - 1) >= 0 &&
		ft_check_case(fill, x - 1, y - 1))
		fill->int_map[y - 1][x - 1] = sv;
	if ((x - 1) >= 0 &&
		ft_check_case(fill, x - 1, y))
		fill->int_map[y][x - 1] = sv;
	if ((x + 1) < fill->map_width &&
		ft_check_case(fill, x + 1, y))
		fill->int_map[y][x + 1] = sv;
	if ((x - 1) >= 0 && (y + 1) < fill->map_height &&
		ft_check_case(fill, x - 1, y + 1))
		fill->int_map[y + 1][x - 1] = sv;
}

int		ft_check1(t_filler *fill, int x, int y, int sv)
{
	if ((y - 1) >= 0 &&
		ft_check_case(fill, x, y - 1))
		fill->int_map[y - 1][x] = sv;
	if ((y - 1) >= 0 && (x + 1) < fill->map_width &&
		ft_check_case(fill, x + 1, y - 1))
		fill->int_map[y - 1][x + 1] = sv;
	if ((y + 1) < fill->map_height &&
		ft_check_case(fill, x, y + 1))
		fill->int_map[y + 1][x] = sv;
	if ((y + 1) < fill->map_height && (x + 1) < fill->map_width &&
		ft_check_case(fill, x + 1, y + 1))
		fill->int_map[y + 1][x + 1] = sv;
	return (1);
}

void	ft_var_init(int *y, int *nb, int *sv)
{
	*y = -1;
	*nb = -1;
	*sv = *nb;
}

void	ft_create_hit_map(t_filler *fill)
{
	int x;
	int y;
	int nb;
	int sv;

	ft_var_init(&y, &nb, &sv);
	while (look_for_zero(fill))
	{
		nb = sv;
		if (sv == -1)
			sv += 2;
		else
			sv++;
		y = -1;
		while (++y < fill->map_height)
		{
			x = -1;
			while (++x < fill->map_width)
			{
				if (fill->int_map[y][x] == nb && ft_check1(fill, x, y, sv))
					ft_check2(fill, x, y, sv);
			}
		}
	}
	ft_put_my_player(fill);
}
