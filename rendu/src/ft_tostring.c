/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tostring.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 15:16:17 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/27 17:35:19 by fablin      ###    #+. /#+    ###.fr     */
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
	if (f->tostring && *f->tostring && f->flags[3] == '#' && (f->type == 'x' || f->type == 'X'))
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
		else if (ft_strcmp(f->tostring, "0"))
			f->tostring = ft_strjoinfree(ft_strdup("0X"), f->tostring);
	}
	else if (f->tostring && f->flags[3] == '#' && f->type == 'o' && *f->tostring != '0')
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

void	ft_flag_space_tostring(t_format *f)
{
	if (!ft_strchr(f->arg, '-') && (f->type == 'd' || f->type == 'D' || f->type == 'i') && f->flags[4] == ' ' && f->tostring[0] != ' ')
	{
		f->tostring = ft_strjoinfree(ft_strdup(" "), f->tostring);
	}
}

void	ft_flag_zero_tostring(t_format *f)
{
	char	*tmp;
	int		tmp_len;

	tmp_len = f->width - ft_strlen(f->tostring);
	if (f->flags[4] == ' ')
		tmp_len -= 1;
	if (f->flags[3] == '#')
		tmp_len -= 4;
	if (f->preci >= 0)
		tmp_len -= f->preci;
	if (f->flags[2] == '0' && tmp_len > 0)
	{
		if (f->type == 'd' || f->type == 'D' || f->type == 'i' || f->type == 'o'
			|| f->type == 'O' || f->type == 'u' || f->type == 'U' ||
			f->type == 'x' || f->type == 'X')
		{
			tmp = ft_strgen('0', tmp_len);
			f->tostring = ft_strjoinfree(tmp, f->tostring);
		}
	}
}

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

void	ft_flags_tostring(t_format *f)
{
	ft_flag_plus_tostring(f);
	ft_flag_zero_tostring(f);
	ft_flag_hashtag_tostring(f);
	ft_flag_space_tostring(f);
}

int		ft_wstr_unilen(wchar_t *src)
{
	int		len;
	int		i;

	if (!src)
		return (0);
	len = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] >= 0xD800 && src[i] <= 0xDFFF)
			return (-1);
		if (src[i] <= 0x7F && MB_CUR_MAX >= 1)
			len += 1;
		else if (src[i] <= 0x7FF && MB_CUR_MAX >= 2)
			len += 2;
		else if (src[i] <= 0xFFFF && MB_CUR_MAX >= 3)
			len += 3;
		else if (src[i] <= 0x10FFFF && MB_CUR_MAX >= 4)
			len += 4;
		else
			return (-1);
		i++;
	}
	return (len);
}

int		ft_wstr_unicpy(char *dst, wchar_t *src, int len)
{
	int		i;
	int		j;

	if (!src)
		return (0);
	i = 0;
	j = 0;
	while(src[i] && j < len)
	{
		if (src[i] <= 0x7F && MB_CUR_MAX >= 1)
			dst[j++] = src[i];
		else if (src[i] <= 0x7FF && MB_CUR_MAX >= 2)
		{
			dst[j++] = (src[i] >> 6) + 0xC0;
			dst[j++] = (src[i] & 0x3F) + 0x80;
		}
		else if (src[i] <= 0xFFFF && MB_CUR_MAX >= 3)
		{
			dst[j++] = (src[i] >> 12) + 0xE0;
			dst[j++] = ((src[i] >> 6) & 0x3F) + 0x80;
			dst[j++] = (src[i] & 0x3F) + 0x80;
		}
		else if (src[i] <= 0x10FFFF && MB_CUR_MAX >= 4)
		{
			dst[j++] = (src[i] >> 18) + 0xF0;
			dst[j++] = ((src[i] >> 12) & 0x3F) + 0x80;
			dst[j++] = ((src[i] >> 6) & 0x3F) + 0x80;
			dst[j++] = (src[i] & 0x3F) + 0x80;
		}
		else
			return (0);
		i++;
	}
	return (j <= i ? j : i);
}

int		ft_convert_wstr_to_str(char **dst, wchar_t *wstr)
{
	int		new_len;

	if (!wstr)
		return (0);
	if ((new_len = ft_wstr_unilen(wstr)) == -1)
		return (-1);
	if ((*dst = ft_strnew(new_len)))
		ft_wstr_unicpy(*dst, wstr, new_len);
	return (new_len);
}

int		ft_type_s_tostring(t_format *f, va_list ap)
{
	wchar_t *tmp;

	if ((f->type == 's' && f->size == L) || f->type == 'S')
	{
		tmp = va_arg(ap, wchar_t *);
		if (ft_convert_wstr_to_str(&f->tostring, tmp) == -1)
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
		if (ft_convert_wstr_to_str(&f->tostring, (wchar_t *)tmp) == -1)
			return (-1);
	}
	else
	{
		f->tostring = ft_strnew(sizeof(int));
		*(int *)f->tostring = va_arg(ap, int);
	}
	f->arg = f->tostring[0] ? ft_strdup(f->tostring) : NULL;
	return (1);
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

