/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ptoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 14:21:32 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 14:50:21 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen(long int x, int base)
{
	int len;

	len = 1;
	while (x /= base)
		len++;
	return (len);
}

static char	ft_base_tochar(long int toprint, int base)
{
	if (base > 10 && toprint >= 10)
		return ('A' + toprint - 10);
	return ('0' + toprint);
}

char		*ft_ptoa_base(long int n, int base)
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

char	*ft_ptoa(void *p)
{
	char		*a;
	
	a = NULL;
	if (p)
	{
		a = ft_ptoa_base((long int)p, 16);
	}
	return (a);
}