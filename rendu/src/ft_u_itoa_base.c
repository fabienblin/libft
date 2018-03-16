/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_u_itoa_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 13:45:08 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 14:50:02 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(unsigned int x, int base)
{
	int len;

	len = 1;
	while (x /= base)
		len++;
	return (len);
}

static char	ft_base_tochar(int toprint, int base)
{
	if (base > 10 && toprint >= 10)
		return ('A' + toprint - 10);
	return ('0' + toprint);
}

char		*ft_u_itoa_base(unsigned int n, int base)
{
	char			*ret;
	int				ret_size;

	ret_size = ft_intlen(n, base);
	if (!(ret = ft_strnew(ret_size)))
		return (NULL);
	while (ret_size > 0)
	{
		ret[--ret_size] = ft_base_tochar(n % base, base);
		n /= base;
	}
	return (ret);
}
