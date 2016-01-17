/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:19:09 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/15 19:19:12 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	while (src[i] && i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	//if (dst_len < size)
		dst[i] = '\0';
	return (dst_len + ft_strlen(src));
}
