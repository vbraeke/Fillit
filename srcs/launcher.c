/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 18:53:11 by julio             #+#    #+#             */
/*   Updated: 2016/01/16 18:35:12 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	coord_xy(group *grp, char **shape, int y)
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

int		getdiez(char *pack)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (pack[++i] != '\n')
	{
		if (pack[i] == '#')
			count++;
	}
	return (count);
}

void	fill_grp(char *pack, group *grp, int *p)
{
	int		i;
	int		j;
	int		y;
	int		x;
	tetrim	*curr;

	i = -1;
	y = 0;
	curr = grp->curr;
	curr->shape = (char **)malloc(sizeof(char *) * 5);
	while (++i < 4)
	{
		x = 0;
		j = -1;
		curr->shape[i] = (char *)malloc(sizeof(char) * 5);
		while (++j < 5)
		{
			if (pack[*p] == '.' && getdiez(&pack[*p]) > 0 &&
				((y > 0 && pack[*p - 5] == '#') ||
				(y > 1 && (pack[*p - 5] == '#' || pack[*p - 10] == '#')) ||
				(y < 3 && pack[*p + 5] == '#') ||
				(y < 2 && (pack[*p + 5] == '#' || pack[*p + 10] == '#'))))
			{
				curr->shape[y][x] = pack[*p];
				x++;
			}
			else if (pack[*p] == '#')
			{
				curr->shape[y][x] = curr->id;
				x++;
			}
			*p += 1;
		}
		curr->shape[y][x] = '\0';
		if (x != 0)
			y++;
	}
	*p += 1;
	coord_xy(grp, curr->shape, y);
}

int		check_sq(tetrim *curr, int i, int j, int count)
{
	if (curr->shape[i][j + 1] && ft_isalpha(curr->shape[i][j + 1]))
		count++;
	if (j > 0 && curr->shape[i][j - 1] && ft_isalpha(curr->shape[i][j - 1]))
		count++;
	if (i > 0 && curr->shape[i - 1][j] && ft_isalpha(curr->shape[i - 1][j]))
		count++;
	if (i < curr->y - 1 && curr->shape[i + 1][j] &&
			ft_isalpha(curr->shape[i + 1][j]))
		count++;
	return (count);
}

int		ft_check_tetrim(tetrim *curr)
{
	int	i;
	int	j;
	int	count;
	int	alph;

	printf("g");
	i = -1;
	count = 0;
	alph = 0;
	while (curr != NULL && curr->shape[++i])
	{
		j = -1;
		while (curr->shape[i][++j])
		{
			if (ft_isalpha(curr->shape[i][j]))
			{
				alph++;
				count = check_sq(curr, i, j, count);
			}
		}
	}
	if (alph == 4 && (count == 6 || (count == 8 && (curr->x == curr->y)
		&& (!count_dot_x(curr->shape[0]) && !count_dot_x(curr->shape[1])))))
		return (1);
	return (0);
}

void	launcher(group *grp, char *pack)
{
	int i;
	int p;

	i = -1;
	p = 0;
	while (++i < grp->size)
	{
		insert(grp, ('A' + i));
		fill_grp(pack, grp, &p);
		if (!ft_check_tetrim(grp->curr))
			ft_iserror();
	}
	ft_tracking(grp, grp->premier);
}
