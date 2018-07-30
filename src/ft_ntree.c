/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ntree.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 17:02:47 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/29 20:12:06 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_ntree		*ft_newntree(char *name, t_point *coord, int depth, t_list *sons)
{
	t_ntree	*new;

	if (!(new = (t_ntree *)malloc(sizeof(t_ntree))))
		return (NULL);
	ft_bzero(new, sizeof(t_ntree));
	new->name = name;
	new->coord = coord ? coord : ft_newpoint(0, 0);
	new->depth = depth;
	new->sons = sons;
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
		ft_lstdel(&(*t)->sons, delson);
		ft_delpoint(&(*t)->coord);
		free(*t);
		*t = NULL;
	}
}
