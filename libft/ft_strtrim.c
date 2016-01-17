/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 16:17:39 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/13 16:17:41 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_strtrim(char const *s)
{
	int i;
	size_t len;
	char *str;

	i 	= 0;
	len = ft_lennospace(s);
	str = ft_strnew(len);
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			str[len] = s[i];
			len++;
		}
		i++;
	}
	str[len] = '\0';
	return (str);
}

int		main(void)
{
	char joe[] = "\t\n  \tAAA \t BBB\t\n  \t";
	printf("%s\n", ft_strtrim(joe));
	return (0);
}*/

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int		ft_without_space_len(const char *str)
{
	unsigned int space_len;
	unsigned int len;
	unsigned int i;

	space_len = 0;
	i = 0;
	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		while (str[i] && ft_isspace(str[i++]))
			space_len++;
		if (i < len)
		{
			i = len - 1;
			while (str[i] && ft_isspace(str[i--]))
				space_len++;
		}
	}
	return (len - space_len);
}

char	*ft_strtrim(char const *s)
{
	char			*result;
	unsigned int	i;
	unsigned int	len;

	if (s)
	{
		len = ft_without_space_len(s);
		if (len > 0)
		{
			i = 0;
			result = ft_strnew(len);
			if (result)
			{
				while (s[i] && ft_isspace(s[i]))
					i++;
				if (!*(s + i))
					return (ft_strnew(0));
				ft_strncpy(result, &s[i], len);
			}
			return (result);
		}
	}
	return (ft_strnew(0));
}

/*int		main(void)
{
	char joe[] = "\t\n  \tAAA \t BBB\t\n  \t";
	printf("%s\n", ft_strtrim(joe));
	return (0);
}*/