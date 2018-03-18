/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_puttostring.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 21:01:32 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 22:48:13 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puttostring(t_format *f)
{
	int		s;
	char	t;
	
	s = f->size;
	t = f->type;
	if (s == HH && (t =='d' || t =='o' || t =='u' || t =='x'))
	;
	else if (s == H)
	;
	else if (s == LL)
	;
	else if (s == L && (t == 's' || t == 'd' || t == 'i' || t == 'o' || t == 'u'
			|| t == 'x' || t == 'c'))
			;
	else if (s == J)
	;
	else if (s == Z)
	;
	else
		;
}