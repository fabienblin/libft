/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_preci_tostring.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 15:14:08 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 18:14:16 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_preci_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;

	if (f->preci > 0 && !(f->type == 'c' || f->type == 'C'))
	{
		tmp_len = f->preci - ft_strlen(f->tostring);
		if (f->type == 'p')
			tmp_len += 2;
		if ((f->type == 's' || f->type == 'S') && f->preci < (int)ft_strlen(f->tostring))
		{
			f->tostring = ft_strrealloc(&f->tostring, f->preci);
		}
		else if (!(f->type == 's' || f->type == 'S') && f->preci > (int)ft_strlen(f->tostring))
		{
			tmp = ft_strgen('0', tmp_len);
			if (ft_strchr(f->tostring, '-'))
			{
				tmp = ft_strjoinfree(ft_strdup("-"), tmp);
				*ft_strchr(f->tostring, '-') = '0';
			}
			f->tostring = ft_strjoinfree(tmp, f->tostring);
		}
	}
}
