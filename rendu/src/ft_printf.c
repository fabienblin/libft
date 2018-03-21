/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:20:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/20 15:18:28 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*f;
	t_format	*first;
	int			octet;

	va_start(ap, format);
	f = ft_parse((char *)format);
	first = f;
	octet = 0;
	while (f)
	{
		ft_type_tostring(f, ap);
		ft_preci_tostring(f);
		ft_width_tostring(f);
		//ft_flags_tostring(f);
		if (f->type == 'x' || f->type == 'p')
			f->tostring = (void *)ft_strtolower((char *)f->tostring);
		ft_putstr((char *)f->tostring);
		octet += ft_strlen((char *)f->tostring);
		f = f->next;
	}
	//puttformat(first);
	va_end(ap);
	ft_del_format_lst(first);
	return (octet);
}