/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:20:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 16:25:43 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_tostring(t_format *f, va_list ap)
{
	t_format	*first;

	first = f;
	while (f)
	{
		if (ft_type_tostring(f, ap) == -1)
			return (-1);
		if (f->preci >= 0)
			ft_preci_tostring(f);
		ft_flags_tostring(f);
		if (f->width > 0)
			ft_width_tostring(f);
		f = f->next;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*f;
	int			octet;

	va_start(ap, format);
	f = ft_parse((char *)format);
	if (ft_tostring(f, ap) == -1)
	{
		ft_del_format_lst(f);
		return (-1);
	}
	octet = ft_puttostring_fd(f, 1);
	va_end(ap);
	ft_del_format_lst(f);
	return (octet);
}
