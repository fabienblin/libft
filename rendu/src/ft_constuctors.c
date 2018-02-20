/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_constuctors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 13:09:01 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 10:21:38 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"



t_format	*ft_new_format(char *substr)
{
	t_format	*new_format;
	char		*c;

	if (!(new_format = (t_format *)malloc(sizeof(t_format))))
		return (NULL);
	ft_bzero(new_format, sizeof(t_format));
	if (substr && *substr == '%')
	{
		c = substr + 1;
		c = ft_set_flags(c, new_format);
		c = ft_set_width(c, new_format);
		c = ft_set_preci(c, new_format);
		c = ft_set_size(c, new_format);
		c = ft_set_type(c, new_format);
	}
	else if (substr && *substr != '%')
		new_format->tostring = ft_strdup(substr);
	return (new_format);
}