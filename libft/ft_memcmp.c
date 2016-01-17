/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:21:38 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/11 17:21:40 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;

	i = 0;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return(tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}

/*int		main(void)
{
	const char s1[] = "OLA";
	const char s2[] = "OLE";

	printf("%d\n", ft_memcmp(s1, s2, 3));
	return (0);
}*/