/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tostring.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 15:16:17 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/10 11:41:04 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

// nombre minimum de chiffres à faire apparaître lors des conversions d, i, o, u, x, et X
// nombre maximum de caractères à imprimer depuis une chaîne pour les conversions s et S
void	ft_preci_tostring(t_format *f)
{
	wchar_t	*tmp;
	int		tmp_len;

	if (f->preci != -1)
	{
		tmp_len = f->preci - f->len;
		// preci < len donc on veut raccourcir tostring
		if ((f->type == 's' || f->type == 'S') && f->preci < f->len)
		{
			f->tostring = (wchar_t *)ft_strrealloc((char **)&f->tostring, f->preci);
			f->len = f->preci;
		}
		// preci > len donc on veut ralonger tostring
		else if (!(f->type == 's' || f->type == 'S') && f->preci > f->len)
		{
			tmp = ft_strgen('0', tmp_len);
			f->tostring = (wchar_t *)ft_strjoinfree( (char *)tmp, (char *)f->tostring);
			f->len += tmp_len;
		}
	}
	else if (f->preci == -1)
		f->tostring = (wchar_t *)ft_strrealloc((char **)&f->tostring, 0);
}
 
void	ft_type_tostring(t_format *f, va_list ap)
{
	char	t;
	
	t = f->type;
	if (t == 's' || t == 'S')
		f->tostring = (wchar_t *)ft_strdup(va_arg(ap, char *));
	else if (t == 'p')
	{
		f->tostring = (wchar_t *)ft_ptoa(va_arg(ap, void *));
		wchar_t *tmp = (wchar_t *)ft_strdup("0x");
		f->tostring = (wchar_t *)ft_strjoinfree((char *)tmp, (char *)f->tostring);
	}
	else if (t == 'd' || t == 'D' || t == 'i')
		f->tostring = (wchar_t *)(ft_itoa(va_arg(ap, int)));
	else if (t == 'o' || t == 'O')
		f->tostring = (wchar_t *)(ft_u_itoa_base(va_arg(ap, unsigned int), 8));
	else if (t == 'u' || t == 'U')
		f->tostring = (wchar_t *)(ft_u_itoa_base(va_arg(ap, unsigned int), 10));
	else if (t == 'x' || t == 'X')
		f->tostring = (wchar_t *)(ft_u_itoa_base(va_arg(ap, unsigned int), 16));
	else if (t == 'c' || t == 'C')
	{
		f->tostring = (wchar_t *)ft_strnew(sizeof(wchar_t));
		f->tostring[0] = va_arg(ap, int);
	}
	if (t == 'x' || t == 'p')
		f->tostring = (wchar_t *)ft_strtolower((char *)f->tostring);
	if (f->tostring == NULL)
		f->tostring = (wchar_t *)ft_strdup("(null)");
	ft_set_len(f);
}

// ajoute des espaces a gauche ou a droite du tostring
void	ft_width_tostring(t_format *f)
{
	wchar_t	*tmp;
	int		tmp_len;
	
	tmp = NULL;
	tmp_len = f->width - f->len;
	if (tmp_len > 0)
	{
		tmp = ft_strgen(' ', tmp_len);
		if (f->flags[1] == '-')
			f->tostring = (wchar_t *)ft_strjoinfree((char *)f->tostring, (char *)tmp);
		else
			f->tostring = (wchar_t *)ft_strjoinfree((char *)tmp, (char *)f->tostring);
		f->len += tmp_len;
	}
}

void	ft_flags_tostring(t_format *f)
{
	(void)f;
}