/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   constuctors.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 13:09:01 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 14:34:27 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"



t_format	*ft_new_format(char *prcnt)
{
	t_format	*new_format;
	char		*c;
	int			i;

	i = 1;
	if (!(new_format = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	ft_bzero(new_format, sizeof(t_format));
	if (prcnt)
	{
		c = prcnt;
		c = ft_set_flags(c, new_format);
		c = ft_set_width(c, new_format);
		c = ft_set_preci(c, new_format);
		c = ft_set_size(c, new_format);
		c = ft_set_type(c, new_format);
	}
	return (new_format);
}