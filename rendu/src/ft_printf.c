/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/28 12:20:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/06 14:46:13 by fablin      ###    #+. /#+    ###.fr     */
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
	ft_printf("%d", -10);
	printf("%d", -10);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_format	*format_lst;
	t_format	*first;

	va_start(ap, format);
	format_lst = ft_parse((char *)format, ap);

	first = format_lst;
/*	while (format_lst)
	{
		format_lst = format_lst->next;
	}
	*/
	puttformat(first);
	va_end(ap);
	return (0);
}