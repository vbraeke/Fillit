/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 01:07:51 by julio             #+#    #+#             */
/*   Updated: 2016/01/16 14:21:17 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_try(group *grp, tetrim *curr, int pos_x, int pos_y)
{
	int	i;
	int j;
	int check;

	i = -1;
	check = 0;
	while (curr->shape[++i] && grp->map[pos_y + i])
	{
		j = -1;
		while (curr->shape[i][++j] && grp->map[pos_y + i][pos_x + j])
		{
			if (curr->shape[i][j] == '.' && i == 0
				&& ft_try(grp, curr, pos_x - 1, pos_y))
				pos_x -= 1;
			else if (curr->shape[i][j] != '.' &&
				grp->map[pos_y + i][pos_x + j]
				&& grp->map[pos_y + i][pos_x + j] == '.')
				check++;
		}
	}
	if (check == 4)
		return (1);
	return (0);
}

void	ft_add_tetrim(group *grp, tetrim *curr, int pos_x, int pos_y)
{
	int	i;
	int j;

	i = -1;
	while (curr->shape[++i] && grp->map[pos_y + i])
	{
		j = -1;
		while (curr->shape[i][++j] && grp->map[pos_y + i][pos_x + j])
		{
			if (curr->shape[i][j] == '.' && i == 0
				&& ft_try(grp, curr, pos_x - 1, pos_y))
				pos_x -= 1;
			else if (curr->shape[i][j] != '.' &&
				grp->map[pos_y + i][pos_x + j]
				&& grp->map[pos_y + i][pos_x + j] == '.')
				grp->map[pos_y + i][pos_x + j] = curr->shape[i][j];
		}
	}
	curr->used = true;
}

void	ft_rm_tetrim(group *grp, tetrim *curr)
{
	int x;
	int y;

	y = -1;
	while (++y < grp->mapLEN)
	{
		x = -1;
		while (++x < grp->mapLEN)
			if (grp->map[y][x] == curr->id)
				grp->map[y][x] = '.';
	}
	curr->used = false;
}

int		ft_check(group *grp, tetrim *curr, int x, int y)
{
	int dot_rest;

	dot_rest = count_dot_x(&grp->map[y][x]);
	if (curr && curr->x > dot_rest)
		return (dot_rest);
	else if (curr && !curr->used && ft_try(grp, curr, x, y))
	{
		ft_add_tetrim(grp, curr, x, y);
		ft_tracking(grp, curr->next);
		ft_rm_tetrim(grp, curr);
	}
	return (0);
}

void	ft_tracking(group *grp, tetrim *curr)
{
	int x;
	int y;

	y = -1;
	if (ft_allused(grp))
		ft_save_check(grp);
	while (++y < grp->mapLEN)
	{
		x = -1;
		while (++x < grp->mapLEN)
			x += ft_check(grp, curr, x, y);
	}
	if (curr->id == 'A')
	{
		show_tab("CURR_SAVE", grp->save);
		exit(0);
	}
}
