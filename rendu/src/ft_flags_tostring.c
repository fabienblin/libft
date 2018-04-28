/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_flags_tostring.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 15:11:58 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 15:12:43 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_flags_tostring(t_format *f)
{
	ft_flag_plus_tostring(f);
	ft_flag_zero_tostring(f);
	ft_flag_hashtag_tostring(f);
	ft_flag_space_tostring(f);
}