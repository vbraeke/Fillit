/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 19:38:56 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/16 14:17:16 by vbraeke          ###   ########.fr       */
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

void	ft_reset_map(group *grp)
{
	int i;

	i = 0;
	while (++i < grp->mapLEN)
	{
		if (grp->map[i])
		{
			free(grp->map[i]);
			grp->map[i] = NULL;
		}
	}
	ft_get_map(grp);
}

void	ft_save(group *grp)
{
	int		i;
	tetrim	*curr;

	i = -1;
	curr = grp->premier;
	grp->save = (char **)malloc(sizeof(char *) * ft_sqlen(grp->map) + 1);
	while (grp->map[++i])
		grp->save[i] = ft_strdup(grp->map[i]);
	grp->save[i] = NULL;
	grp->mapLEN -= 1;
	ft_reset_map(grp);
	while (curr != NULL)
	{
		curr->used = false;
		curr = curr->next;
	}
	ft_tracking(grp, grp->premier);
}

void	ft_save_check(group *grp)
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
		printf("BETTER_SQ_FOUND with sqLEN = %d\n", ft_sqlen(grp->map));
		ft_save(grp);
	}
	else if (!(grp->save))
	{
		printf("FIRST_SQ with sqLEN = %d\n", ft_sqlen(grp->map));
		ft_save(grp);
	}
}
