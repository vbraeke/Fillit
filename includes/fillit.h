/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 16:55:14 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/16 16:55:05 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

# define BUFFER (27*21) //

typedef int bool;
enum {false, true};

typedef struct		tetrim
{
	int				x;
	int				y;
	char			id;
	char			**shape;
	char			*coord;
	bool			used;
	struct tetrim	*next;
}					tetrim;

typedef struct  group
{
    int 	size;
    int 	mapLEN;
    char	**map;
    char	**save;
    struct tetrim *premier;
    struct tetrim *curr;
}				group;

typedef struct	count
{
	int		count;
	int		i;
	int		j;
	int		alph;
}				count;

group 	*init();
void	ft_iserror();
void	pre_launcher(int argc, char **argv);
void	launcher(group *_group, char *pack);
void 	insert(group *grp, char id);
void 	show_tetrim(group *grp);
void 	show_tab(char *name, char **tab);
void	ft_tracking(group *grp, tetrim *curr);
void	ft_save_check(group *grp);
void	ft_get_map(group *grp);
int		ft_allused(group *grp);
int 	count_dot_x(char *line);
int		check(tetrim *curr);

#endif
