/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tostring.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 15:16:17 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/21 17:47:26 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_preci_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;

	if (f->preci > 0 && (f->type != 'c' && f->type != 'C'))
	{
		tmp_len = f->preci - ft_strlen(f->tostring);
		if ((f->type == 's' || f->type == 'S') && f->preci < (int)ft_strlen(f->tostring))
		{
			f->tostring = ft_strrealloc(&f->tostring, f->preci);
		}
		else if (!(f->type == 's' || f->type == 'S') && f->preci >= (int)ft_strlen(f->tostring))
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

void	ft_flag_hashtag_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;

	tmp = NULL;
	tmp_len = f->width - ft_strlen(f->tostring);
	if (*f->tostring && f->flags[3] == '#' && (f->type == 'x' || f->type == 'X') && *f->tostring != '0')
	{
		if (tmp_len > 0 && f->flags[2] == '0')
		{
			char *tmp = ft_strgen('0', tmp_len);
			tmp[1] = 'X';
			f->tostring = ft_strjoinfree(tmp, f->tostring);
		}
		else if (tmp_len > 2 && f->flags[1] == '-')
		{
			tmp_len -= 2;
			char *tmp = ft_strgen(' ', tmp_len);
			f->tostring = ft_strjoinfree(ft_strdup("0X"), f->tostring);
			f->tostring = ft_strjoinfree(f->tostring, tmp);
		}
		else
			f->tostring = ft_strjoinfree(ft_strdup("0X"), f->tostring);
	}
	else if (f->flags[3] == '#' && f->type == 'o' && *f->tostring != '0')
	{
		f->tostring = ft_strjoinfree(ft_strdup("0"), f->tostring);
	}
	if (f->type == 'x' || f->type == 'p')
		f->tostring = ft_strtolower(f->tostring);
}

void	ft_flag_plus_tostring(t_format *f)
{
	if (!ft_strchr(f->tostring, '-') && (f->type == 'd' || f->type == 'D' || f->type == 'i') && f->flags[0] == '+')
	{
		f->tostring = ft_strjoinfree(ft_strdup("+"), f->tostring);
	}
}

void ft_flag_space_tostring(t_format *f)
{
	if (!ft_strchr(f->arg, '-') && (f->type == 'd' || f->type == 'D' || f->type == 'i') && f->flags[4] == ' ' && f->tostring[0] != ' ')
	{
		f->tostring = ft_strjoinfree(ft_strdup(" "), f->tostring);
	}
}

void	ft_width_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;
	
	tmp = NULL;
	ft_flag_plus_tostring(f);
	ft_flag_hashtag_tostring(f);
	ft_flag_space_tostring(f);
	
	tmp_len = f->width - ft_strlen(f->tostring);
	if ((f->type == 'c' || f->type == 'C') && f->arg == NULL)
		tmp_len--;
	if (tmp_len > 0 && f->preci <= 0)
	{
		tmp = f->flags[2] == '0' ? ft_strgen('0', tmp_len) : ft_strgen(' ', tmp_len);
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
		if (f->type == 'o' && *f->tostring != '0'  && f->width == -1)
			f->tostring = ft_strjoinfree(ft_strdup("0"), f->tostring);
		else if ((f->type == 'x' || f->type == 'X'))
		{
			ft_flag_hashtag_tostring(f);
		}
	}
	else if (f->flags[4] == ' ')
	{;}
	(void)f;
}

char	*ft_convert_wstr_to_str(wchar_t *str)
{
	char	*new;
	int		new_len;
	int		i;

	new_len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			new_len += 1;
		else if (str[i] <= 0x7FF)
			new_len += 2;
		else if (str[i] <= 0xFFFF)
			new_len += 3;
		else if (str[i] <= 0x10FFFF)
			new_len += 4;
		i++;
	}
	
	new = ft_strnew(new_len);
	
	i = 0;
	while(str[i])
	{
		if (str[i] <= 0x7F)
		{
			new[i] = str[i];
		}
	    else if (str[i] <= 0x7FF)
	    {
			new[i] = (str[i] >> 6) + 0xC0;
			new[i + 1] = (str[i] & 0x3F) + 0x80;
	    }
	    else if (str[i] <= 0xFFFF)
	    {
			new[i] = (str[i] >> 12) + 0xE0;
			new[i + 1] = ((str[i] >> 6) & 0x3F) + 0x80;
			new[i + 2] = (str[i] & 0x3F) + 0x80;
	    }
	    else if (str[i] <= 0x10FFFF)
	    {
			new[i] = (str[i] >> 18) + 0xF0;
			new[i + 1] = ((str[i] >> 12) & 0x3F) + 0x80;
			new[i + 2] = ((str[i] >> 6) & 0x3F) + 0x80;
			new[i + 3] = (str[i] & 0x3F) + 0x80;
	    }
		i++;
	}
	return (new);
}

void	ft_type_s_tostring(t_format *f, va_list ap)
{
	wchar_t *tmp;
	
	if ((f->type == 's' && f->size == L) || f->type == 'S')
	{
		tmp = va_arg(ap, wchar_t *);
		f->tostring = ft_convert_wstr_to_str(tmp);
		f->arg = ft_strdup(f->tostring);
	}
	else
	{
		f->arg = ft_strdup(va_arg(ap, char *));
		f->tostring = ft_strdup(f->arg);
	}
	if (!f->arg)
		f->tostring = ft_strdup("(null)");
}

void	ft_type_c_tostring(t_format *f, va_list ap)
{
	wchar_t tmp[2];

	if ((f->type == 'c' && f->size == L) || f->type == 'C')
	{
		tmp[0] = va_arg(ap, wchar_t);
		tmp[1] = 0;
		f->tostring = ft_convert_wstr_to_str((wchar_t *)tmp);
	}
	else
	{
		f->tostring = ft_strnew(sizeof(int));
		*(int *)f->tostring = va_arg(ap, int);
	}
	f->arg = f->tostring[0] ? ft_strdup(f->tostring) : NULL;
}

void	ft_type_p_tostring(t_format *f, va_list ap)
{
	if (!(f->tostring = ft_ptoa(va_arg(ap, void *))))
		f->tostring = ft_strdup("0");
	f->arg = ft_strdup(f->tostring);
	f->tostring = ft_strjoinfree(ft_strdup("0X"), f->tostring);
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

void	ft_type_tostring(t_format *f, va_list ap)
{
	char	t;

	if ((t = f->type))
	{
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
			f->tostring = ft_strdup("%");
		ft_type_exceptions(f);
	}
}

