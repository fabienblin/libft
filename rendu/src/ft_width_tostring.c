/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_width_tostring.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 15:14:12 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 15:14:35 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;
	
	tmp = NULL;
	
	
	tmp_len = f->width - ft_strlen(f->tostring);
	if ((f->type == 'c' || f->type == 'C') && f->arg == NULL)
		tmp_len--;
	if (tmp_len > 0 && f->preci <= 0)
	{
		tmp = ft_strgen(' ', tmp_len);
		if (f->flags[1] == '-')
			f->tostring = ft_strjoinfree(f->tostring, tmp);
		else
			f->tostring = ft_strjoinfree(tmp, f->tostring);
	}
	if (f->preci > 0)
	{
		tmp_len = f->width - ft_strlen(f->tostring);
		if (f->flags[1] == '-')
			f->tostring = ft_strjoinfree(f->tostring, ft_strgen(' ', tmp_len));
		else
			f->tostring = ft_strjoinfree(ft_strgen(' ', tmp_len), f->tostring);
		
	}
	char *p;
	if ((p = ft_strchr(f->tostring, '+')) && (p[-1] == '0') && (f->type == 'd' || f->type == 'D' || f->type == 'i'))
	{
		f->tostring[0] = '+';
		*p = '0';
	}
	char *m = ft_strchr(f->tostring, '-');
	if ((m = ft_strchr(f->tostring, '-')) && (m[-1] == '0') && (f->type == 'd' || f->type == 'D' || f->type == 'i'))
	{
		f->tostring[0] = '-';
		*m = '0';
	}
}
