/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ntree.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/02 17:02:47 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/02 17:41:25 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.c"

t_ntree		*ft_newntree(t_point *coord, int nb, t_ntree *sons)
{
	t_ntree	*new;

	if (!(new = (t_ntree *)malloc(sizeof(t_ntree))))
		return (NULL);
	new->coord = coord ? coord : ft_newpoint(0, 0);
	new->nb = nb;
	new->sons = sons;
}

void		ft_delntree(t_ntree **t)
{
	int i;

	if (t && *t)
	{
		i = 0;
		while (i < (*t)->nb)
		{
			ft_delntree(&((*t)->sons[i]));
			i++;
		}
		free(*t);
		*t = NULL;
	}
}