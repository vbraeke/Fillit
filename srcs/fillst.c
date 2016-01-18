/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 00:02:15 by julio             #+#    #+#             */
/*   Updated: 2016/01/18 13:05:22 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_allused(t_group *grp)
{
	t_tetrim	*curr;
	int			used;

	curr = grp->premier;
	used = 0;
	while (curr != NULL)
	{
		if (curr->used)
			used++;
		curr = curr->next;
	}
	if (used == grp->size)
		return (1);
	return (0);
}

void	ft_get_map(t_group *grp)
{
	int i;
	int j;

	i = -1;
	grp->map = (char **)malloc(sizeof(char *) * grp->maplen + 1);
	while (++i < grp->maplen)
	{
		j = -1;
		grp->map[i] = (char *)malloc(sizeof(char) * grp->maplen + 1);
		while (++j < grp->maplen)
			grp->map[i][j] = '.';
		grp->map[i][j] = '\0';
	}
	grp->map[i] = NULL;
}

void	show_tab(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
	}
}

void	insert(t_group *grp, char id)
{
	t_tetrim	*new;

	new = (t_tetrim *)malloc(sizeof(t_tetrim));
	if (!(new))
		exit(0);
	new->id = id;
	new->used = false;
	new->next = NULL;
	if (grp->curr != NULL)
		grp->curr->next = new;
	else
		grp->premier = new;
	grp->curr = new;
}

t_group	*init(void)
{
	t_group *grp;

	grp = (t_group*)malloc(sizeof(t_group));
	if (!(grp))
		exit(0);
	grp->premier = NULL;
	grp->curr = NULL;
	grp->save = NULL;
	return (grp);
}
