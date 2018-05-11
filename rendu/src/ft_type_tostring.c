/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_type_tostring.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 13:28:21 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 16:23:15 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_s_tostring(t_format *f, va_list ap)
{
	wchar_t *tmp;

	if ((f->type == 's' && f->size == L) || f->type == 'S')
	{
		tmp = va_arg(ap, wchar_t *);
		if (ft_convert_wstr_to_str(&f->tostring, tmp, f->preci) == -1)
			return (-1);
		f->arg = ft_strdup(f->tostring);
	}
	else
	{
		f->arg = ft_strdup(va_arg(ap, char *));
		f->tostring = ft_strdup(f->arg);
	}
	if (!f->arg)
	{
		f->tostring = ft_strdup("(null)");
		return (1);
	}
	return (1);
}

int	ft_type_c_tostring(t_format *f, va_list ap)
{
	wchar_t tmp[2];

	if ((f->type == 'c' && f->size == L) || f->type == 'C')
	{
		tmp[0] = va_arg(ap, wchar_t);
		tmp[1] = 0;
		if (ft_convert_wstr_to_str(&f->tostring, (wchar_t *)tmp, f->preci) == -1)
			return (-1);
	}
	else
	{
		f->tostring = ft_strnew(sizeof(char));
		*f->tostring = (char)va_arg(ap, int);
	}
	f->arg = f->tostring[0] ? ft_strdup(f->tostring) : NULL;
	return (1);
}

void	ft_type_p_tostring(t_format *f, va_list ap)
{
	if (!(f->tostring = ft_ptoa(va_arg(ap, void *))))
		f->tostring = ft_strdup("0");
	f->arg = ft_strdup(f->tostring);
	f->flags[3] = '#';
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
	f->tostring = ft_intmax_itoa_type(arg, f->type);
	f->arg = ft_strdup(f->tostring);
}

void	ft_type_uox_tostring(t_format *f, va_list ap)
{
	int			t;
	uintmax_t	arg;

	t = (f->type == 'u' || f->type == 'o' || f->type == 'x' || f->type == 'X');
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
	f->tostring = ft_uintmax_itoa_type(arg, f->type);
	f->arg = ft_strdup(f->tostring);
}

void	ft_type_exceptions(t_format *f)
{
	int	t;
	int	c;
	
	t = f->type;
	c = (t == 'd' || t == 'D' || t == 'o' || t == 'O' || t == 'u' || t == 'U' || t == 'x' || t == 'X' || t == 'i');
	if (ft_strcmp("0", f->tostring) == 0 && f->preci == 0 && c)
		ft_strrealloc(&f->tostring, 0);
	c = (t == 'd' || t == 'D' || t == 'u' || t == 'U' || t == 'x' || t == 'X' || t == 'i');
	if (ft_strcmp("0X", f->tostring) == 0 && f->preci == 0 && c)
		ft_strrealloc(&f->tostring, 0);
}

int		ft_type_tostring(t_format *f, va_list ap)
{
	char	t;

	if ((t = f->type))
	{
		if (t == 'p')
			ft_type_p_tostring(f, ap);
		else if (t == 'd' || t == 'D' || t == 'i')
			ft_type_di_tostring(f, ap);
		else if (t == 'o' || t == 'O' || t == 'u' || t == 'U' || t == 'x' || t == 'X')
			ft_type_uox_tostring(f, ap);
		else if (t == 'c' || t == 'C')
		{
			if (ft_type_c_tostring(f, ap) == -1)
				return (-1);
		}
		else if (t == '%')
			f->tostring = ft_strdup("%");
		else
		{
			if (ft_type_s_tostring(f, ap) == -1)
				return (-1);
		}
		ft_type_exceptions(f);
	}
	return (1);
}