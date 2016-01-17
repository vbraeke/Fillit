/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:36:36 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/11 13:36:38 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 /*void	*ft_memmove(void *dst, const void *src, size_t len)
 {
 	size_t i;
 	unsigned char *dst_tmp;
 	unsigned char *src_tmp;

 	i = 0;
 	dst_tmp = (unsigned char *)dst;
 	src_tmp = (unsigned char *)src;
 	while (i < len)
 	{
 		dst_tmp[i] = src_tmp[i];
 		i++;
 	}
 	return (dst);
 }

int		main(void)
{
	char dst[] = "old";
	const char src[] = "newoeod";

	printf("%s\n", ft_memmove(dst, src, 6));
	return (0);
}*/

	void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*str;

	if (!dest || !src)
		return (NULL);
	str = (unsigned char*)malloc(sizeof(*str) * n);
	ft_memcpy(str, src, n);
	ft_memcpy(dest, str, n);
	free(str);
	return (dest);
}