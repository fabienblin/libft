/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 11:27:02 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 14:36:33 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_parse(const char *input)
{
	t_list		*ouput;
	t_list		*new_lst;
	t_format	*new_format;
	char		*sub;

	while (*input)
	{
		sub = ft_strsub(input, start, len)
		new_format = ft_new_format();
		new_lst = ft_lstnew(new_format, sizeof(t_format));
		output = ft_lstpush();
		input++;
	}
	return (output);
}
