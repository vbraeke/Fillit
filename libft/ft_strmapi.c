/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:15:44 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/12 14:15:46 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
	
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char 	*map;

	i = 0;
	map = ft_strnew(ft_strlen(s));
	if (map)
	{
		while (s[i] != '\0')
		{
			map[i] = f(i, s[i]);
			i++;
		}
	}
	return (map);
}
