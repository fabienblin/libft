/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parse.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 11:27:02 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/09 17:32:25 by fablin      ###    #+. /#+    ###.fr     */
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
			*end == 'D' || *end == 'i' || *end == 'o' || *end == 'O' ||
			*end == 'u' || *end == 'U' || *end == 'x' || *end == 'X' ||
			*end == 'c' || *end == 'C')
			return (end);
		end++;
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
	
	begin = format;
	end  = format;
	format_lst = NULL;
	while (*begin)
	{
		substr = NULL;
		if (*begin == '%')
			end = ft_find_type(begin) + 1;
		else if ((substr = ft_strchr(begin, '%')) == NULL)
			end = begin + ft_strlen(begin);
		else
			end = substr;
		substr = ft_strsub(begin, 0, end - begin);
		ft_format_push(&format_lst, ft_new_format(substr));
		free(substr);
		begin = end++;
	}
	return (format_lst);
}