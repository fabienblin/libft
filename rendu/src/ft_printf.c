/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:20:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 17:32:01 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int main (int argc, char **argv)
{
/*	if (argc != 2)
	{
		printf("Usage : %s format", argv[0]);
	}
	
*/	
	(void)argc;
	(void)argv;
	ft_printf("abc %s%s", "hey", NULL);
	return (0);
}

void	ft_format_tostring(t_format *format_lst, va_list ap)
{
	char	t;
	
	t = format_lst->type;
	if (t == 's' || t == 'S')
		format_lst->tostring = ft_strdup(va_arg(ap, char *));
	else if (t == 'p')
		format_lst->tostring = ft_strdup(ft_itoa_base((int)va_arg(ap, void *), 16));
	else if (t == 'd' || t == 'D')
		format_lst->tostring = ft_strdup(ft_itoa((int)va_arg(ap, int)));
	else if (t == 'i')
		format_lst->tostring = ft_strdup(ft_itoa((int)va_arg(ap, int)));
	else if (t == 'o' || t == 'O')
		format_lst->tostring = ft_strdup(ft_itoa((int)va_arg(ap, unsigned int)));
	else if (t == 'u' || t == 'U')
		format_lst->tostring = ft_strdup(ft_itoa((int)va_arg(ap, unsigned int)));
	else if (t == 'x' || t == 'X')
		format_lst->tostring = ft_strdup(ft_itoa((int)va_arg(ap, unsigned int)));
	else if (t == 'c' || t == 'C')
		format_lst->tostring = ft_strdup(va_arg(ap, unsigned char));
	if (format_lst->tostring == NULL)
		format_lst->tostring = ft_strdup("(null)");
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*format_lst;
	t_format	*first;

	va_start(ap, format);
	format_lst = ft_parse((char *)format);
	
	first = format_lst;
	
	
	while (format_lst)
	{
		ft_format_tostring(format_lst, ap);
		format_lst = format_lst->next;
	}
	puttformat(first);
	va_end(ap);
	return (0);
}
