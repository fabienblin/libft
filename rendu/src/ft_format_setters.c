/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format_setters.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 14:36:07 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 15:10:54 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_set_flags(char *c, t_format *f)
{
	int	i;

	if (c && f)
	{		
		i = 0;
		if (ft_strchr(c, '+'))
			f->flags[i++] = *c;
		if (ft_strchr(c, '-'))
			f->flags[i++] = *c;		
		if (ft_strchr(c, '0'))
			f->flags[i++] = *c;
		if (ft_strchr(c, '#'))
			f->flags[i++] = *c;
		if (ft_strchr(c, ' '))
			f->flags[i++] = *c;
	}
	return (c);
}

char		*ft_set_width(char *c, t_format *f)
{
	if (ft_isdigit(*c))
	{
		f->width = ft_atoi(c);
		while(ft_isdigit(*c))
			c++;
	}
	return (c);
}

char		*ft_set_preci(char *c, t_format *f)
{
	if (*c == '.')
	{
		c++;
		f->preci = ft_atoi(c);
		while(ft_isdigit(*c))
			c++;
	}
	return (c);
}

char		*ft_set_size(char *c, t_format *f)
{
	if (*c == 'h' || *c == 'l' || *c == 'j' || *c == 'z')
	{
		if (!ft_strcmp(c, "hh"))
			f->size = HH;
		else if (!ft_strcmp(c, "h"))
			f->size = H;
		else if (!ft_strcmp(c, "ll"))
			f->size = LL;
		else if (!ft_strcmp(c, "l"))
			f->size = L;
		else if (!ft_strcmp(c, "j"))
			f->size = J;
		else if (!ft_strcmp(c, "z"))
			f->size = Z;
		while (*c == 'h' || *c == 'l' || *c == 'j' || *c == 'z')
			c++;
	}
	return (c);
}

char		*ft_set_type(char *c, t_format *f)
{
	if (*c == 's' || *c == 'S' || *c == 'p' || *c == 'd' || *c == 'D' ||
		*c == 'i' || *c == 'o' || *c == 'u' || *c == 'U' || *c == 'x' ||
		*c == 'X' || *c == 'c' || *c == 'C')
	{
		f->type = *c;
		c++;
	}
	else
	 	f->type = 0;
	return (c);
}
