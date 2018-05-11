/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puttostring.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 21:01:32 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 16:50:22 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"



int	ft_puttostring_fd(t_format *f, int fd)
{
	int			octet;

	octet = 0;
	while (f)
	{
		if (f->err || (f->next && f->next->err))
			return (-1);
		if (f->type == 'x' || f->type == 'p')
			f->tostring = ft_strtolower(f->tostring);
		// cas particulier  avec "% Zooo" sans argument
		if (!f->tostring && !f->type)
		{
			char *print = f->form;
			while (*print == ' ')
				print++;
			ft_putstr_fd(print, fd);
			octet += ft_strlen(print);
		}
		//cas particulier avec "%c", 0
		else if ((f->type == 'c' || f->type == 'C') && f->arg == NULL)
		{
			if (f->flags[1] != '-')
				ft_putstr_fd(f->tostring, fd);
			ft_putchar_fd(0, fd);
			octet++;
			if (f->flags[1] == '-' && f->width > 0)
				ft_putstr_fd(f->tostring, fd);
		}
		else
			ft_putstr_fd(f->tostring, fd);

		octet += ft_strlen(f->tostring);
		f = f->next;
	}
	return (octet);
}
