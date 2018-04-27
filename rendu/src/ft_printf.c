/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:20:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 17:29:27 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*f;
	t_format	*first;
	int			octet;

	va_start(ap, format);
	first = ft_parse((char *)format);
	
	f = first;
	octet = 0;
	//ft_putwstr_fd(wstr, 1);
	while (f)
	{
		if (ft_type_tostring(f, ap) == -1)
		{
			ft_del_format_lst(first);
			return (-1);
		}
		ft_preci_tostring(f);
		ft_flags_tostring(f);
		ft_width_tostring(f);
		f = f->next;
	}
	f = first;
//	if (ft_checkstr(f) == 0)
//		return (-1);
	while (f)
	{
		// cas particulier  avec "% Zooo" sans argument
		if (!f->tostring && !f->type)
		{
			char *print = f->form;
			while (*print == ' ')
				print++;
			ft_putstr_fd(print, 1);
			octet += ft_strlen(print);
		}
		else
			ft_putstr_fd(f->tostring, 1);
		//cas particulier avec "%c", 0
		if ((f->type == 'c' || f->type == 'C') && f->arg == NULL)
		{
			ft_putchar_fd(0, 1);
			octet++;
		}
		octet += ft_strlen(f->tostring);
		f = f->next;
	}
	//puttformat(first);
	va_end(ap);
	ft_del_format_lst(first);
	return (octet);
}