/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_unicode.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/28 13:28:14 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/28 13:28:44 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

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