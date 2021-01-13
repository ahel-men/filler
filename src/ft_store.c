/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 09:59:17 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 10:29:04 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

char	**allocate_char_2d_array(int heigth, int width)
{
	char	**tab;
	int		i;

	i = -1;
	tab = NULL;
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (heigth + 1))))
		return (NULL);
	while (++i < heigth)
	{
		if (!(tab[i] = (char *)ft_memalloc(width + 1)))
			return (NULL);
	}
	tab[i] = 0;
	return (tab);
}

int		ft_define_number(char *str, t_filler *fill)
{
	int		i;
	char	*tmp;
	int		nb;

	i = 0;
	tmp = NULL;
	while (ft_isdigit(str[i]))
		i++;
	fill->index = i;
	str = ft_strsub(str, 0, i);
	nb = ft_atoi(str);
	ft_strdel(&str);
	return (nb);
}

int		ft_stock_map(char *line, t_filler *fill)
{
	char	*str;
	int		i;
	int		x;

	i = -1;
	x = -1;
	str = NULL;
	if (fill->h_map_index >= fill->map_height)
		return (0);
	while (line[++i])
		if (!ft_isdigit(line[i]))
			break ;
	str = &line[++i];
	i = 0;
	while (str[i])
	{
		if ((i >= fill->map_width) || (str[i] != 'X' && str[i] != 'x' &&
					str[i] != 'O' && str[i] != 'o' && str[i] != '.'))
			return (0);
		fill->map[fill->h_map_index][++x] = str[i++];
	}
	if (i < fill->map_width - 1)
		return (0);
	fill->h_map_index++;
	return (1);
}

int		ft_stock_piece(char *line, t_filler *fill)
{
	int		i;
	int		x;

	i = 0;
	x = -1;
	if (fill->h_piece_index >= fill->p_height)
		return (0);
	while (line[i])
	{
		if ((i >= fill->p_width) ||
				(line[i] != '*' && line[i] != '.'))
			return (0);
		if (line[i] == '*')
			fill->asterisks_counter++;
		fill->piece[fill->h_piece_index][++x] = line[i++];
	}
	if (i < fill->p_width - 1)
		return (0);
	fill->h_piece_index++;
	return (1);
}

void	ft_store_map_demensions(t_filler *fill, char *line, int i, int y)
{
	char	*str;

	str = &line[i];
	fill->map_height = ft_define_number(str, fill);
	str = &line[y + fill->index];
	fill->map_width = ft_define_number(str, fill);
}
