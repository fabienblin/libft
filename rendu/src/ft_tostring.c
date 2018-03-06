/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tostring.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 15:16:17 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 11:06:51 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"



// nombre minimum de chiffres à faire apparaître lors des conversions d, i, o, u, x, et X
// nombre maximum de caractères à imprimer depuis une chaîne pour les conversions s et S
void	ft_preci_tostring(t_format *f)
{
	char	t;
	unsigned int		len;
	unsigned int		diff;

	t = f->type;
	len = ft_strlen(f->tostring);
	diff = f->preci - len;
	// mettre des 0 devant tostring
	if ((t == 'd' || t == 'i' || t == 'o' || t == 'u' || t == 'x' || t == 'X')
		&& f->preci > len)
	{
		char *m = ft_strdup("0000");
		ft_strjoinfree(m, f->tostring);
	}
	else if ((t == 's' || t == 'S') && f->preci < len)
	{
		ft_realloc((void **)&f->tostring, f->preci);
	}
}

void	ft_type_tostring(t_format *f, va_list ap)
{
	char	t;
	
	t = f->type;
	if (t == 's' || t == 'S')
		f->tostring = ft_strdup(va_arg(ap, char *));
	else if (t == 'p')
		f->tostring = ft_strdup(ft_itoa_base((int)va_arg(ap, void *), 16));
	else if (t == 'd' || t == 'D')
		f->tostring = ft_strdup(ft_itoa((int)va_arg(ap, int)));
	else if (t == 'i')
		f->tostring = ft_strdup(ft_itoa((int)va_arg(ap, int)));
	else if (t == 'o' || t == 'O')
		f->tostring = ft_strdup(ft_itoa((int)va_arg(ap, unsigned int)));
	else if (t == 'u' || t == 'U')
		f->tostring = ft_strdup(ft_itoa((int)va_arg(ap, unsigned int)));
	else if (t == 'x' || t == 'X')
		f->tostring = ft_strdup(ft_itoa((int)va_arg(ap, unsigned int)));
	else if (t == 'c' || t == 'C')
		*f->tostring = (unsigned char)va_arg(ap, int);
	if (f->tostring == NULL)
		f->tostring = ft_strdup("(null)");
}