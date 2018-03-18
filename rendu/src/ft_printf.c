/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:20:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/17 14:38:59 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*format_lst;
	t_format	*first;
	int			octet;

	va_start(ap, format);
	format_lst = ft_parse((char *)format);
	first = format_lst;
	octet = 0;
	while (format_lst)
	{
		ft_type_tostring(format_lst, ap);
		ft_width_tostring(format_lst);
		ft_preci_tostring(format_lst);
		ft_putstr((char *)format_lst->tostring);
		octet += format_lst->len;
		format_lst = format_lst->next;
	}
	//puttformat(first);
	va_end(ap);
	ft_del_format_lst(first);
	return (octet);
}