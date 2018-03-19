/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tostring.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 15:16:17 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/19 17:46:51 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_preci_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;

	if (f->preci != -1)
	{
		tmp_len = f->preci - f->len;
		if ((f->type == 's' || f->type == 'S') && f->preci < f->len)
		{
			f->tostring = ft_strrealloc(&f->tostring, f->preci);
			f->len = f->preci;
		}
		else if (!(f->type == 's' || f->type == 'S') && f->preci > f->len)
		{
			tmp = ft_strgen('0', tmp_len);
			f->tostring = ft_strjoinfree(tmp, (char *)f->tostring);
			f->len += tmp_len;
		}
	}
}

void	ft_width_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;
	
	tmp = NULL;
	tmp_len = f->width - f->len;
	if (tmp_len > 0)
	{
		tmp = f->flags[2] == '0' ? ft_strgen('0', tmp_len) : ft_strgen(' ', tmp_len);
		if (f->flags[1] == '-')
			f->tostring = ft_strjoinfree((char *)f->tostring, tmp);
		else if (f->flags[0] == '+')
		{
			tmp[tmp_len - 1] = '+';
			f->tostring = ft_strjoinfree(tmp, (char *)f->tostring);
		}
		else
			f->tostring = ft_strjoinfree(tmp, (char *)f->tostring);
		f->len += tmp_len;
	}
}

void	ft_flags_tostring(t_format *f)
{
	
	if (f->flags[0] == '+')
	{;}
	else if (f->flags[1] == '-')
	{;}
	else if (f->flags[2] == '0')
	{;}
	else if (f->flags[3] == '#')
	{
		if (f->type == 'o' && *f->tostring != '0')
			f->tostring = ft_strjoinfree(ft_strdup("0"), f->tostring);
		else if (f->type == 'x')
			f->tostring = ft_strjoinfree(ft_strdup("0x"), f->tostring);
		else if (f->type == 'X')
			f->tostring = ft_strjoinfree(ft_strdup("0X"), f->tostring);
	}
	else if (f->flags[4] == ' ')
	{;}
	(void)f;
}

void	ft_type_s_tostring(t_format *f, va_list ap)
{
	if ((f->type == 's' && f->size == L) || f->type == 'S')
	{
		f->tostring = (void *)ft_strdup((char *)va_arg(ap, wchar_t *));
	}
	else
	{
		f->tostring = (void *)ft_strdup(va_arg(ap, char *));
	}
}

void	ft_type_c_tostring(t_format *f, va_list ap)
{
	if ((f->type == 'c' && f->size == L) || f->type == 'C')
	{
		f->tostring = (void *)ft_strnew(sizeof(wchar_t));
		*(wchar_t *)f->tostring = va_arg(ap, wchar_t);
	}
	else
	{
		f->tostring = (void *)ft_strnew(sizeof(int));
		*(int *)f->tostring = va_arg(ap, int);
	}
}

void	ft_type_p_tostring(t_format *f, va_list ap)
{
	f->tostring = ft_ptoa(va_arg(ap, void *));
	f->tostring = (void *)ft_strjoinfree(ft_strdup("0x"), (char *)f->tostring);
}

void	ft_type_di_tostring(t_format *f, va_list ap)
{
	int			t;
	intmax_t	arg;
	
	t = (f->type == 'd' || f->type == 'i');
	arg = va_arg(ap, intmax_t);
	if ((t && f->size == L) || f->type == 'D')
		arg = (long int)arg;
	else if (t && f->size == LL)
		arg = (long long int)arg;
	else if (t && f->size == H)
		arg = (short int)arg;
	else if (t && f->size == HH)
		arg = (signed char)arg;
	else if (t && f->size == J)
		arg = (intmax_t)arg;
	else if (t && f->size == Z)
		arg = (size_t)arg;
	else
		arg = (int)arg;
	f->tostring = (void *)ft_intmax_itoa_type(arg, f->type);
}

void	ft_type_uox_tostring(t_format *f, va_list ap)
{
	int			t;
	uintmax_t	arg;

	t = (f->type == 'u' || f->type == 'o' || f->type == 'x' ||	f->type == 'X');
	arg = va_arg(ap, uintmax_t);
	if ((t && f->size == L) || f->type == 'U' || f->type == 'O')
		arg = (unsigned long int)arg;
	else if (t && f->size == LL)
		arg = (unsigned long long int)arg;
	else if (t && f->size == H)
		arg = (unsigned short int)arg;
	else if (t && f->size == HH)
		arg = (unsigned char)arg;
	else if (t && f->size == J)
		arg = (uintmax_t)arg;
	else if (t && f->size == Z)
		arg = (size_t)arg;
	else
		arg = (unsigned int)arg;
	f->tostring = (void *)ft_uintmax_itoa_type(arg, f->type);
}

void	ft_type_tostring(t_format *f, va_list ap)
{
	char	t;
	
	t = f->type;
	if (t == 's' || t == 'S')
		ft_type_s_tostring(f, ap);
	else if (t == 'p')
		ft_type_p_tostring(f, ap);
	else if (t == 'd' || t == 'D' || t == 'i')
		ft_type_di_tostring(f, ap);
	else if (t == 'o' || t == 'O' || t == 'u' || t == 'U' || t == 'x' || t == 'X')
		ft_type_uox_tostring(f, ap);
	else if (t == 'c' || t == 'C')
		ft_type_c_tostring(f, ap);
	else if (t == '%')
		f->tostring = (void *)ft_strdup("%");
	if (t == 'x' || t == 'p')
		f->tostring = (void *)ft_strtolower((char *)f->tostring);
	if (f->tostring == NULL)
		f->tostring = (void *)ft_strdup("(null)");
	ft_set_len(f);
}
