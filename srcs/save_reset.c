/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:38:56 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/18 13:06:17 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqlen(char **map)
{
	int i;
	int x;
	int y;

	i = -1;
	x = 0;
	y = 0;
	while (map[++i])
	{
		if (x < (int)ft_strlen(map[i]))
			x = (int)ft_strlen(map[i]);
		y++;
	}
	if (x > y)
		return (x);
	return (y);
}

void	ft_reset_map(t_group *grp)
{
	int i;

	i = 0;
	while (++i < grp->maplen)
	{
		if (grp->map[i])
		{
			free(grp->map[i]);
			grp->map[i] = NULL;
		}
	}
	ft_get_map(grp);
}

void	ft_save(t_group *grp)
{
	int			i;
	t_tetrim	*curr;

	i = -1;
	curr = grp->premier;
	grp->save = (char **)malloc(sizeof(char *) * ft_sqlen(grp->map) + 1);
	while (grp->map[++i])
		grp->save[i] = ft_strdup(grp->map[i]);
	grp->save[i] = NULL;
	grp->maplen -= 1;
	ft_reset_map(grp);
	while (curr != NULL)
	{
		curr->used = false;
		curr = curr->next;
	}
	ft_tracking(grp, grp->premier);
}

void	ft_save_check(t_group *grp)
{
	int i;

	i = -1;
	if (grp->save && (ft_sqlen(grp->map) < ft_sqlen(grp->save)))
	{
		while (grp->save[++i])
		{
			if (grp->save[i])
			{
				free(grp->save[i]);
				grp->save[i] = NULL;
			}
		}
		ft_save(grp);
	}
	else if (!(grp->save))
		ft_save(grp);
}
