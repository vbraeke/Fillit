/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:35:35 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/11 13:35:38 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;
	unsigned char *str;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

/*int		main(void)
{
	char joe[50] = "YEEPA";
	printf("%s\n", ft_memset(joe + 2, '@', 2));
	printf("%s\n", memset(joe + 2, '@', 2));
	return (0);
}*/