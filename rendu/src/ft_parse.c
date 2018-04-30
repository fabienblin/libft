/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 11:27:02 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 16:36:14 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"



char	*ft_find_type(char *str)
{
	char	*type;
	
	type = str + 1;
	while (*type)
	{
		if (*type == 's' || *type == 'S' || *type == 'p' || *type == 'd' ||
			*type == 'D' || *type == 'i' || *type == 'o' || *type == 'O' ||
			*type == 'u' || *type == 'U' || *type == 'x' || *type == 'X' ||
			*type == 'c' || *type == 'C' || *type == '%')
			return (type + 1);
		type++;
	}
	return (NULL);
}

void	ft_format_push(t_format **alst, t_format *new)
{
	if (!*alst)
		*alst = new;
	else
		ft_format_push(&(*alst)->next, new);
}


// segments format into sub strings as "abc" or "%s"
// then returns list of pourly formated strings
t_format	*ft_parse(char *format)
{
	t_format	*format_lst;
	char		*substr;
	char		*begin;
	char		*end;
	char		*tmp;
	
	begin = format;
	end  = format;
	format_lst = NULL;
	while (*begin)
	{
		substr = NULL;
		tmp = ft_strchr(begin, '%');
		if (*begin == '%')
		{
			if (!(end = ft_find_type(begin)))
				end = begin + ft_strlen(begin);
		}
		else if (tmp == NULL)
			end = begin + ft_strlen(begin);
		else
			end = tmp;
		substr = ft_strsub(begin, 0, end - begin);
		ft_format_push(&format_lst, ft_new_format(substr));
		free(substr);
		begin = end++;
	}
	return (format_lst);
}