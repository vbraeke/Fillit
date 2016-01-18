/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillia.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:37:54 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/18 12:37:57 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_iserror(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	check_next(char *pack, int p)
{
	while (pack[p] && pack[p] != '#')
		p++;
	if (getdiez(&pack[p]) != 4 && !getdiez(&pack[p + 5]))
		ft_iserror();
}

int		count_dot_x(char *line)
{
	int i;

	i = 0;
	while (line[i] == '.' && line[i] != '\0')
		i++;
	return (i);
}

void	coord_xy(t_group *grp, char **shape, int y)
{
	int	i;
	int j;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		if (shape[i][0] == '\0')
			shape[i] = NULL;
		else
		{
			while (++j < 5)
			{
				if (i == 0 && ft_isalpha(shape[i][j]))
					grp->curr->x += 1;
			}
			j = -1;
		}
	}
	shape[i] = NULL;
	grp->curr->y = y;
}

int		getdiez(char *line)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (line[++i] != '\n')
	{
		if (line[i] == '#')
			count++;
	}
	return (count);
}
