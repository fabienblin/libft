/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strgen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fablin <fablin@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 16:28:10 by fablin       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/07 16:44:28 by fablin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_strgen(int c, int len)
{
	wchar_t	*gen;
	
	if (!(gen = (wchar_t *)ft_strnew(len)))
		return (NULL);
	gen = ft_memset(gen, c, len);
	return (gen);
}