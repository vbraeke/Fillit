/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 20:20:45 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/15 20:20:47 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ismatch(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}


char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	if (s1)
	{
		while (s1[i] != '\0' && i <= (n - ft_strlen(s2)))
		{
			if (ft_ismatch(&s1[i], s2))
				return ((char *)s1 + i);
			i++;
		}
	}
	return (NULL);
}