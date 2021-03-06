/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:04:09 by ahel-men          #+#    #+#             */
/*   Updated: 2019/04/19 23:34:19 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((!s1 && !s2) || !n)
		return (1);
	if (s1 && s2)
		while (*s1 == *s2 && n)
		{
			n--;
			if ((!*s1 && !*s2) || !n)
				return (1);
			s1++;
			s2++;
		}
	return (0);
}
