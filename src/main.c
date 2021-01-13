/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:08:44 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 14:27:37 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int	ft_store_piece(t_filler *fill, char **line, int *i)
{
	if (!(ft_allocate_piece(fill, line, i)))
		return (0);
	while (*i < fill->p_height && get_next_line(0, line, 0) > 0 &&
			(*line[0] == '.' || *line[0] == '*'))
	{
		if (!(ft_stock_piece(*line, fill)))
		{
			ft_putendl("piece error");
			ft_rescue_memory(fill);
			ft_strdel(line);
			return (0);
		}
		(*i)++;
		ft_strdel(line);
	}
	if (fill->h_piece_index < fill->p_height)
	{
		ft_putendl("map is uncompleted");
		ft_rescue_memory(fill);
		ft_strdel(line);
		return (0);
	}
	return (1);
}

int	ft_print_dimensions_to_vm(t_filler *fill)
{
	ft_fill_map_with_zeros(fill);
	ft_create_hit_map(fill);
	if (!(ft_stock_asterisks_dimensions(fill)))
		return (0);
	ft_get_dimensions_to_place_piece(fill);
	return (1);
}

int	ft_manipulate_map(t_filler *fill, char **line)
{
	if (!(ft_check_dimensions(fill, *line)))
		return (0);
	if (!fill->map)
		if (!(ft_allocate_map_array(fill, line)))
			return (0);
	ft_strdel(line);
	if (!(store_map(fill, line)))
		return (0);
	return (1);
}

int	ft_manipulate_piece(t_filler *fill, char **line, int *i)
{
	if (ft_strnequ("Piece ", *line, 6))
	{
		if (!(ft_store_piece(fill, line, i)))
			return (0);
		ft_print_dimensions_to_vm(fill);
	}
	return (1);
}

int	main(void)
{
	int			i;
	char		*line;
	t_filler	fill;

	i = 0;
	ft_bzero(&fill, sizeof(t_filler));
	while (get_next_line(0, &line, 0) > 0)
	{
		if (!fill.checked)
		{
			if (!(ft_check_which_player(&fill, line, &fill.checked)))
				return (0);
			continue;
		}
		else if (ft_strnequ("Plateau ", line, 8))
		{
			if (!(ft_manipulate_map(&fill, &line)))
				return (0);
		}
		if (!(ft_manipulate_piece(&fill, &line, &i)))
			return (0);
		ft_strdel(&line);
	}
	ft_rescue_memory(&fill);
	return (0);
}
