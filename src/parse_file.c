/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 09:47:23 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 12:48:17 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

int	ft_check_which_player(t_filler *fill, char *line, t_bool *checked)
{
	if (ft_strnequ("$$$ exec p", line, 10))
	{
		if (line[10] == '1')
			fill->player = 1;
		else if (line[10] == '2')
			fill->player = 2;
		else
		{
			ft_putendl("player detection error");
			get_next_line(0, &line, 1);
			ft_strdel(&line);
			return (0);
		}
		*checked = TRUE;
	}
	else
	{
		ft_putendl("player detection error");
		get_next_line(0, &line, 1);
		ft_strdel(&line);
		return (0);
	}
	ft_strdel(&line);
	return (1);
}

int	ft_check_dimensions(t_filler *fill, char *line)
{
	fill->h_map_index = 0;
	if (fill->map)
	{
		if (ft_is_bad_dimention(*fill))
		{
			ft_putendl("bad map's dementions");
			ft_rescue_memory(fill);
			ft_strdel(&line);
			return (0);
		}
	}
	ft_store_map_demensions(fill, line, 8, 9);
	return (1);
}

int	store_map(t_filler *fill, char **line)
{
	int res;

	while ((res = get_next_line(0, line, 0)) > 0
			&& !ft_strnequ("Piece ", *line, 6))
	{
		if (ft_strnequ("    0", *line, 5))
		{
			ft_strdel(line);
			res = get_next_line(0, line, 0);
		}
		if (!(ft_stock_map(*line, fill)))
		{
			ft_putendl("map error");
			ft_rescue_memory(fill);
			ft_strdel(line);
			return (0);
		}
		ft_strdel(line);
	}
	return (1);
}

int	ft_allocate_map_array(t_filler *fill, char **line)
{
	if (!ft_detect_demensions_error(fill->map_height,
				fill->map_width, line))
		return (0);
	if (!(fill->map = allocate_char_2d_array(fill->map_height,
					fill->map_width)))
		return (0);
	fill->first_width = fill->map_width;
	fill->first_height = fill->map_height;
	ft_strdel(line);
	if (get_next_line(0, line, 0) <= 0)
	{
		ft_strdel(line);
		if (get_next_line(0, line, 0) <= 0)
			ft_putendl("file error");
		ft_rescue_memory(fill);
		ft_strdel(line);
		return (0);
	}
	return (1);
}

int	ft_allocate_piece(t_filler *fill, char **line, int *i)
{
	fill->h_piece_index = 0;
	if (fill->piece)
	{
		ft_free_2d_array(fill->piece);
		ft_free_2d_int_array(fill->asterisks_xy, fill->asterisks_counter);
		fill->piece = NULL;
		fill->asterisks_counter = 0;
		*i = 0;
	}
	if (!fill->map || fill->h_map_index < fill->map_height)
	{
		ft_putendl("map error");
		ft_rescue_memory(fill);
		ft_strdel(line);
		return (0);
	}
	ft_store_piece_demensions(fill, *line, 6, 7);
	if (!ft_detect_demensions_error(fill->p_height, fill->p_width, line))
		return (0);
	if (!fill->piece)
		fill->piece = allocate_char_2d_array(fill->p_height, fill->p_width);
	ft_strdel(line);
	return (1);
}
