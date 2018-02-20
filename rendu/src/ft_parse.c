/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 11:27:02 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 14:49:06 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"



char	*ft_find_type(char *str)
{
	char	*end;
	
	end = str;
	while (*end)
	{
		if (*end == 's' || *end == 'S' || *end == 'p' || *end == 'd' ||
			*end == 'D' || *end == 'i' || *end == 'o' || *end == 'u' ||
			*end == 'U' || *end == 'x' || *end == 'X' || *end == 'c' ||
			*end == 'C')
			return (end);
		end++;
	}
	return (NULL);
}

void	ft_format_push(t_format **alst, t_format *new)
{
	if (*alst)
		ft_format_push(&(*alst)->next, new);
	else
		*alst = new;
}


// segments format into sub strings as "abc" or "%s"
t_format	*ft_get_format_lst(char *format)
{
	t_format	*format_lst;
	char		*substr;
	char		*begin;
	char		*end;
	
	begin = format;
	end  = format;
	format_lst = NULL;
	while(*begin)
	{
		substr = NULL;
		// add string of type "%s" to the return value
		if (*begin == '%')
		{
			end = ft_find_type(begin) + 1;
		}
		// add string of type "abc" to the return value
		else
		{
			if ((substr = ft_strchr(begin, '%')) == NULL)
				end = begin + ft_strlen(begin);
			else
				end = substr;
		}
		substr = ft_strsub(begin, 0, end - begin);
		ft_format_push(&format_lst, ft_new_format(substr));
		free(substr);
		begin = end++;
	}
	return (format_lst);
}

t_format	*ft_parse(char *format)
{
	t_format	*format_lst;
	
	format_lst = ft_get_format_lst(format);
	return (format_lst);
}