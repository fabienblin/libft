/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:20:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 17:24:43 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

wchar_t		*ft_convert_str_to_unicode(char *str)
{
	wchar_t	*new;
	int		new_len;
	int		i;

	new_len = ft_strlen(str);
	new = (wchar_t *)malloc(sizeof(wchar_t) * new_len + 1);
	new[new_len] = 0;
	i = 0;
	while(str[i])
	{
		new[i] = str[i];
		i++;
	}
	return (new);
}

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
	//ft_putwstr_fd(wstr, 1);
	while (f)
	{
		ft_type_tostring(f, ap);
		ft_preci_tostring(f);
		ft_width_tostring(f);
		//ft_flags_tostring(f);
		
		ft_putstr(f->tostring);
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