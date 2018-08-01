/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ntree.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 17:02:47 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/01 13:48:42 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_sons(t_list *sons)
{
	int	i;
	
	i = 0;
	while(sons)
	{
		sons = sons->next;
		i++;
	}
	return (i);
}

t_ntree		*ft_newntree(char *name, t_point *coord, int depth, t_list *sons)
{
	t_ntree	*new;

	if (!(new = (t_ntree *)malloc(sizeof(t_ntree))))
		return (NULL);
	ft_bzero(new, sizeof(t_ntree));
	new->name = name;
	new->coord = coord;
	new->depth = depth;
	new->sons = sons;
	if (sons)
		new->nbsons = ft_count_sons(sons);
	return (new);
}

void delson(void *son, size_t size)
{
	(void)size;
	if (son)
	{
		ft_delntree(((t_ntree *)son)->sons->content);
	}
}

void		ft_delntree(t_ntree **t)
{
	if (t && *t)
	{
		if ((*t)->name)
			ft_strdel(&(*t)->name);
		if ((*t)->sons)
			ft_lstdel(&(*t)->sons, delson);
		if ((*t)->coord)
			ft_delpoint(&(*t)->coord);
		free(*t);
		*t = NULL;
	}
}
