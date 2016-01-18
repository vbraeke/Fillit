/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prelauncher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 19:15:21 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/18 12:25:53 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetris_check(char *pac, int *count, int *valid, int dot_x)
{
	int i;

	i = -1;
	while (pac[++i])
	{
		dot_x++;
		*valid += 1;
		if (pac[i] == '.' || pac[i] == '#' || pac[i] == '\n')
		{
			if (pac[i] == '\n')
			{
				dot_x > 5 ? ft_iserror() : 0;
				dot_x = 0;
			}
			if (pac[i] == '\n' && (i + 1 - *count) % 5 != 0)
			{
				if ((pac[i + 1] != '.' && pac[i + 1] != '#') || (*valid != 21))
					ft_iserror();
				*valid = 0;
				*count += 1;
			}
		}
		else
			ft_iserror();
	}
}

void	tetris_dieze(char *pack, int count)
{
	int i;
	int diezes;

	diezes = 0;
	i = -1;
	while (pack[++i])
	{
		if (pack[i] == '#')
			diezes++;
		if (pack[i] == '\n' && (i + 1 - count) % 5 != 0)
		{
			if (diezes != 4)
				ft_iserror();
			diezes = 0;
			count++;
		}
	}
	if (diezes != 4)
		ft_iserror();
}

int		tetris_count(char *pack)
{
	int valid;
	int dot_x;
	int count;

	dot_x = 0;
	valid = 0;
	count = 0;
	tetris_dieze(pack, count);
	tetris_check(pack, &count, &valid, dot_x);
	count++;
	if (valid + 1 != 21)
		ft_iserror();
	return (count);
}

char	*ft_orc(char *file)
{
	int					fd;
	int					ret;
	char				*pack;

	if (!(pack = (char *)malloc(sizeof(char) * BUFFER)))
		return (NULL);
	if (!(fd = open(file, O_RDONLY)) || fd < 1)
		return (NULL);
	if (!(ret = read(fd, pack, BUFFER)))
		return (NULL);
	close(fd);
	return (pack);
}

void	pre_launcher(int argc, char **argv)
{
	t_group	*grp;
	char	*pack;

	if (!(pack = ft_orc(argv[1])) || argc != 2)
		ft_iserror();
	grp = init();
	grp->size = tetris_count(pack);
	grp->maplen = 12;
	ft_get_map(grp);
	launcher(grp, pack);
}
