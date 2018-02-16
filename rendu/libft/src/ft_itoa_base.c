/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 16:52:26 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 14:14:01 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	ft_base_tochar(int toprint, int base)
{
	if (base > 10 && toprint >= 10)
		return ('A' + toprint - 10);
	return ('0' + toprint);
}

static int	ft_intlen(unsigned int x, int base)
{
	int len;

	len = 1;
	while (x /= base)
		len++;
	return (len);
}

char		*ft_itoa_base(int n, int base)
{
	char			*ret;
	int				neg;
	int				intlen;
	unsigned int	n_long;

	ret = NULL;
	if (base >= 2)
	{
		n_long = (long int)n;
		neg = n < 0;
		if (neg)
			n_long = -n;
		intlen = ft_intlen(n_long, base);
		if (!(ret = ft_strnew(intlen + neg)))
			return (NULL);
		ret[0] = '-';
		while (intlen > 0)
		{
			ret[intlen--] = ft_base_tochar(n_long % base, base);
			n_long /= base;
		}
		if (!neg)
			ret++;
	}
	return (ret);
}
