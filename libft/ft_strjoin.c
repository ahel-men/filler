/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:56:46 by ahel-men          #+#    #+#             */
/*   Updated: 2019/04/10 02:34:09 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		t;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	t = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (t + 1))))
		return (NULL);
	while (s1[i])
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	return (str);
}
