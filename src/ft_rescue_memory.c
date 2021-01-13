/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rescue_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:24:50 by ahel-men          #+#    #+#             */
/*   Updated: 2020/11/08 10:22:47 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	ft_rescue_memory(t_filler *fill)
{
	ft_free_2d_array(fill->map);
	ft_free_2d_array(fill->piece);
	ft_free_2d_int_array(fill->int_map, fill->map_height);
	ft_free_2d_int_array(fill->asterisks_xy, fill->asterisks_counter);
}
