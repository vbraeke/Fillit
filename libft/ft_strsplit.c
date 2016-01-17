/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:00:52 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/13 18:00:54 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill(char const *s, char c, size_t idx, char *split)
{
	unsigned int word;
	unsigned int letter;
	unsigned int i;

	word = 0;
	letter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				if (word == idx)
				{
					split[letter] = s[i];
					letter++;
				}
				i++;
			}
			split[letter] = '\0';
			word++;
		}
		i++;
	}
}

unsigned int	ft_letter(char const *s, char c,size_t idx)
{
	unsigned int word;
	unsigned int letter;
	unsigned int i;

	word = 0;
	letter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				if (word == idx)
					letter++;
				i++;
			}
			word++;
		}
		i++;
	}
	//printf("%zu letter\n", letter);
	return (letter);
}

unsigned int ft_wordnb(char const *s, char c)
{
	unsigned int word;
	unsigned int i;

	word 	= 0;
	i 		= 0;
	if (s && c)
	{
		if (s[0] && s[0] != c)
			word = 1;
		else
			word = 0;
		i++;
		while (s[0] && s[i] != '\0')
		{
			if (s[i - 1] == c && s[i] != c)
				word++;
			i++;
		}
	}
	return (word);
}

char	**ft_strsplit(char const *s, char c)
{
	char **split;
	unsigned int  word;
	unsigned int letter;
	unsigned int i;

	i = 0;
	split = NULL;
	if (s && c)
	{
		word = ft_wordnb(s, c);
		//printf("%zu\n", word);
		split = (char **)malloc(sizeof(char *) * word);
		if (split == NULL)
			return (NULL);
		while (i < word)
		{
			letter = ft_letter(s, c, i);
			split[i] = (char *)malloc(sizeof(char) * (letter + 1));
			ft_fill(s, c, i, split[i]);
			if (split[i] == NULL)
				return (NULL);
			i++;
		}
		return (split);
	}
	return (NULL);
}

/*int main(void)
{
	char tosplit[] = "0salut0les**0etudiants0***";
	char **split;

	split = ft_strsplit(tosplit, '0');

		printf("%s\n", split[0]);
		printf("%s\n", split[1]);
		printf("%s\n", split[2]);
		printf("%s\n", split[3]);
		printf("%s\n", split[4]);
		printf("%s\n", split[5]);
		printf("%s\n", split[6]);
	
	return (0);
}*/