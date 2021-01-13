/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_conditions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:14:22 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 12:40:06 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int		ft_is_bad_dimention(t_filler fill)
{
	return ((fill.map_width <= 0 || fill.map_height <= 0) ||
			(fill.map_height > INT_MAX || fill.map_width > INT_MAX) ||
			(fill.first_width != fill.map_width) ||
			(fill.first_height != fill.map_height));
}

int		ft_is_max_int_or_negative(int height, int width)
{
	return ((width <= 0 || height <= 0) ||
			(height > INT_MAX || width >= INT_MAX));
}

int		ft_free_2d_array(char **tab)
{
	int i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
			ft_strdel(&tab[i]);
		free(tab);
		tab = NULL;
		return (1);
	}
	return (0);
}

void	ft_free_2d_int_array(int **tab, int size)
{
	int i;

	i = -1;
	if (tab)
	{
		while (++i < size)
			ft_memdel((void **)&tab[i]);
		free(tab);
		tab = NULL;
	}
}

int		ft_detect_demensions_error(int height,
		int width, char **line)
{
	if (ft_is_max_int_or_negative(height, width))
	{
		ft_putendl("dementions error");
		ft_strdel(line);
		return (0);
	}
	return (1);
}
